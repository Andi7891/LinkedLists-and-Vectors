/**
 * The working principle is the following:
 * headNode/firstNode   nextNode/secondNode
 * -->[Node]------------>[Node]-->NULL
 * Each node has a variable, which contains the content of the node, and a pointer to the nextNode
 */

//I will add many comments, so everyone could understand the idea behind of it
#include <stdio.h> //Used for printf
#include <stdlib.h> //Used for malloc
#include <stdbool.h> //Used for true/false macros and bool type

/*
 * Conventions: I will use ? when I am not sure about something, or maybe it has a better replace.
 * To be expanded...
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
// of each node is incremented by 0.5f starting from 0.0f
void generateNodes(Node **head_ptr, size_t number_of_nodes) {
  double initial_value = 0.0f;
  Node *temp_node = (Node *) (malloc(sizeof(Node)));
  *head_ptr = temp_node;
  for (size_t index = 0; index < number_of_nodes; index++) {
    temp_node->next_ptr = (Node *) (malloc(sizeof(Node)));
    temp_node->node_content = initial_value;
    temp_node = temp_node->next_ptr;
    initial_value += 0.5f;
  }
  temp_node->next_ptr = NULL;
}

void print_list(Node *head_ptr) {
  Node *temp_node = head_ptr;
  do {
    printf("Address: %p Value: %f\n", temp_node, temp_node->node_content);
    temp_node = temp_node->next_ptr;
  } while (temp_node->next_ptr != NULL);
}

bool modify_value_at(Node *head_ptr, size_t final_dest, double value) {
  Node *temp_node = head_ptr;
  if (final_dest == 0) {
    head_ptr->node_content = value;
    return true;
  } else {
    size_t current_node = 1;
    do {
      temp_node = temp_node->next_ptr;
      if (current_node == final_dest) {
        temp_node->node_content = value;
        return true;
      }
      current_node++;
    } while (temp_node->next_ptr != NULL);
    return false;
  }
}

int main(void) {
  Node *head_node = NULL;
  generateNodes(&head_node, 5);
  if (!modify_value_at(head_node, 5, 10.0)) return -100;
  print_list(head_node);
}