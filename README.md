# packer
C functions for pack and unpack data from 16/32 bit to a size which fit the set of data.

## How to use
```c
#include "packer.h"

// data to pack
uint vals[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
// 4 bits fits our set of 16 values
byte size = 4;
// pack array vals
byte *buffer = pack(vals, 16, size);
// unpack buffer
uint *res = unpack(buffer, 16, size);
```

## How it works
Following the code above we have an array of values of this type 0x0000000X (32-bit unsigned integer). Only last 4 bits are used to store the value. So we can remove all unused zeroes ahead obteining an array of values 0xX reducing the space required for storing this set of data. This is what the `pack` function does. `unpack` reverts this process by adding zeroes ahead to values in the input buffer.
