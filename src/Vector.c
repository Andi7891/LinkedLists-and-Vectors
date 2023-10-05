#include "Vector.h"

//abs = sqrt(a^2 + b^2)
double absolut_value_2d(Vector2d *vec) {
  return sqrt((vec->x * vec->x) + (vec->y * vec->y));
}

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

double v_dot(Vector2d* vec_a, Vector2d* vec_b) {
  return vec_a->x * vec_b->x + vec_a->y * vec_b->y;
}

//Not done yet
Vector3d v_cross(Vector3d* vec_a, Vector3d* vec_b) {
  Vector3d temp_vec = {.x = 0.f, .y = 0.f, .z = 0.f};
  return temp_vec;
}

void print_vector2d(Vector2d vec) {
  printf("Vector content: x=%f, y=%f\n", vec.x, vec.y);
}

void print_vector2d_p(Vector2d vec, unsigned int precision) {
  printf("Vector content: x=%.*f, y=%.*f\n", precision, vec.x, precision, vec.y);
}
