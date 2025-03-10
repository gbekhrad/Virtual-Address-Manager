# Virtual Address Manager

Gabriella (Gabi) Bekhrad
gabimbek@gmail.com

## Overview/Source Files:
- vmmgr.c: C program simulating a virtual memory system with 16-bit virtual address space (65,536 bytes), 8-bit page numbers and 8-bit offsets, TLB with 16 entries using LRU replacement, 256 frames of physical memory, and demand paging from backing_store.bin.

## To compile:
gcc vmmgr.c -o vmmgr

## To run:
./vmmgr addresses.txt

## Sample Output: (Sources at end of README)
Virtual Address: 16916 -- Physical Address:    20 -- Value:    0  
Virtual Address: 62493 -- Physical Address:   285 -- Value:    0  
Virtual Address: 30198 -- Physical Address:   758 -- Value:   29  
Virtual Address: 53683 -- Physical Address:   947 -- Value:  108  
Virtual Address: 40185 -- Physical Address:  1273 -- Value:    0  
Virtual Address: 28781 -- Physical Address:  1389 -- Value:    0  
Virtual Address: 24462 -- Physical Address:  1678 -- Value:   23  
Virtual Address: 48399 -- Physical Address:  1807 -- Value:   67  
Virtual Address: 64815 -- Physical Address:  2095 -- Value:   75  
Virtual Address: 18295 -- Physical Address:  2423 -- Value:  -35  
Virtual Address: 12218 -- Physical Address:  2746 -- Value:   11  
Virtual Address: 22760 -- Physical Address:  3048 -- Value:    0  
Virtual Address: 57982 -- Physical Address:  3198 -- Value:   56  
Virtual Address: 27966 -- Physical Address:  3390 -- Value:   27  
Virtual Address: 54894 -- Physical Address:  3694 -- Value:   53  
Virtual Address: 38929 -- Physical Address:  3857 -- Value:    0  
Virtual Address: 32865 -- Physical Address:  4193 -- Value:    0  
Virtual Address: 64243 -- Physical Address:  4595 -- Value:  -68  
Virtual Address:  2315 -- Physical Address:  4619 -- Value:   66  
Virtual Address: 64454 -- Physical Address:  5062 -- Value:   62  
Virtual Address: 55041 -- Physical Address:  5121 -- Value:    0  
Virtual Address: 18633 -- Physical Address:  5577 -- Value:    0  
Virtual Address: 14557 -- Physical Address:  5853 -- Value:    0  
Virtual Address: 61006 -- Physical Address:  5966 -- Value:   59  
Virtual Address: 62615 -- Physical Address:   407 -- Value:   37  
Virtual Address:  7591 -- Physical Address:  6311 -- Value:  105  
Virtual Address: 64747 -- Physical Address:  6635 -- Value:   58  
Virtual Address:  6727 -- Physical Address:  6727 -- Value: -111  
Virtual Address: 32315 -- Physical Address:  6971 -- Value: -114  
Virtual Address: 60645 -- Physical Address:  7397 -- Value:    0  
Virtual Address:  6308 -- Physical Address:  7588 -- Value:    0  
Virtual Address: 45688 -- Physical Address:  7800 -- Value:    0  
Virtual Address:   969 -- Physical Address:  8137 -- Value:    0  
Virtual Address: 40891 -- Physical Address:  8379 -- Value:  -18  
Virtual Address: 49294 -- Physical Address:  8590 -- Value:   48  
Virtual Address: 41118 -- Physical Address:  8862 -- Value:   40  
Virtual Address: 21395 -- Physical Address:  9107 -- Value:  -28  
Virtual Address:  6091 -- Physical Address:  9419 -- Value:  -14  
Virtual Address: 32541 -- Physical Address:  9501 -- Value:    0  
Virtual Address: 17665 -- Physical Address:  9729 -- Value:    0  
Virtual Address:  3784 -- Physical Address: 10184 -- Value:    0  
Virtual Address: 28718 -- Physical Address:  1326 -- Value:   28  
Virtual Address: 59240 -- Physical Address: 10344 -- Value:    0  
Virtual Address: 40178 -- Physical Address:  1266 -- Value:   39  
Virtual Address: 60086 -- Physical Address: 10678 -- Value:   58  
Virtual Address: 42252 -- Physical Address: 10764 -- Value:    0  
Virtual Address: 44770 -- Physical Address: 11234 -- Value:   43  
Virtual Address: 22514 -- Physical Address: 11506 -- Value:   21  
Virtual Address:  3067 -- Physical Address: 11771 -- Value:   -2  
Virtual Address: 15757 -- Physical Address: 11917 -- Value:    0  
Virtual Address: 31649 -- Physical Address: 12193 -- Value:    0  
Virtual Address: 10842 -- Physical Address: 12378 -- Value:   10  
Virtual Address: 43765 -- Physical Address: 12789 -- Value:    0  
Virtual Address: 33405 -- Physical Address: 12925 -- Value:    0  
Virtual Address: 44954 -- Physical Address: 13210 -- Value:   43  
Virtual Address: 56657 -- Physical Address: 13393 -- Value:    0  
Virtual Address:  5003 -- Physical Address: 13707 -- Value:  -30  
Virtual Address: 50227 -- Physical Address: 13875 -- Value:   12  
Virtual Address: 19358 -- Physical Address: 14238 -- Value:   18  
Virtual Address: 36529 -- Physical Address: 14513 -- Value:    0  
Virtual Address: 10392 -- Physical Address: 14744 -- Value:    0  
Virtual Address: 58882 -- Physical Address: 14850 -- Value:   57  
Virtual Address:  5129 -- Physical Address: 15113 -- Value:    0  
Virtual Address: 58554 -- Physical Address: 15546 -- Value:   57  
Virtual Address: 58584 -- Physical Address: 58584 -- Value:    0  
Virtual Address: 27444 -- Physical Address: 15668 -- Value:    0  
Virtual Address: 58982 -- Physical Address: 58982 -- Value:    0  
Virtual Address: 51476 -- Physical Address: 15892 -- Value:    0  
Virtual Address:  6796 -- Physical Address:  6796 -- Value:    0  
... *until termination*

Statistics:
Page Fault Rate = 24.40%
TLB Hit Rate = 5.50%

## Sources:
https://www.geeksforgeeks.org/scanf-and-fscanf-in-c/
https://stackoverflow.com/questions/70326954/does-fopen-give-back-an-adress 
https://www.ibm.com/docs/en/i/7.3?topic=functions-fopen-open-files 
https://www.geeksforgeeks.org/reading-binary-files-in-python/
https://stackoverflow.com/questions/3427585/understanding-the-bitwise-and-operator
https://stackoverflow.com/questions/3427585/understanding-the-bitwise-and-operator
https://www.geeksforgeeks.org/paging-in-operating-system/
https://stackoverflow.com/questions/53734848/about-tlb-entries-and-page-table-entries
https://stackoverflow.com/questions/10668501/page-replacement-algorithm-lru
https://github.com/saksoo/TlbSimulation/blob/master/main.cpp 
