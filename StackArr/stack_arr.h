#include <assert.h>
#include <stdalign.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define nullptr ((void*)NULL)

struct Stack {
  void* arr;
  size_t size;
  size_t capacity;
  size_t element_size;
  size_t real_elem_size;
};

struct Stack* stack_ctr(size_t size, size_t element_size);

// возвращает 1 если всё хорошо, возвращает 0 при ошибке в реаллоке
int resize(struct Stack* st, size_t new_size);

// возвращает 1 - если успех, 0 - если ошибка
int push(struct Stack* st, void* buffer);

// возвращает 1 - если успех, 0 - если ошибка
int top(struct Stack* st, void* buffer);

// возвращает 1 - если успех, 0 - если ошибка
int pop(struct Stack* st);

struct Stack* stack_dtr(struct Stack* st);
