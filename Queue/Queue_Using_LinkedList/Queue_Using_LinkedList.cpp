#include <iostream>
using namespace std;
class QueueLinkedList {
	struct Node {
		int item;
		Node* next;
	};
	Node* front, * rear;
	int count;

public:
	QueueLinkedList() {
		front = rear = NULL;
		count = 0;
	}

	void Insert(int element) {
		Node* newptr = new Node;
		newptr->item = element;
		newptr->next = NULL;
		if (count == 0) {
			front = rear = newptr;
		}
		else {
			rear->next = newptr;
			rear = newptr;

		}
		count++;
	}

	void pop() {
		if (count == 0) {
			cout << "Nothing to delete " << endl;
		}
		else {
			if (count == 1) {
				front = rear = NULL;
			}
			else {
				Node* temp = front;
				front = front->next;
				temp->next = NULL;
				delete temp;
			}
			count--;
		}
	}

	void GetFront() {
		if (count == 0) {
			cout << "Queue is Empty " << endl;
		}
		else {
			cout << front->item << endl;
		}
	}

	void print(){
		if (count == 0) {
			cout << "Queue is Empty " << endl;
		}
		Node* cur = front;
		while (cur != NULL){
			cout << cur->item << " ";
			cur = cur->next;
		}
		cout << endl;
	}

	void Clear() {
		if (count == 0) {
			cout << "already the Queue is empty " << endl;
		}
		else {
			Node* cur = front;
			while (front != NULL) {
				cur = front;
				front = front->next;
				delete cur;
			}
			rear = NULL;
			count = 0;
		}
	}

};
int main(){
	QueueLinkedList q;
	q.Insert(2);
	q.Insert(4);
	q.Insert(6);
	q.Insert(8);
	q.GetFront();
	q.print();
	q.pop();
	q.print();
	q.Clear();
	q.Clear();
	q.print();
	
}
