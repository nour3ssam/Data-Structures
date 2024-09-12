#include <iostream>
using namespace std;
class LinkedList {
    struct Node {
        int item;
        Node* next;
    };
    Node* first;
    Node* last;
    int size;
public:
    LinkedList() {
        first = last = NULL;
        size = 0;
    }
    void InsertFirst(int element) {
        Node* newptr = new Node;
        newptr->item = element;
        if (size == 0) {
            first = last = newptr;
            newptr->next = NULL;
        }
        else {
            newptr->next = first;
            first = newptr;
        }
        size++;
    }
    void InsertLast(int element) {
        Node* newptr = new Node;
        newptr->item = element;
        if (size == 0) {
            first = last = newptr;
            newptr->next = NULL;
        }
        else {
            last->next = newptr;
            newptr->next = NULL;
            last = newptr;
        }
        size++;
    }
    void InsertPos(int pos, int element) {
        if (pos > 0 or pos > size) {
            cout << "out of range " << endl;
        }
        else {
            Node* newptr = new Node;
            newptr->item = element;
            if (pos == 0) {
                InsertFirst(element);
            }
            else if (pos == size) {
                InsertLast(element);

            }
            else {
                Node* current = new Node;
                current = first;
                for (int i = 1; i < pos; i++) {
                    current = current->next;
                }
                newptr->next = current->next;
                current->next = newptr;

            }
        }
    }
    void print() {
        if (size == 0 or first == NULL) {
            cout << "no item to display! " << endl;
        }
        else {
            Node* temp = first;
            while (temp != NULL) {
                cout << temp->item << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int CountNodes() {

        return size;
    }

    void RemoveFirst() {
        if (size == 0) {
            cout << "Empty List" << endl;
        }
        else if(size==1) {
            delete first;
            first = last = NULL;
            size--;
        }
        else {
            Node* cur = first;
            first = first->next;
            delete cur;// delete the node that the pointer point it
            size--;
        }
    }
    void RemoveLast() {
        if (size == 0) {
            cout << "Empty List" << endl;
        }
        else if (size == 1) {
            delete last;
            first = last = NULL;
            size--;
        }
        else {
            Node* temp = first;
            Node* cur = first->next;
            while (cur != last) {
                temp = cur;
                cur = cur->next;
            }
            delete cur;// delete the node that the pointer point it
            temp->next = NULL;
            last = temp;
            size--;

        }
    }

    void DeletePos(int pos) {
        if (pos == 1) {
            RemoveFirst();
        }
        else {
            if (pos > 0  and  pos <= CountNodes()) {
               Node* temp = first;
                int  count = 1;
                while (count != pos - 1) {
                    temp = temp->next;
                    count++;
                }
                Node* ptr = temp->next;
                temp->next = temp->next->next;
                delete ptr;
            }
            else {
                cout << "Out of the range! " << endl;

            }

        }
    }

    void DeleteValue(int element) {
        if (size == 0) {
            cout << "Nothing to Delete!" << endl;
        }
        else {
            Node* cur, * prev;
            if (first->item == element) {
                 cur = first;
                first = first->next;
                delete cur;// delete the node that the pointer point it
                size--;
                if (size == 0) {
                    first = last = NULL;
                }
            }
            else {
                cur = first->next; prev = first;
                while (cur != NULL and cur->item != element) {
                    prev = cur;
                    cur = cur->next;
                }
                if (cur == NULL) {
                    cout << "Element not found! " << endl;

                }
                else {
                    prev->next = cur->next;
                    if (last == cur) {
                        last = prev;
                    }
                    delete cur;
                    size--;
                }
            }

        }
    }

    void SearchNode(int element) {
        int count = 1;
        bool ch= 0;
        Node* temp = first;
        while (temp != NULL) {
            if (temp->item == element) {
                ch = 1;
                break;
            }
            temp = temp->next;
            count++;
        }
        if (ch) {
        cout << "Element found at " << count << " position " << endl;
            
        }
        else {
            cout << "Element not found! " << endl;
        }
    }

    void ReverseLinkedList() {
        Node* cur, * Next, * prev;
        prev = NULL;
        cur = first;
        Next = cur->next;
        while (cur != NULL) {
            Next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = Next;
        }
        first = prev;
    }

};

int main() {
    LinkedList l;
    int option = 0;
    int element;
    while (1) {
        cout << "1- Insert at beginning " << endl;
        cout << "2- Insert at the end " << endl;
        cout << "3- Insert at position " << endl;
        cout << "4- Numbers of items " << endl;
        cout << "5- Display List " << endl;
        cout << "6- Search an element." << endl;
        cout << "7- Delete first element " << endl;
        cout << "8- Delete last element " << endl;
        cout << "9- Delete a position " << endl;
        cout << "10- Delete a value " << endl;
        cout << "11- Reverse the List " << endl;
        cout << "0- EXIT " << endl;
        cout << "Enter your choice : ";
        cin >> option;
        if (option == 1) {
            cout << "Enter the Element to Insert : "; 
            int element;cin >> element;
            l.InsertFirst(element);
        }

        else if (option == 2) {
            cout << "Enter the Element to Insert : ";
            int element; cin >> element;
            l.InsertLast(element);
        }
        else if (option == 3) {
            cout << "Enter the position and element to insert : ";
            int element, pos; cin >> pos >> element;
            l.InsertPos(pos,element);
         
        }
        else if (option == 4) {
           int t;
           t= l.CountNodes();
           cout << t << endl;
        }
        else if (option == 5) {
            l.print();
        }
        else if (option == 6) {
            cout << "Enter element to search " << endl;
            int element; cin >> element;
           l.SearchNode(element);
        }
        else if (option == 7) {
            l.RemoveFirst();
        }
        else if (option == 8) {
            l.RemoveLast();
        }
        else if (option == 9) {
            cout << "Enter the position " << endl;
            int pos; cin >> pos;
            l.DeletePos(pos);
        }
        else if (option == 10) {
            cout << "Enter the element " << endl;
            int element; cin >> element;
            l.DeleteValue(element);
        }
        else if (option == 11) {
            l.ReverseLinkedList();
        }
        else if (option == 0) {
            return 0;
        }
        else {
            cout << "wrong choice" << endl;
        }
    }















}

  