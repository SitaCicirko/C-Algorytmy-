#include <iostream>

using namespace std;

const int MAX_SIZE = 1000000;

class Queue {
private:
    int front, rear;
    int arr[MAX_SIZE];
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue overflow\n";
        }
        else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            arr[rear] = x;
        }
    }

    int dequeue() {
        int x;
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return -1;
        }
        else {
            x = arr[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            }
            else {
                front++;
            }
        }
        return x;
    }
};

int main() {
    Queue zuzia;
    Queue antek;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0) {
            zuzia.enqueue(x);
        }
        else {
            antek.enqueue(x);
        }
    }

    while (!zuzia.isEmpty()) {
        cout << zuzia.dequeue() << " ";
    }
    cout << endl;
    while (!antek.isEmpty()) {
        cout << antek.dequeue() << " ";
    }

    return 0;
}
