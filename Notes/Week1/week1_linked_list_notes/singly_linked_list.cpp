#include <iostream>
#include "singly_linked_list.h"

// Constructor
singly_linked_list::singly_linked_list(){
    head = nullptr;
    numElements = 0;
}

// Destructor
singly_linked_list::~singly_linked_list(){
    while(head != nullptr){
        node* next = head->next;
        delete head;
        head = next;
    }
}


bool singly_linked_list::isEmpty(){
    return head==nullptr;
}


int singly_linked_list::size(){
    return numElements;
}


void singly_linked_list::append(int num){
    node *n = new node;
    n->val = num;
    n->next = nullptr;

    if (isEmpty()){
        head = n;
    } else {
        node *cur = head;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = n;
    }
    numElements++;
}


void singly_linked_list::prepend(int num){
    node *n = new node;
    n->val = num;
    n->next = head;
    head = n;
    numElements++;
}


void singly_linked_list::printAll(){
    for(node *cur = head; cur!=nullptr; cur=cur->next){
        std::cout << cur->val << "-->";
    }
    std::cout << std::endl;
}


int singly_linked_list::pop_first(){
    if (isEmpty()){
        std::cerr << "Popping from an empty list" << std::endl;
        return INT_MIN;
    }
    node* cur = head;
    head = head->next;
    int val = cur->val;
    delete cur;
    numElements--;
    return val;
}


int singly_linked_list::pop_last(){
    if(isEmpty()){
        std::cout << "Popping from an empty list" << std::endl;
        return INT_MIN;
    }

    node *cur = head;
    while(cur->next->next!=nullptr){
        cur = cur->next;
    }
    node *last = cur->next;
    int val = last->val;

    cur->next = nullptr;
    delete last;
    numElements--;
    return val;
}

int singly_linked_list:: see_first(){
    if (isEmpty()){
        std:: cerr << "List is empty" << std::endl;
        return INT_MIN;
    }
    return head->val;
}

int singly_linked_list:: see_last(){
    if (isEmpty()){
        std::cerr << "List is empty" << std::endl;
        return INT_MIN;
    }
    node *cur = head;
    while (cur->next != nullptr){
        cur = cur->next;
    }
    return cur->val;
}
