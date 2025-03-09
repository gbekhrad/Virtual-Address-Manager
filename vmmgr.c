#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int page_size = 256;          // size of each page (2^8 bytes)
int page_table_size = 256;    // number of pages in virtual address space
int frame_size = 256;         // size of each frame
int physical_size = 65536;    // total physical memory size (256 frames × 256 bytes)
int TLB_size = 16;           // number of TLB entries

// TLB entry structure
typedef struct {
    int frame_num; // physical frame number
    int page_num; // virtual page number
    int valid; // valid bit (1 = valid, 0 = invalid)
    int last_used; // timestamp for LRU replacement
} TLBEntry;

TLBEntry TLB[16]; // translation lookaside buffer
int page_table[256]; // page table
char physical_memory[65536]; // physical memory -- signed?
FILE* backing_store; // backing store file pointer

int page_faults = 0; // counter for page faults
int TLB_hits = 0; // counter for TLB hits
int time_counter = 0; // global time for LRU implementation

int get_pAddress(int logical_address); // fx prototype

int main(int argc, char *argv[]) {
    // error handle 
    if (argc != 2) {
        fprintf(stderr, "Invalid number of command-line arguments.\n");
        return -1;
    }

    // begin initialization
    // initialize TLB entries as invalid
    for (int i = 0; i < TLB_size; i++) {
        TLB[i].valid = 0;
        TLB[i].last_used = 0;
    }
    
    // initialize page table entries as not in memory
    for (int i = 0; i < page_table_size; i++) {
        page_table[i] = -1;
    }
    
    // open backing store file
    backing_store = fopen("BACKING_STORE.bin", "rb"); // read only binary mode 
    if (backing_store == NULL) {
        fprintf(stderr, "Error: cannot open backing_store.bin.\n");
        exit(1);
    }
    // end initialization 


    // open input file
    // read a file containing several 32-bit integer numbers that represent logical addresses (imp stdio.h)
    FILE *input_file = fopen(argv[1], "r"); // r indicates read-only
    if (!input_file) {
        fprintf(stderr, "Error: Cannot open input file.\n");
        return -1;
    }

    // initialize addresses to be stored and updated 
    int logical_address = 0;
    int translated_addresses = 0;


    // BEGIN CHECKING
    while (fscanf(input_file, "%d", &logical_address) == 1) {  // Read as decimal
        // Extract page number and offset from 32-bit address
        int offset = logical_address & 0xFF;          // bits 0-7
        int page_num = (logical_address >> 8) & 0xFF; // bits 8-15
        
        // get physical address and value stored there
        int physical_address = get_pAddress(logical_address);
        signed char value = physical_memory[physical_address];

        // Format string for virtual address
        printf("Virtual Address: %5d ", logical_address);  // align right
        printf("-- Physical Address: %5d ", physical_address);  // no leading zeros
        printf("-- Value: %4d\n", value);
        
        translated_addresses++;
    }

    // After completion, your program is to report (output as well) the following statistics:
    printf("\nStatistics:\n");
    printf("Page Fault Rate = %.2f%%\n", 
           (float)page_faults/translated_addresses * 100); // rounding 2 decimal places
    printf("TLB Hit Rate = %.2f%%\n", 
           (float)TLB_hits/translated_addresses * 100);

    // cleanup
    fclose(backing_store);
    fclose(input_file);
    
    return 0;
}


// searc h the TLB for a page number (given as param)
int search_TLB(int page_num) {
    for (int i = 0; i < TLB_size; i++) {
        if (TLB[i].valid && TLB[i].page_num == page_num) {
            // TLB hit - update access time and return frame
            TLB[i].last_used = time_counter++;
            TLB_hits++;
            return TLB[i].page_num;
        }
    }
    return -1;  // TLB miss
}

// LRU algorithm to find TLB entry for replacement
int LRU_entry() {
    int LRU_index = 0;
    int min_time = TLB[0].last_used;
    
    for (int i = 1; i < TLB_size; i++) {
        // first check for any invalid (unused) entries
        if (!TLB[i].valid) {
            return i;
        }
        // otherwise, find entry with smallest last_used time
        if (TLB[i].last_used < min_time) {
            min_time = TLB[i].last_used;
            LRU_index = i;
        }
    }
    return LRU_index;
}

void updateTLB(int pageNum, int frameNum) {
    int index = LRU_entry();
    TLB[index].page_num = pageNum;
    TLB[index].frame_num = frameNum;
    TLB[index].valid = 1;
    TLB[index].last_used = time_counter++;
}

// handles page faults (with backing store)
int handle_page_fault(int page_number) {
    page_faults++;
    
    // calculate position in backing store
    long offset = page_number * page_size;
    
    // seek to correct position in backing_store.bin
    if (fseek(backing_store, offset, SEEK_SET) != 0) {
        fprintf(stderr, "Error: Backing store..\n");
        exit(1);
    }
    
    // find next available frame (using page_faults as frame counter)
    int frame_number = page_faults - 1;
    if (frame_number >= page_table_size) {
        fprintf(stderr, "Error: Out of memory.\n");
        exit(1);
    }
    
    // read page from backing store into physical memory
    if (fread(&physical_memory[frame_number * frame_size], 
              sizeof(signed char), page_size, backing_store) != page_size) {
        fprintf(stderr, "Error: Failed to read from backing store.\n");
        exit(1);
    }
    
    // update page table
    page_table[page_number] = frame_number;
    
    return frame_number;
}

// translates logical address to physical address
int get_pAddress(int logical_address) {
    int page_num = (logical_address & 0xFF00) >> 8;
    int offset = logical_address & 0xFF;
    int frameNum;
    
    // first check TLB
    frameNum = search_TLB(page_num);
    
    if (frameNum == -1) {
        // TLB miss - check page table
        frameNum = page_table[page_num];
        
        if (frameNum == -1) {
            // page fault - load from backing store
            frameNum = handle_page_fault(page_num);
        }
        
        // update TLB with new mapping
        updateTLB(page_num, frameNum);
    }
    
    // calculate and return the physical address
    return (frameNum * frame_size) + offset;
}

