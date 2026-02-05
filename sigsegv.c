#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define DA_INIT_CAP 256
#define da_reserve(da, expected_capacity)                                                  \
    do {                                                                                   \
        if ((expected_capacity) > (da)->capacity) {                                        \
            if ((da)->capacity == 0) {                                                     \
                (da)->capacity = DA_INIT_CAP;                                              \
            }                                                                              \
            while ((expected_capacity) > (da)->capacity) {                                 \
                (da)->capacity *= 2;                                                       \
            }                                                                              \
            (da)->items = realloc((da)->items, (da)->capacity * sizeof(*(da)->items));     \
            assert((da)->items != NULL && "Buy more RAM lol");                             \
        }                                                                                  \
    } while (0)

#define da_append(da, item)                    \
    do {                                       \
        da_reserve((da), (da)->count + 1);     \
        (da)->items[(da)->count++] = (item);   \
    } while (0)                                \


typedef struct {
  size_t *items;
  size_t count;
  size_t capacity;
} Numbers;

int main() {
  Numbers numbers = {0};
  da_append(&numbers, 9);

  free(numbers.items);
  numbers.items = 0;
  numbers.count = 0;
  numbers.capacity = 0;

  for (size_t i = 0; i < 200; ++i) {
    da_append(&numbers, i);
  }

  for (size_t i = 0; i < numbers.count; ++i) {
    printf("%zu\n", numbers.items[i]);
  }

  return 0;
};
