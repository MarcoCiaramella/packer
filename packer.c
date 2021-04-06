#include "packer.h"
#include <stdio.h>


byte *alloc_buffer(uint num_vals, byte num_bits){
    uint size = ceil(num_bits/8.0 * num_vals) + UINT_SIZE - ceil(num_bits/8.0);
    byte *buffer = (byte *) malloc(size);
    memset(buffer, 0, size);
    return buffer;
}

uint *to_uint(byte *buffer, uint byte_index){
    return (uint *)&(buffer[byte_index]);
}

byte *pack(uint *vals, uint size, byte num_bits){
    byte *buffer = alloc_buffer(size, num_bits);
    int i;
    for (i = 0; i < size; i++){
        uint val = vals[i] << (UINT_SIZE - num_bits);
        uint byte_index = (i * num_bits) / 8;
        byte byte_offset = (i * num_bits) % 8;
        *to_uint(buffer, byte_index) |= val >> byte_offset;
    }
    return buffer;
}

uint *unpack(byte *buffer, uint size, byte num_bits){
    uint *vals = (uint *) malloc(UINT_SIZE/8 * size);
    int i;
    for (i = 0; i < size; i++){
        uint byte_index = (i * num_bits) / 8;
        byte byte_offset = (i * num_bits) % 8;
        uint a = *to_uint(buffer, byte_index);
        a <<= byte_offset;
        a >>= UINT_SIZE - num_bits;
        vals[i] = a;
    }
    return vals;
}

void test_pack_unpack(){
    uint vals[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    byte *buffer = pack(vals, 16, 4);
    uint *res = unpack(buffer, 16, 4);
    int i;
    for (i = 0; i < 16; i++){
        printf("%d\n", res[i]);
    }
}

void packer_test(){
    test_pack_unpack();
}