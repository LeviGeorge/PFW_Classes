#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arg1;
    long arg2;
    
    if (argc != 3) {
        printf("USAGE: %s int_num long_num\n", argv[0]);
        return -1;
    }
    
    arg1 = atoi(argv[1]);
    arg2 = atol(argv[2]);
    
    printf("Program %s: int_num = %d, long_num = %ld\n", argv[0], arg1, arg2);
    
    return 0;
}