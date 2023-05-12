// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED)
    {
        return NULL;
    }

    mem_list_add(ptr, size);
    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;
    void *ptr = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED)
    {
        return NULL;
    }
    memset(ptr, 0, total_size);
    return ptr;
}

void free(void *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    struct mem_list *result = mem_list_find(ptr);
    munmap(ptr, result->len);
    mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL)
    {
        return malloc(size);
    }
    else if (size == 0)
    {
        free(ptr);
        return NULL;
    }
    else
    {
        size_t *size_p = (size_t *)ptr - 1;
        size_t oldSize = *size_p + sizeof(size_t);

        if (size <= oldSize)
        {
            return ptr;
        }
        else
        {
            void *newPtr = malloc(size);

            if (newPtr == NULL)
            {
                return NULL;
            }

            memcpy(newPtr, ptr, oldSize);
            free(ptr);
            return newPtr;
        }
    }
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t total_size;
    if (__builtin_mul_overflow(nmemb, size, &total_size))
    {
        return NULL;
    }
    return realloc(ptr, total_size);
}
