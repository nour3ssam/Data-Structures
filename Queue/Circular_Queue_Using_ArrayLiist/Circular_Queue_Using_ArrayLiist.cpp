#include <iostream>
using namespace std;
class Queue {
    int rear;
    int count;
    int front;
    int *arr;
    int maxsize;
public:
    Queue(int Size) {
        maxsize = Size;
        arr = new int[Size];
        front = 0;
        rear = Size-1;
        count = 0;
    }

    void Insert(int element) {
        if (count == maxsize) {
            cout << "queue is full" << endl;
        }
        else {
            rear = (rear + 1) % maxsize;
            arr[rear] = element;
            count++;
        }
    }

    void pop() {
        if (count == 0) {
            cout << "queue is empty" << endl;
        }
        else {
            front = (front + 1) % maxsize;
            count--;

        }
    }

    void GetFront() {
        if (count == 0) {
            cout << "queue is empty" << endl;
        }
        else {
            cout << arr[front] << endl;
        }
    }

    void Print() {
        for (int i = front; i != rear ; i = (i + 1) % maxsize) {
            cout << arr[i] << " ";
        }
        cout << arr[rear];
        cout << endl;
    }

};
int main() {
    Queue q(5);
    q.Insert(2);
    q.Insert(4);
    q.Insert(6);
    q.Insert(8);
    q.Insert(10);
    q.Print();
    q.Insert(12);
    q.pop();
    q.Print();
    q.GetFront();

}
