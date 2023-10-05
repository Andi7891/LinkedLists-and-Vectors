/**
 * Vector library
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector2d Vector2d;

struct Vector2d {
  double x;
  double y;
};

Vector2d v_add(Vector2d* vec_a, Vector2d* vec_b);
Vector2d v_subtract(Vector2d* vec_a, Vector2d* vec_b);
Vector2d v_cross();
Vector2d v_dot();
//...

void print_vector2d(Vector2d vec);
void print_vector2d_p(Vector2d vec, unsigned int precision);

typedef struct Vector2d Vector2d;

struct Vector3d {
  double x;
  double y;
  double z;
};