#define LINMATH_H_DEFINE_VEC(n) \
typedef float vec##n[n]; \

int main() {
  LINMATH_H_DEFINE_VEC(10);
  vec##10[10] a = 10.0;
  return 0;
}
