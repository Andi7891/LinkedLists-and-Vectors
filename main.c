//With the macro below you can choose which library to test. (VECTOR/LINKED_LIST)
#define VECTOR

#ifdef VECTOR
#include "Vector.h"

int main(void) {
  Vector2d vec_a = {.x = 1.f, .y = 2.f};
  Vector2d vec_b = {.x = 2.f, .y = 3.f};
  Vector2d sum_vec = v_add(&vec_a, &vec_b);
  Vector2d diff_vec = v_subtract(&vec_a, &vec_b);
  print_vector2d(sum_vec);
  print_vector2d(diff_vec);
  return EXIT_SUCCESS;
}
#endif

#ifdef LINKED_LIST
#include "Linked_List.h"

int main(void) {
  Node *head_node = nullptr;
  generate_link_list(&head_node, 5);

  if (!modify_value_at(head_node, 3, 10.0)) return -100;
  print_linked_list(head_node);

  //printf("############REVERSED###########\n");

  //reverse_linked_list(&head_node);

  //print_linked_list(head_node);
  return EXIT_SUCCESS;
}
#endif