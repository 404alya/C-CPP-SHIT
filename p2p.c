#include <stdio.h>
#include <string.h>

typedef struct {
  char **str;
} A;


typedef struct {
  char* name;
  char **command;
  int *status;

  /*Output string returned from command*/
  char* output;
} Cmd;

int main(int argc, char *argv[]) {
  A a = {NULL};

  printf("%c", **a.str);

  return 0;
}

void l(A *a) {
  printf("%c", **a->str);
  int n = strlen(a->str);

}



void n(Cmd *cmd) {
  int a = strlen(*cmd->command);
}


