#include "Linked_List.h"

//Get the last node ptr.
Node *get_last_node(Node *head_ptr) {
  //Check if there is a linked list in the first place :).
  //You can't assume that there will be always a linked list.
  //Assert is used when the program cannot continue because of an error considered impossible to recover from.
  assert(head_ptr != nullptr);

  Node *current_node = head_ptr;
  while (current_node->next_ptr != nullptr) current_node = current_node->next_ptr;
  return current_node;
}

//This function generates a linked list with a specified number of nodes, also the default value
//of each node is incremented by 0.5f starting from 0.0f.
void generate_link_list(Node **head_ptr, size_t number_of_nodes) {
  double initial_value = 0.0f;

  //The first node (headNode) is initialized here.
  Node *current_node = (Node *) (malloc(sizeof(Node)));
  Node *prev_node = current_node;
  (*head_ptr) = current_node;
  (*head_ptr)->content = initial_value;
  (*head_ptr)->next_ptr = nullptr;
  (*head_ptr)->prev_ptr = nullptr;

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

    //Set the current node to the previous generated node.
    current_node = current_node->next_ptr;

    //The value of the current node's content variable is set.
    current_node->content = initial_value;

    //Set the previous node to the current node.
    current_node->prev_ptr = prev_node;

    //The previous node for the next node is the current one.
    prev_node = current_node;
  }

  //Setting the last Node's next_ptr to null, because is the last node in the list.
  current_node->next_ptr = nullptr;
}

//This function prints the entire list.
void print_linked_list(Node *head_ptr) {
  //Check if there is a linked list in the first place :).
  //You can't assume that there will be always a linked list.
  //Assert is used when the program cannot continue because of an error considered impossible to recover from.
  assert(head_ptr != nullptr);

  Node *current_node = head_ptr;
  do {
    printf("Address currentNode: %p Address prevNode: %p Address nextNode: %p Content: %f\n",
           current_node,
           current_node->prev_ptr,
           current_node->next_ptr,
           current_node->content);

    current_node = current_node->next_ptr;
  } while (current_node != nullptr);
}


/*
 * This function modifies the content in a specified node.
 * Return values is used to evaluate the success of the operation.
 * The function returns true if succeeded and false if not.
 */
bool modify_value_at(Node *head_ptr, size_t destination_node, double new_value) {
  //Check if there is a linked list in the first place :).
  //You can't assume that there will be always a linked list.
  if (head_ptr == nullptr) return false;

  Node *current_node = head_ptr;

  size_t iteration_index = 0;
  do {
    //Check if our current node is the desired one.
    //Otherwise, set the current node with the next one.
    if (iteration_index == destination_node) {
      current_node->content = new_value;
      return true; //Return success.
    } else {
      current_node = current_node->next_ptr;
      iteration_index++;
    }
  } while (current_node != nullptr);
  //If no element with the requested position was found just return failed operation.
  return false;
}
//Not functional.
//This function reverses the linked list, it needs only the head_ptr.
//The function is not expected to fail, thus no return value.
//If the head_ptr is null the assert macro will terminate the program.
void reverse_linked_list(Node **head_ptr) {
  //Exit if the head_ptr is null.
  assert((*head_ptr) != nullptr);

  Node *last_node = get_last_node(*head_ptr);
  Node *head_node = (*head_ptr);

  Node *current_node = last_node;

  //Switch between last and head node
  (*head_ptr) = last_node;

  Node* temp_ptr = nullptr;
  while (current_node->next_ptr != nullptr) {
    temp_ptr = current_node->prev_ptr;
    current_node->prev_ptr = current_node->next_ptr;
    current_node->next_ptr = temp_ptr;
    current_node = current_node->next_ptr;
  }
  (*head_ptr)->next_ptr = current_node;
  (*head_ptr)->prev_ptr = nullptr;
}

/*
 * This function get the content in a specified node.
 * Return values is used to evaluate the success of the operation.
 * The function returns true if succeeded and false if not.
 * !!!The result is passed through the value pointer, not the return value of the function.
 */
bool get_value_at(Node *head_ptr, size_t destination_node, double* value) {
  //Check if there is a linked list in the first place :).
  //You can't assume that there will be always a linked list.
  if (head_ptr == nullptr) return false;

  Node *current_node = head_ptr;

  size_t iteration_index = 0;
  do {
    //Check if our current node is the desired one.
    if (iteration_index == destination_node) {
      *value = current_node->content;
      return true;
      //Otherwise, set the current node with the next one.
    } else {
      current_node = current_node->next_ptr;
      iteration_index++;
    }
  } while (current_node != nullptr);
  //If no element with the requested position was found just return failed operation.
  return false;
}