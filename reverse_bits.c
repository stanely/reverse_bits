#include <stdio.h>
#include <stdlib.h>

void print_bit(unsigned char in)
{
    unsigned char num = 7;
    unsigned char v = 0;

    do{
        if((in & 0x01) == 1)
            v = 1;
        else
            v = 0;

        in >>= 1;
        printf("%d ", v);
    } while(num--);
    printf("\r\n");
}

void print_bit_reserve(unsigned char in)
{
    unsigned char num = 7;
    unsigned char v = 0;
    unsigned char in_bak = 0;

    in_bak = in;
    do{
        in_bak >>= num;
/*
        if((in_bak & 0x01) == 1)
            v = 1;
        else
            v = 0;
*/
        v = (in_bak & 0x01) ? 1 : 0;
        printf("%d ", v);
        in_bak = in;
    } while(num--);
    printf("\r\n");
}

int main(int argc, char* argv[])
{
    unsigned char test_start = 0;
    unsigned char test_end = 0xFF;
    unsigned char b; // reverse this (8-bit) byte

    for(test_start = 0; test_start < test_end; ++test_start)
    {
        b = test_start; 
        printf("[%d] Original: ", test_start);
        print_bit_reserve(b);
        /* https://graphics.stanford.edu/~seander/bithacks.html#ReverseByteWith64BitsDiv */
        b = (b * 0x0202020202ULL & 0x010884422010ULL) % 1023;  /* reserve */
        printf("[%d] Reserved: ", test_start);
        print_bit_reserve(b);
    }

    return 1;
}
