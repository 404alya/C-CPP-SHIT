#include <time.h>
#include <stdlib.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define DA_INIT_CAP 256
#define da_reserve(da, expected_capacity)                                              \
    do {                                                                                   \
        if ((expected_capacity) > (da)->capacity) {                                        \
            if ((da)->capacity == 0) {                                                     \
                (da)->capacity = DA_INIT_CAP;                                          \
            }                                                                              \
            while ((expected_capacity) > (da)->capacity) {                                 \
                (da)->capacity *= 2;                                                       \
            }                                                                              \
            (da)->items = realloc((da)->items, (da)->capacity * sizeof(*(da)->items)); \
            assert((da)->items != NULL && "Buy more RAM lol");                         \
        }                                                                                  \
    } while (0)

// Append an item to a dynamic array
#define da_append(da, item)                    \
    do {                                       \
        da_reserve((da), (da)->count + 1);      \
        (da)->items[(da)->count++] = (item);   \
    } while (0) \


typedef struct {
  int *items;
  size_t count;
  size_t capacity;
} Nums;

int main() {
  srand(time(NULL));
  Nums nums  = {
    .items=0,
    .count=0
  };


  while (1) {
    da_append(&nums, rand());
    printf("%d\n", nums.items[nums.count - 1]);
  }

  return 0;
}
