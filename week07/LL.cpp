#include <iostream>


using std::cout;
using std::endl;


struct Node{
    int key = 0;
    Node* next = nullptr;
};

void push_front(Node*& head_ref, int new_key){
    if (head_ref == nullptr){
        head_ref = new Node;
        head_ref -> key = new_key;
        return;
    }
    Node *new_Node = new Node;
    new_Node -> next = head_ref;
    new_Node -> key = new_key;
    head_ref = new_Node;
    return;
}

void push_back(Node*& head_ref, int new_data){
    if (head_ref == nullptr){
        head_ref = new Node;
        head_ref -> key = new_data;
        return;
    }
    Node *current = head_ref;
    while (current -> next != nullptr) {
        current = current -> next;
    }
    current -> next = new Node;
    current -> next -> key = new_data;
}

void insert_after(Node*& prev_ref, int new_key){
    if (prev_ref == nullptr){
        return;
    }
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = prev_ref->next;
    prev_ref->next = new_node;
}

void destroy_list(Node*& head_ref){
    Node* current = head_ref;
    while (head_ref != nullptr){
        head_ref = current->next;
        delete current;
        current = head_ref;
    }
}

void print_list(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << endl;
        return;
    }
    Node *current = head_ref;
    while (current != nullptr) {
        cout << current -> key << " ";
        current = current -> next;
    }
    cout << endl;
}
