# packer
C functions for pack and unpack data from 32/64 bit to a size which fit the set of data.

## How to use
```c
#include "packer.h"

uint vals[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
byte *buffer = pack(vals, 16, 4);
uint *res = unpack(buffer, 16, 4);
```
