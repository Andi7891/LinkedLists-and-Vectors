/**
 * The working principle is the following:
 * headNode/firstNode   nextNode/secondNode      endOfTheList
 * -->[Node]------------>[Node]----------------->NULL
 * Each node has a variable, which contains the content of the node, and a pointer to the nextNode
 */

//I will add many comments, so everyone could understand the idea behind of it.

#include <stdio.h> //Used for printf.
#include <stdlib.h> //Used for malloc.
#include <stdbool.h> //Used for true/false macros and bool type.

/*
 * Conventions:
 * 1.I will use ? when I am not sure about something, or maybe it has a better replace.
 * 2.To be expanded...
 */

//Just an alias. Ex: Instead of writing everywhere struct Node* we could use Node*
//This could be implemented in many ways.
typedef struct Node Node;

//Defined/Custom/Derived? type.
//The base declaration and definition of the linked list node.
struct Node {
  double node_content;  //The content stored in a node.
  Node *next_ptr;
};

//This function generates a linked list with a specified number of nodes, also the default value
// of each node is incremented by 0.5f starting from 0.0f.
void generate_link_list(Node **head_ptr, size_t number_of_nodes) {
  double initial_value = 0.0f;

  //The first node (headNode) is initialized here.
  Node *current_node = (Node *) (malloc(sizeof(Node)));
  *head_ptr = current_node;
  (*head_ptr)->node_content = initial_value;

  /*
   * Here are initialized the rest of the nodes.
   * The number_of_nodes parameter is referring to the total numbers of nodes in the list including the headNode.
   * Because of the rule defined before, in the for loop condition, the number_of_nodes variable is subtracted by 1,
   * so this way we take into account the headNode created before.
   */

  for (size_t index = 0; index < (number_of_nodes - 1); index++) {
    //The initial value is incremented.
    initial_value += 0.5f;

    //The next node is generated.
    current_node->next_ptr = (Node *) (malloc(sizeof(Node)));

    //We are setting the current node to the previous generated node.
    current_node = current_node->next_ptr;

    //The value of the current node's content variable is set.
    current_node->node_content = initial_value;
  }

  //Setting the last Node's next_ptr to null, because is the last node in the list.
  current_node->next_ptr = NULL;
}

void print_linked_list(Node *head_ptr) {
  Node *current_node = head_ptr;
  do {
    printf("Address: %p Value: %f\n", current_node, current_node->node_content);
    current_node = current_node->next_ptr;
  } while (current_node != NULL);
}

/*
 * The function is not complete and it needs comments, so I just commented it out for the moment.
bool modify_value_at(Node *head_ptr, size_t final_dest, double value) {
  Node *current_node = head_ptr;
  if (final_dest == 0) {
    head_ptr->node_content = value;
    return true;
  } else {
    size_t current_node = 1;
    do {
      current_node = current_node->next_ptr;
      if (current_node == final_dest) {
        current_node->node_content = value;
        return true;
      }
      current_node++;
    } while (current_node->next_ptr != NULL);
    return false;
  }
}
*/


int main(void) {
  Node *head_node = NULL;
  generate_link_list(&head_node, 5);

  //if (!modify_value_at(head_node, 5, 10.0)) return -100;

  print_linked_list(head_node);
}