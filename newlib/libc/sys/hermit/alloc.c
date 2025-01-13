#include <stdalign.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/param.h>

void *sys_alloc(size_t size, size_t align);
void *sys_alloc_zeroed(size_t size, size_t align);
void *sys_realloc(void *ptr, size_t size, size_t align, size_t new_size);
void sys_dealloc(void *ptr, size_t size, size_t align);

void *malloc(size_t size) { return aligned_alloc(alignof(max_align_t), size); }

void *calloc(size_t num, size_t size) {
    size_t mem_align = MAX(alignof(size_t[2]), alignof(max_align_t));
    size_t header_size = MAX(sizeof(size_t[2]), alignof(max_align_t));
    size_t mem_size = header_size + num * size;

    void *mem = sys_alloc_zeroed(mem_size, mem_align);

    if (mem == NULL) {
        return NULL;
    }

    void *ptr = mem + header_size;

    *((size_t *)ptr - 2) = mem_size;
    *((size_t *)ptr - 1) = mem_align;

    return ptr;
}

void *realloc(void *ptr, size_t new_size) {
    if (ptr == NULL) {
        return malloc(new_size);
    }

    size_t mem_align = *((size_t *)ptr - 1);
    size_t header_size = MAX(sizeof(size_t[2]), mem_align);
    size_t mem_size = *((size_t *)ptr - 2);
    size_t new_mem_size = header_size + new_size;

    void *mem = ptr - header_size;

    void *new_mem = sys_realloc(mem, mem_size, mem_align, new_mem_size);

    if (new_mem == NULL) {
        return NULL;
    }

    void *new_ptr = new_mem + header_size;

    *((size_t *)new_ptr - 2) = new_mem_size;
    *((size_t *)new_ptr - 1) = mem_align;

    return new_ptr;
}

void free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    size_t mem_align = *((size_t *)ptr - 1);
    size_t header_size = MAX(sizeof(size_t[2]), mem_align);
    size_t mem_size = *((size_t *)ptr - 2);

    void *mem = ptr - header_size;

    sys_dealloc(mem, mem_size, mem_align);
}

void free_sized(void *ptr, size_t size) {
    if (ptr == NULL) {
        return;
    }

    size_t mem_align = *((size_t *)ptr - 1);
    size_t header_size = MAX(sizeof(size_t[2]), mem_align);
    size_t mem_size = header_size + size;

    void *mem = ptr - header_size;

    sys_dealloc(mem, mem_size, mem_align);
}

void free_aligned_sized(void *ptr, size_t alignment, size_t size) {
    if (ptr == NULL) {
        return;
    }

    size_t mem_align = MAX(alignof(size_t[2]), alignment);
    size_t header_size = MAX(sizeof(size_t[2]), alignment);
    size_t mem_size = header_size + size;

    void *mem = ptr - header_size;

    sys_dealloc(mem, mem_size, mem_align);
}

void *aligned_alloc(size_t alignment, size_t size) {
    size_t mem_align = MAX(alignof(size_t[2]), alignment);
    size_t header_size = MAX(sizeof(size_t[2]), alignment);
    size_t mem_size = header_size + size;

    void *mem = sys_alloc(mem_size, mem_align);

    if (mem == NULL) {
        return NULL;
    }

    void *ptr = mem + header_size;

    *((size_t *)ptr - 2) = mem_size;
    *((size_t *)ptr - 1) = mem_align;

    return ptr;
}
