#include <iostream>
using namespace std;
const int Size = 100;
class Stack {
    int top;
    int arr[Size];
public:
    Stack() {
        top = -1;
    }
    void push(int element) {
        if (top == (Size - 1)) {
            cout << "stack is full" << endl;
        }
        else {

            top++;
            arr[top] = element;
        }
    }
    void pop() {
        if (top == -1) {
            cout << "stack is empty" << endl;
        }
        else {
            top--;
        }
    }
    void gettop() {
        if (top == -1) {
            cout << "stack is empty" << endl;
        }
        else {
            cout << arr[top] << endl;
        }
    }
    void print() {
        for (int i = top; i > -1; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack s;
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
