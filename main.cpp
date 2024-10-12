#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class Stack {
private:
    Node<T>* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    T peek() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty.");
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int getSize() const {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    ~Stack() {
        clear();
    }
};

int main() {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;

    stack.clear();
    cout << "Stack size after clear: " << stack.getSize() << endl;

    system("pause");
    return 0;
}