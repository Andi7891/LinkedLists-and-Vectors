/**
 * Doubly Linked List
 * The working principle is the following:
 * headNode/firstNode   nextNode/secondNode      endOfTheList
 * -->[Node]<----------->[Node]<---------------->NULL
 * Each node has a variable, which contains the content of the node, a pointer to
 * the next node, and a pointer to the previous node
 */

//I will add many comments, so everyone could understand the idea behind of each line.

#include <stdio.h> //Used for printf.
#include <stdlib.h> //Used for malloc.
#include <stdbool.h> //Used for true/false macros and bool type.
#include <assert.h> //Exit program in case of a critical error.
/*
 * Conventions:
 * 1.We could use (?) when we are not sure about something, or (??) if there is a better word, but we don't know which one.
 * 2.To be expanded...
 */

//Just an alias. Ex: Instead of writing everywhere struct Node* you could use Node*
//This could be implemented in many ways.
typedef struct Node Node;

//Because in no C's standard is defined a nullptr macro as in C++11 standard I defined one bellow.
//The only role of the macro is to distinguish between a ptr and a number operation.
#define nullptr ((void*)0)

//Defined/Custom/Derived? type.
//The base declaration and definition of the linked list node.
struct Node {
  double content;
  Node *next_ptr;
  Node *prev_ptr;
};

//Get the last node ptr.
Node *get_last_node(Node *head_ptr);

//This function generates a linked list with a specified number of nodes, also the default value
//of each node is incremented by 0.5f starting from 0.0f.
void generate_link_list(Node **head_ptr, size_t number_of_nodes);

//This function prints the entire list.
void print_linked_list(Node *head_ptr);

/*
 * This function modifies content in a specified node.
 * Return values is used to evaluate the success of the operation.
 * The function returns true if succeeded and false if not.
 */
bool modify_value_at(Node *head_ptr, size_t destination_node, double new_value);

//This function reverses the linked list, it needs only the head_ptr.
//The function is not expected to fail, thus no return value.
void reverse_linked_list(Node **head_ptr);

bool get_value_at(Node *head_ptr, size_t destination_node, double* value);