/**
 * Vector library
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vector2d Vector2d;

struct Vector2d {
  double x;
  double y;
};

double absolut_value_2d(Vector2d* vec);
Vector2d v_add(Vector2d* vec_a, Vector2d* vec_b);
Vector2d v_subtract(Vector2d* vec_a, Vector2d* vec_b);
double v_dot(Vector2d* vec_a, Vector2d* vec_b);
void print_vector2d(Vector2d vec);

void print_vector2d_p(Vector2d vec, unsigned int precision);
typedef struct Vector3d Vector3d;

struct Vector3d {
  double x;
  double y;
  double z;
};

Vector3d v_cross_3d(Vector3d* vec_a, Vector3d* vec_b);
