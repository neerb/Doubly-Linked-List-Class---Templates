#ifndef DOUBLYLINKEDLISTCLASS_DOUBLYLINKEDLISTTEMPLATED_H
#define DOUBLYLINKEDLISTCLASS_DOUBLYLINKEDLISTTEMPLATED_H

template <class T>
class DoublyLinkedListTemplated
{
    struct Node
    {
        Node *left = nullptr;
        Node *right = nullptr;
        T val;
    };

private:
    //Beginning of list pointer
    Node *head = nullptr;
    //End of list pointer
    Node *end = nullptr;

public:
    //Constructors
    DoublyLinkedListTemplated();
    DoublyLinkedListTemplated(T initialVal);

    //Linked List Methods and Operations
    void append(T val);
    void push(T val);
    void pop();
    int deleteNode(int pos);
    int searchNode(T searchVal);
    void sortList();
    void displayAllNodes();
    void reverseTraverseDisplay();

    //Destructor
    ~DoublyLinkedListTemplated();
};


#endif //DOUBLYLINKEDLISTCLASS_DOUBLYLINKEDLISTTEMPLATED_H
