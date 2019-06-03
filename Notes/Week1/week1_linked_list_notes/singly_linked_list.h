#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


class singly_linked_list
{
public:
    // Constructor
    singly_linked_list(); // done

    // Destructor
    ~singly_linked_list(); // done

    // Public methods
    int size();
    bool isEmpty();

    void prepend(int num);
    void append(int num);
    int pop_first();
    int pop_last();
    int see_first();
    int see_last();
    void printAll();

private:
    int numElements;

    struct node{
        int val;
        node* next;
    };

    node* head;

};

#endif // SINGLY_LINKED_LIST_H
