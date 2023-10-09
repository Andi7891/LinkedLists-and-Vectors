/**
 * Vector library
 * It was remade in c++ as a generic(template) library without a source code file,
 * only a header file.
 */

#ifndef VECTOR_VISUALIZER_SRC_VECTOR_H_
#define VECTOR_VISUALIZER_SRC_VECTOR_H_

template <typename T>
struct Vector2d {
  T x;
  T y;
};

//abs = sqrt(a^2 + b^2)
template <typename T>
T absolut_value_2d(Vector2d<T> *vec) {
  return sqrt((vec->x * vec->x) + (vec->y * vec->y));
}

template <typename T>
Vector2d<T> v_add(Vector2d<T>* vec_a, Vector2d<T>* vec_b) {
  Vector2d<T> temp_vec;
  temp_vec.x = vec_a->x + vec_b->x;
  temp_vec.y = vec_a->y + vec_b->y;
  return temp_vec;
}

template <typename T>
Vector2d<T> v_subtract(Vector2d<T>* vec_a, Vector2d<T>* vec_b) {
  Vector2d<T> temp_vec;
  temp_vec.x = vec_a->x - vec_b->x;
  temp_vec.y = vec_a->y - vec_b->y;
  return temp_vec;
}

template <typename T>
T v_dot(Vector2d<T>* vec_a, Vector2d<T>* vec_b) {
  return vec_a->x * vec_b->x + vec_a->y * vec_b->y;
}

template <typename T>
void print_vector2d(Vector2d<T> vec) {
  printf("Vector content: x=%f, y=%f\n", vec.x, vec.y);
}

template <typename T>
void print_vector2d_p(Vector2d<T> vec, unsigned int precision) {
  printf("Vector content: x=%.*f, y=%.*f\n", precision, vec.x, precision, vec.y);
}

#endif //VECTOR_VISUALIZER_SRC_VECTOR_H_