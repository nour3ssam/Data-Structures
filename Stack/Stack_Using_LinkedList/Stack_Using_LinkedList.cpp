#include <iostream>
using namespace std;
class LinkStack {
    struct node {
        int item;
        node* next;
    };
    node* top;
public:
    LinkStack() {
        top = NULL;
    }
    void push(int element) {
        node* newptr = new node;
        newptr->item = element;
        newptr->next = top;
        top = newptr;
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack is Empty" << endl;

        }
        else {
            node* temp = new node;
            temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }
    void gettop() {
        if (top == NULL) {
            cout << "stack is empty" << endl;

        }
        else {
            cout << top->item << endl;
        }
    }
    void print() {
       node *cur = top;
        while (cur != NULL) {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};
int main() {
    LinkStack s;
    int option = 0;
    int element;
    while (1) {
        cout << "Enter 1 to push: " << endl; cout << "Enter 2 for pop:" << endl;;
        cout << "Enter 3 for display:" << endl; cout << "Enter 4 to get top " << endl; cout << "Enter 5 for exit" << endl;
        cout << "Enter option: " << endl;
        cin >> option;
        if (option == 1) {
            cout << "Enter element to push : ";
            cin >> element;
            s.push(element);
        }
        else if (option == 2) {
            s.pop();
        }
        else if (option == 3) {
            s.print();
        }
        else if (option == 4) {
            s.gettop();
        }
        else if (option == 5) {
            return 0;
        }
        else {
            cout << "wrong choice" << endl;
        }
    }
}
