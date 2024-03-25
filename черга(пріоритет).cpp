#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include"x64/Debug/черга(пріоритет).tlog/doctest.h"

using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enQueue(int x, int p) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->priority = p;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
        }
        else if (p > front->priority) {
            newNode->next = front;
            front = newNode;
        }
        else {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority >= p) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deQueue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return;
        }
        else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return -1;
        }
        else {
            return front->data;
        }
    }
};

TEST_CASE("Test 1: Insert elements with different priorities") {
    PriorityQueue q;
    q.enQueue(10, 2);
    q.enQueue(20, 1);
    q.enQueue(15, 3);
    q.enQueue(30, 2);
    CHECK(q.getFront() == 15);
    q.deQueue();
    CHECK(q.getFront() == 10);
    q.deQueue();
    CHECK(q.getFront() == 30);
    q.deQueue();
    CHECK(q.getFront() == 20);
    q.deQueue();
    CHECK(q.isEmpty() == true);
}

TEST_CASE("Test 2: Insert elements with the same priority") {
    PriorityQueue q;
    q.enQueue(10, 1);
    q.enQueue(20, 1);
    q.enQueue(15, 1);
    q.enQueue(30, 1);
    CHECK(q.getFront() == 10);
    q.deQueue();
    CHECK(q.getFront() == 20);
    q.deQueue();
    CHECK(q.getFront() == 15);
    q.deQueue();
    CHECK(q.getFront() == 30);
    q.deQueue();
    CHECK(q.isEmpty() == true);
}

TEST_CASE("Test 3: Insert elements with decreasing priorities") {
    PriorityQueue q;
    q.enQueue(10, 3);
    q.enQueue(20, 2);
    q.enQueue(15, 1);
    q.enQueue(30, 0);
    CHECK(q.getFront() == 10);
    q.deQueue();
    CHECK(q.getFront() == 20);
    q.deQueue();
    CHECK(q.getFront() == 15);
    q.deQueue();
    CHECK(q.getFront() == 30);
    q.deQueue();
    CHECK(q.isEmpty() == true);
}

TEST_CASE("Test 4: Try to dequeue from an empty queue") {
    PriorityQueue q;
    q.deQueue();
    CHECK(q.isEmpty() == true);
}

TEST_CASE("Test 5: Get front from an empty queue") {
    PriorityQueue q;
    CHECK(q.getFront() == -1);
    CHECK(q.isEmpty() == true);
}
TEST_CASE("Test 6: Printing queue") {
    PriorityQueue q;

    q.enQueue(10, 2);
    q.enQueue(20, 1);
    q.enQueue(15, 3);
    q.enQueue(30, 2);

    cout << "Priority Queue elements are: ";
    while (!q.isEmpty()) {
        cout << q.getFront() << " ";
        q.deQueue();
    }
    cout << endl;

}


