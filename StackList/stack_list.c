#include "stack_list.h"

// задаёт размер одного элемента, возвращает экземпляр стека на списке
struct Stack* stack_ctr(size_t element_size) {
  struct Stack* new_stack = (struct Stack*)calloc(1, sizeof(struct Stack));
  new_stack->stack_top = nullptr;
  new_stack->element_size = element_size;

  // выравнивание начала области с данными
  new_stack->shift_from_beginning =
      ((sizeof(void*) - 1) / alignof(max_align_t) + 1) * alignof(max_align_t);

  return new_stack;
}

// Добавляет элемент в конец контейнера, возвращает 1 если добавление успешно,
// 0 - не успешно
int push(struct Stack* st, void* buffer) {
  void* new_node = calloc(st->shift_from_beginning + st->element_size, 1);
  if (new_node == nullptr) {
    return 0;
  }

  // первые sizeof(void*) байт будут заняты под указатель на предыдущий элемент
  // стека
  *((void**)new_node) = st->stack_top;

  st->stack_top = new_node;
  memcpy(new_node + st->shift_from_beginning, buffer, st->element_size);
  return 1;
}

// Возвращает последний элемент
int top(struct Stack* st, void* buffer) {
  if (st->stack_top == nullptr) {
    return 0;
  }
  memcpy(buffer, st->stack_top + st->shift_from_beginning, st->element_size);
  return 1;
}

// Удаляет последний элемент, не возвращая его, возвращает 1 - если успех, 0
// - если ошибка
int pop(struct Stack* st) {
  if (st->stack_top == nullptr) {
    return 0;
  }
  void* new_top = *((void**)st->stack_top);
  free(st->stack_top);
  st->stack_top = new_top;
  return 1;
}

// Уничтожает контейнер, освобождая память, возвращает nullptr
struct Stack* stack_dtr(struct Stack* st) {
  while (st->stack_top != nullptr) {
    pop(st);
  }
  free(st);
  return nullptr;
}
