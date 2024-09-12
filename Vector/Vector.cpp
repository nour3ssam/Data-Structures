#include <iostream>
using namespace std;
 class Vector {
private:
    int* arr;
    int size;
    int index;
public:
    Vector() {
        arr = new int;
        size = 0;
        index = 0;
    }
    Vector(int s) {
        arr = new int[s];
        size = s;
        index = 0;
    }

    void ReSize() {
        int newSize = 0;
        if (size == 0) {
            newSize = 1;
        }
        else {
            newSize = size + 1;
        }
        int* temp = new int[newSize];
        for (int i = 0; i < index; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;// delete the previous array
        arr = temp;
        size = newSize;
    }

    void Push(int element) {
        if (index == size) {
            ReSize();
        }
        arr[index] = element;
        index++;
    }

    void Clear() {
        index = 0;
    }

    void Print() {
        for (int i = 0; i < index; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Push(int element, int pos) {
        if (index == size) {
            ReSize();
        }
        for (int i = index; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = element;
        index++;
    }

    int Get(int idx) {
        if (idx < index) {
            return arr[idx];
        }
        else {
            return -1;
        }
    }

    int GetSize() {
        return index;
    }

    void Update(int pos,int element) {
        arr[pos] = element;
    }

};
 
int main(){
  Vector v(6);
   v.Push(1);
   v.Push(2);
   v.Push(4);
   v.Push(5, 1);
   v.Push(6);
   v.Print();
   v.Update(2, 1);
   v.Print();
   cout << v.Get(2) << endl;
   cout << v.GetSize() << endl;
   v.Clear(); 
}

