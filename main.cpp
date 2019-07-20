#include <iostream>
#include "DoublyLinkedListClassTemplated.h"
#include "DoublyLinkedListClassTemplated.cpp"

using namespace std;

template <class T>
void pushNewVal(DoublyLinkedListTemplated<T> &dll)
{
    T val;

    cin >> val;

    dll.push(val);
}

template <class T>
void appendNewVal(DoublyLinkedListTemplated<T> &dll)
{
    T val;

    cin >> val;

    dll.append(val);
}

int main()
{
    DoublyLinkedListTemplated<char> dll;

    //char data testing
    dll.append('z');
    dll.append('y');
    dll.append('x');
    dll.append('a');
    dll.append('x');
    dll.append('w');
    dll.append('c');
    dll.append('b');

    //integer/double data testing
    /*
    dll.append(5);
    dll.append(10);
    dll.append(0);
    dll.append(20);
    dll.append(-5);
    dll.append(30);
    dll.append(25);
    dll.append(15);
     */

    int option = 0;
    int searchVal;

    while(option != -1)
    {
        cout << "0. Display the list." << endl;
        cout << "1. Append a node to the end of the list." << endl;
        cout << "2. Push a node to the front of the list (creates new root/head)." << endl;
        cout << "3. Pop from the end of the list." << endl;
        cout << "4. Search for a node in the list." << endl;
        cout << "5. Sort the list." << endl;
        cout << "6. Delete a node from the list." << endl;
        cout << "7. Display list in reverse." << endl;
        cout << "Enter an option (-1 to exit): ";

        cin >> option;

        switch(option)
        {
            case -1:
                break;
            case 0:
                dll.displayAllNodes();
                break;
            case 1:
                cout << "Enter a value: ";
                appendNewVal(dll);
                break;
            case 2:
                cout << "Enter a value: ";
                pushNewVal(dll);
                break;
            case 3:
                dll.pop();
                cout << "Pop!" << endl;
                break;
            case 4:
                int searchedPos;
                cout << "Enter a value to search for it: ";
                cin >> searchVal;
                searchedPos = dll.searchNode(searchVal);

                if(searchedPos != -1)
                    cout << "Number found at index " << searchedPos << "." << endl;
                else
                    cout << "Number could not be found." << endl;
                break;
            case 5:
                dll.sortList();
                cout << "List sorted." << endl;
                break;
            case 6:
                int nodePos;
                int returnVal;
                cout << "Enter node position you wish to delete: ";
                cin >> nodePos;

                returnVal = dll.deleteNode(nodePos);

                if(returnVal != -1)
                    cout << "Node deleted." << endl;
                else
                    cout << "Error: node could not be deleted." << endl;
                break;
            case 7:
                dll.reverseTraverseDisplay();
                break;

            default:
                cout << "That is not a valid menu option." << endl;
                break;
        }

        cin.clear();
        cin.ignore(256, '\n');
    }

    cout << "Exiting program... Goodbye!" << endl;


    //Call to destructor
    dll.~DoublyLinkedListTemplated();

    return 0;
}