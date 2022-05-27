#include "memory.h"
#include <stdlib.h>

Allocator allocator_create(size_t block_capacity)
{
    Allocator alloc = {};
    alloc.block_capacity = block_capacity;

    return alloc;
}

void* allocator_allocate(Allocator* alloc, size_t bytes)
{
    if (bytes > alloc->cur_block->capacity - alloc->cur_block->size)
    {
        /* Plus de place, on alloue un nouveau bloc */
        MemoryBlock* new_block = (MemoryBlock*)malloc(sizeof(MemoryBlock));
        new_block->capacity = alloc->block_capacity;
        new_block->data = (char*)malloc(new_block->capacity);
        new_block->size = 0;
        new_block->next = nullptr;

        if (alloc->cur_block)
        {
            /* On ajoute le nouveau bloc à la suite, si il existe déjà un
            bloc courant */
            alloc->cur_block->next = new_block;
        }

        alloc->cur_block = new_block;

        return alloc->cur_block->data;
    }

    /* Sinon on augmente juste la taille du bloc courant */
    alloc->cur_block->size += bytes;

    return alloc->cur_block->data + bytes;
}

void allocator_clear(Allocator* alloc)
{
    MemoryBlock* next;

    /* On libère les blocs et leur mémoire associée */
    for (MemoryBlock* block = alloc->first_block; block != alloc->cur_block; block = next)
    {
        next = block->next;
        free(block->data);
        free(block);
    }
}
