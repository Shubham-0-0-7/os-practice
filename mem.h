#ifndef MEM_H
#define MEM_H
#include <stdint.h>
#include <stddef.h>

void* memset(void* dest, int val, size_t count);
void* memcpy(void* dest, const void* src, size_t count);
int memcmp(const void* s1, const void* s2, size_t count);

#endif