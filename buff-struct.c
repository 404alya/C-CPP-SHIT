#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *items;
  size_t count;
  size_t capacity;
} ABCda;

typedef struct {
  int a;
  int b;
  char c;
} ABC;

#define ABC_OFFSET sizeof(ABC)
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
            (da)->items = realloc((da)->items, (da)->capacity * ABC_OFFSET);               \
        }                                                                                  \
    } while (0)

#define da_append(da, memsrc, memcount)                                          \
    do {                                                                         \
        da_reserve((da), (da)->count + 1);                                       \
        memcpy(&(da)->items+ ( (((da)->count++)-1)*ABC_OFFSET ), memsrc, memcount);  \
    } while (0)                                                                  \

int main() {
  ABC abc = {0,2,6};
  char *u;
  ABCda abcda = {0};
 
  for (int i = 0; i < 400; ++i) {
    da_append(&abcda, &abc, sizeof(abc));
  }
      printf("count: %zu\n", abcda.count);

  for (int i = 0; i < abcda.count; ++i) {
     ABC *a = (ABC *) &abcda.items[i];
      
    printf("VALUE: %d\n", (a)->b);
  }
}
