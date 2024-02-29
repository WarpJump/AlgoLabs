#include <stdalign.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define nullptr ((void*)NULL)

struct Stack {
  void* stack_top;
  size_t element_size;
  size_t shift_from_beginning;
};

// задаёт размер одного элемента, возвращает экземпляр стека на списке
struct Stack* stack_ctr(size_t element_size);

// Добавляет элемент в конец контейнера, возвращает 1 если добавление успешно,
// 0 - не успешно
int push(struct Stack* st, void* buffer);

// Возвращает последний элемент
int top(struct Stack* st, void* buffer);

// Удаляет последний элемент, не возвращая его, возвращает 1 - если успех, 0
// - если ошибка
int pop(struct Stack* st);

// Уничтожает контейнер, освобождая память, возвращает nullptr
struct Stack* stack_dtr(struct Stack* st);