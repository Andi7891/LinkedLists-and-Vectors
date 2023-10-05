#include "Vector.h"

Vector2d v_add(Vector2d* vec_a, Vector2d* vec_b) {
  Vector2d temp_vec;
  temp_vec.x = vec_a->x + vec_b->x;
  temp_vec.y = vec_a->y + vec_b->y;
  return temp_vec;
}

Vector2d v_subtract(Vector2d* vec_a, Vector2d* vec_b) {
  Vector2d temp_vec;
  temp_vec.x = vec_a->x - vec_b->x;
  temp_vec.y = vec_a->y - vec_b->y;
  return temp_vec;
}

void print_vector2d(Vector2d vec) {
  printf("Vector content: x=%f, y=%f\n", vec.x, vec.y);
}

void print_vector2d_p(Vector2d vec, unsigned int precision) {
  printf("Vector content: x=%.*f, y=%.*f\n", precision, vec.x, precision, vec.y);
}