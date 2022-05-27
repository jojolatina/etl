#ifndef ALLOCATOR_H_INCLUDED
#define ALLOCATOR_H_INCLUDED

#include <stddef.h> /* size_t */

/* Simple allocateur permettant d'allouer des données comme une pile */
/* Il y a une liste chainée de blocs, chacun ayant une capacité, une taille actuelle et des données quelconques */

struct MemoryBlock
{
    char* data;
    size_t size;
    size_t capacity;
    MemoryBlock* next;
};

struct Allocator
{
    MemoryBlock* first_block;
    MemoryBlock* cur_block;
    size_t block_capacity;
};

Allocator allocator_create(size_t block_capacity);
void* allocator_allocate(Allocator* alloc, size_t bytes);
void allocator_clear(Allocator* alloc);

#endif
