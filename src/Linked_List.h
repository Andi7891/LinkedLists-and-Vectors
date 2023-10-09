/**
 * Doubly Linked List
 * The working principle is the following:
 * headNode/firstNode   nextNode/secondNode      endOfTheList
 * -->[Node]<----------->[Node]<---------------->NULL
 * Each node has a variable, which contains the content of the node, a pointer to
 * the next node, and a pointer to the previous node
 */

//I will add many comments, so everyone could understand the idea behind of each line.

#include <cstdio> //Used for printf.
#include <cstdlib> //Used for malloc.
#include <cassert> //Exit program in case of a critical error.
/*
 * Conventions:
 * 1.We could use (?) when we are not sure about something, or (??) if there is a better word, but we don't know which one.
 * 2.To be expanded...
 */

//Just an alias. Ex: Instead of writing everywhere struct Node* you could use Node*
//This could be implemented in many ways.
//typedef struct Node Node;

//Because in no C's standard is defined a nullptr macro as in C++11 standard I defined one bellow.
//The only role of the macro is to distinguish between a ptr and a number operation.
//#define nullptr ((void*)0)

//Defined/Custom/Derived? type.
//The base declaration and definition of the linked list node.
template<typename T>
struct Node {
  T content;
  Node *next_ptr;
  Node *prev_ptr;
};

#ifdef REMOVE
//Get the last node ptr.
template<typename T>
Node<T> *get_last_node(Node<T> *head_ptr) {
  //Check if there is a linked list in the first place :).
  //You can't assume that there will be always a linked list.
  //Assert is used when the program cannot continue because of an error considered impossible to recover from.
  assert(head_ptr != nullptr);

  Node<T> *current_node = head_ptr;
  while (current_node->next_ptr != nullptr) current_node = current_node->next_ptr;
  return current_node;
}

//This function generates a linked list with a specified number of nodes.
// Also, the default value of each node is incremented by 0.5f starting from 0.0f.
template<typename T>
void generate_link_list(Node<T> **head_ptr, size_t number_of_nodes) {
  double initial_value = 0.0f;

  //The first node (headNode) is initialized here.
  auto *current_node = (Node<T> *) (malloc(sizeof(Node<T>)));
  Node<T> *prev_node = current_node;
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
    current_node->next_ptr = (Node<T> *) (malloc(sizeof(Node<T>)));

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
template<typename T>
void print_linked_list(Node<T> *head_ptr);

/*
 * This function modifies content in a specified node.
 * Return value is used to evaluate the success of the operation.
 * The function returns true if succeeded and false if not.
 */
template<typename T>
bool modify_value_at(Node<T> *head_ptr, size_t destination_node, double new_value);

//This function reverses the linked list, it needs only the head_ptr.
//The function is not expected to fail, thus no return value.
template<typename T>
void reverse_linked_list(Node<T> **head_ptr);

template<typename T>
bool get_value_at(Node<T> *head_ptr, size_t destination_node, double* value);
#endif