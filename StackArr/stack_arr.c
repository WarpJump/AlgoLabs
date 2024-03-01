#include "stack_arr.h"

struct Stack* stack_ctr(size_t size, size_t element_size) {
  assert(element_size != 0);
  struct Stack* new_stack = (struct Stack*)calloc(1, sizeof(struct Stack));

  new_stack->capacity = size;

  new_stack->real_elem_size =
      ((element_size - 1) / alignof(max_align_t) + 1) * alignof(max_align_t);

  // выделение памяти с учётом выравнивания
  new_stack->arr = calloc(size, new_stack->real_elem_size);
  new_stack->element_size = element_size;
  return new_stack;
}

// возвращает 1 если всё хорошо, возвращает 0 при ошибке в реаллоке
int resize(struct Stack* st, size_t new_size) {
  assert(st != nullptr);

  void* tmp = realloc(st->arr, new_size * st->real_elem_size);

  if (tmp == nullptr) {
    return 0;
  }
  st->capacity = new_size;
  st->arr = tmp;
  return 1;
}

// возвращает 1 - если успех, 0 - если ошибка
int push(struct Stack* st, void* buffer) {
  assert(st != nullptr);

  if (st->size == st->capacity) {
    if (st->size == 0) {
      st->size = 1;
    }
    int code = resize(st, 2 * st->size);
    if (code == 0) {
      return 0;
    }
  }
  memcpy(st->arr + st->real_elem_size * st->size, buffer, st->element_size);
  ++st->size;
  return 1;
}

// возвращает 1 - если успех, 0 - если ошибка
int top(struct Stack* st, void* buffer) {
  assert(st != nullptr);
  if (st->size == 0) {
    return 0;
  }
  memcpy(buffer, st->arr + st->real_elem_size * (st->size - 1),
         st->element_size);
  return 1;
}

// возвращает 1 - если успех, 0 - если ошибка
int pop(struct Stack* st) {
  if (st->size == 0) {
    return 0;
  }
  --st->size;
  return 1;
}

struct Stack* stack_dtr(struct Stack* st) {
  assert(st != nullptr);
  free(st->arr);
  free(st);
  return nullptr;
}
