// https://stackoverflow.com/a/40926993/22740544

#include <stdio.h>

class Base {
public:
  int x;
};
class Derived : public Base {}; 

struct Base2 {
public:
  int x;
};
struct Derived2 : Base2 {}; // Is equivalent to struct Derived : public Base {}

int main() {
  // Program1
  Derived d;
  d.x = 20; // Compiler error because inheritance is private
  printf("%c", getchar());

  // Program2
  Derived2 d2;
  d2.x = 20; // Works fine because inheritance is public
  printf("%c", getchar());
  
  return 0;
} 


