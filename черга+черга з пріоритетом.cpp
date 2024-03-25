#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "x64/Debug/черга+че.c72bfbb4.tlog/doctest.h"
#include<iostream>
using namespace std;

const int MAX_SIZE = 100;
class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    void enQueue(int x) {
        if (isFull()) {
            cout << "Error: Queue is full\n";
            return;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = x;
    }

    void deQueue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return;
        }
        else if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return -1;
        }
        else {
            return arr[front];
        }
    }

    void printQueue(Queue q) {
        if (q.isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        else {
            cout << "Queue elements are: ";
            int i;
            for (i = q.front; i != q.rear; i = (i + 1) % MAX_SIZE) {
                cout << q.arr[i] << " ";
            }
            cout << q.arr[i] << "\n";
        }
    }
};

TEST_CASE("Testing enqueue") {
    Queue q;
    q.enQueue(5);
    q.enQueue(10);
    q.enQueue(15);
    REQUIRE(q.getFront() == 5);
}

TEST_CASE("Testing dequeue") {
    Queue q;
    q.enQueue(5);
    q.enQueue(10);
    q.deQueue();
    REQUIRE(q.getFront() == 10);
}

TEST_CASE("Testing isFull") {
    Queue q;
    for (int i = 0; i < 100; i++) {
        q.enQueue(i);
    }
    CHECK(q.isFull());
}

TEST_CASE("Testing isEmpty") {
    Queue q;
    CHECK(q.isEmpty());
    q.enQueue(5);
    CHECK_FALSE(q.isEmpty());
}



/*int main() {
    Queue q;
    int n;

   
    
    // Додавання чисел в чергу
    cout << "Enter 5 numbers to enqueue:\n";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        q.enQueue(n);
    }

    // Виведення елементів черги та їх видалення
    cout << "\nDequeuing elements...\n";
    while (!q.isEmpty()) {
        cout << q.getFront() << " ";
        q.deQueue();
    }

    return 0;
}*/

