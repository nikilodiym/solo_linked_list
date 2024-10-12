#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        DeleteAll();
    }

    void AddToHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void AddToTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void DeleteFromHead() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void DeleteFromTail() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next && current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    void DeleteAll() {
        while (head) {
            DeleteFromHead();
        }
    }

    void Show() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

protected:
    Node* head;
};

int main() {
    SinglyLinkedList list;
    list.AddToHead(1);
    list.AddToHead(2);
    list.AddToHead(3);
    list.AddToHead(4);
    list.AddToHead(5);
    list.AddToTail(6);
    list.AddToTail(7);
    list.AddToTail(8);
    list.AddToTail(9);
    list.AddToTail(10);
    list.Show();

    list.DeleteFromHead();
    list.Show();

    list.DeleteFromTail();
    list.Show();

    system("pause");
    return 0;
}