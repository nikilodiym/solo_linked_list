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
class LinkedList {
protected:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void addToHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void addToTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteFromHead() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            cout << "List is empty." << endl;
        }
    }

    void deleteFromTail() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* current = head;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    void deleteAll() {
        while (head) {
            deleteFromHead();
        }
    }

    void show() const {
        Node<T>* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        deleteAll();
    }
};

int stringToInt(const string& str) {
    int number = 0;
    for (char ch : str) {
        if (isdigit(ch)) {
            number = number * 10 + (ch - '0');
        }
        else {
            throw invalid_argument("Invalid input, not a number.");
        }
    }
    return number;
}

int main() {
    LinkedList<int> list;
    string command;
    string input;

    while (true) {
        cout << "Enter a command (or 'exit' to quit):" << endl;
        cout << "1. Add to Head" << endl;
        cout << "2. Add to Tail" << endl;
        cout << "3. Delete from Head" << endl;
        cout << "4. Delete from Tail" << endl;
        cout << "5. Delete All" << endl;
        cout << "6. Show" << endl;
        cout << "7. Exit" << endl;

        getline(cin, command);

        if (command == "1") {
            cout << "Enter value to add to head: ";
            getline(cin, input);
            try {
                int value = stringToInt(input);
                list.addToHead(value);
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
        }
        else if (command == "2") {
            cout << "Enter value to add to tail: ";
            getline(cin, input);
            try {
                int value = stringToInt(input);
                list.addToTail(value);
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
        }
        else if (command == "3") {
            list.deleteFromHead();
        }
        else if (command == "4") {
            list.deleteFromTail();
        }
        else if (command == "5") {
            list.deleteAll();
            cout << "All elements deleted." << endl;
        }
        else if (command == "6") {
            list.show();
        }
        else if (command == "7" || command == "exit") {
            break;
        }
        else {
            cout << "Invalid command." << endl;
        }
    }

	system("pause");
    return 0;
}