//With the macro below you can choose which library to test. (VECTOR/LINKED_LIST)
#define LINKED_LIST

//Macro for enabling testing
//#define TEST

#ifdef VECTOR
#include "Vector.h"

int main(void) {

#ifdef TEST
  Vector2d vec_a = {.x = 5.f, .y = 1.f};
  Vector2d vec_b = {.x = 4.f, .y = 3.f};

  Vector2d sum_vec = v_add(&vec_a, &vec_b);
  if ((sum_vec.x == 9.f) && (sum_vec.y == 4.f))
    printf("Addition succeeded\n");
  else
    printf("Addition failed\n");

  Vector2d diff_vec = v_subtract(&vec_a, &vec_b);
  if ((diff_vec.x == 1.f) && (diff_vec.y == -2.f))
    printf("Subtraction succeeded\n");
  else
    printf("Subtraction failed\n");

  if (absolut_value_2d(&vec_a) == sqrt(26))
    printf("Absolut value succeeded\n");
  else
    printf("Absolut value failed\n");

  if (v_dot(&vec_a, &vec_b) == 23)
    printf("Dot product succeeded\n");
  else
    printf("Dot product failed\n");

#endif

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
  //Not functional.
  //reverse_linked_list(&head_node);

  //print_linked_list(head_node);
  return EXIT_SUCCESS;
}
#endif