/*
Author: Arjun Makwana
Date: November 2021
*/

/*
                        Program Description

        The function to_code_len() takes an unsigned integer
        of 16 bits and packs it as consecutive 13 bits.

        This kind of packing is useful in compression algorithms.
        This particular algorithm was written for LZW lossless 
        compression algorithm. 

        The result of packing 16 bits into 13 bits is stored in 
        an output buffer. Though this buffer is defined as unsigned
        char, the data stored in there actually represents a number
        between 0 to 2^(CODE_LENGTH). 

        This function works for a CODE_LENGTH anywhere between 9 and 15.

*/

#include <iostream>
#include <stdlib.h>
#include <stdint.h>

#define CODE_LENGTH 13

uint16_t written = 0;
uint16_t to_be_written; // = CODE_LENGTH;
uint16_t capacity = 8;
uint16_t idx = 0;


void to_code_len(uint16_t num, unsigned char* op) {
    
    to_be_written = CODE_LENGTH;
    unsigned char temp;

    while (to_be_written != 0) {
        
        if (to_be_written >= 8) {
            
            temp = num >> (to_be_written - capacity);
            op[idx] |= temp;

            written = capacity;
            to_be_written = to_be_written - written;
            capacity = capacity - written;

            if (capacity <= 0) { idx++; capacity = 8; }

        }

        if (to_be_written < 8) {

            temp = num << (8 - to_be_written);
            op[idx] |= temp;

            written = to_be_written;
            capacity = 8 - written;
            to_be_written = 0;
            
            if (capacity <= 0) { idx++; capacity = 8; }

        }

    }

}


int main()
{
    uint16_t data[] = { 257, 300, 125, 400 };
    int data_elements = sizeof(data) / sizeof(uint16_t);

    uint32_t size_required;

    if (CODE_LENGTH * data_elements % 8 == 0) {
        size_required = CODE_LENGTH * data_elements / 8;
    }
    else {
        size_required = (CODE_LENGTH * data_elements / 8) + 1;
    }

    unsigned char* op = (unsigned char*)calloc((size_required), sizeof(uint16_t));

    //unsigned char op[7] = {0};

    printf("size req = %d\n\n", size_required);

    //printf("%X\n\n", data[0]);

    for (int i = 0; i < data_elements; i++) {
        to_code_len(data[i], op);
    }

    for (int i = 0; i < size_required; i++) {
        printf("%X\n",op[i]);
    }
}

