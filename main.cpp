/*
  
lab17: modularize the linked list code
COMSC-210
Naveen Islam
IDE: emacs ( i code in emacs and import it into the repo folder)

 */
#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node *next;
};

// function prototypes
void frontNode(Node*& head, float value);
void tailNode(Node*& head, float value);
void deleteNode(Node*& head, int position);
void insertNode(Node*& head, int position, float value);
void deleteList(Node*& head);
void output(Node* head);

// main function
int main() {
  Node* head = nullptr;

  // create a linked list of size SIZE with random numbers 0-99
  for (int i = 0; i < SIZE; i++) {
    int tmp_val = rand() % 100;
    // calls frontNode to head to the front
    frontNode(head, tmp_val);
  }
  output(head);

  // deleting a node
  int entry;
  cout << "Which node to delete? " << endl;
  output(head);
  cout << "Choice --> ";
  cin >> entry;
    
  // calls deleteNode to delete the node at the users entry
  deleteNode(head, entry);
  // output to display the linked list after a node is deleted
  output(head);

  // insert a node
  cout << "After which node to insert 10000? " << endl;
  output(head);
  cout << "Choice --> ";
  cin >> entry;
  // calls insertNode to insert the value 10000 into the user specified entry
  insertNode(head, entry, 10000);
  // output to display the addition of 10000 to the linked list
  output(head);

  // deleting the linked list
  deleteList(head);
  output(head);

  return 0;
}

// function frontNode. creates a newNode, assigns value to the new node, and sets the next pointer of the new node
void frontNode(Node*& head, float value) {
  Node* newNode = new Node;
  
  newNode->value = value;
  newNode->next = head;
  head = newNode;
}

// function tailNode. adds a node to the end of the linked list
void tailNode(Node*& head, float value) {
  Node* newNode = new Node{value, nullptr};
  
  if (!head) {
    head = newNode;
  } else {
    Node* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }
}

// function deleteNode. deletes a node by positon
void deleteNode(Node*& head, int position) {
  Node* current = head;
  if (position == 1) {
    head = current->next;
    delete current;
    return;
  }
  Node* prev = nullptr;
  for (int i = 1; current && i < position; i++) {
    prev = current;
    current = current->next;
  }

  if (current) {
    prev->next = current->next;
    delete current;
  }
}

// function insertNode. insert a node in a specific spot
void insertNode(Node*& head, int position, float value) {
  Node* newNode = new Node;
  
  newNode->value = value;
  if (position == 1) {
    newNode->next = head;
    head = newNode;
    return;
  }
  
  Node* current = head;
  
  Node* prev = nullptr;
  for (int i = 0; current && i < position; i++) {
    prev = current;
    current = current->next;
  }

  if (prev) {
    newNode->next = current;
    prev->next = newNode; 
  }
}

// function deleteList. deletes the entire linked list
void deleteList(Node*& head) {
  Node* current = head;
  
  while (current) {
    Node* nextNode = current->next;
    delete current;
    current = nextNode;
  }
  head = nullptr;
}

// function output. output the linked list
void output(Node* hd) {
  if (!hd) {
    cout << "Empty list.\n";
    return;
  }
  int count = 1;
  Node * current = hd;
  while (current) {
    cout << "[" << count++ << "] " << current->value << endl;
    current = current->next;
  }
  cout << endl;
}

