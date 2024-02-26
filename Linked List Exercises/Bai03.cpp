// CÂU 03
// Xóa các node đầu và cuối danh sách (xóa đầu trước, xóa cuối sau)
//
// INPUT:
// Nhập danh sách liên kết đơn trong câu 1.
//
// OUTPUT
// Xuất danh sách đã xóa trên cùng một dòng, mỗi giá trị cách nhau một khoảng trắng.
// Nếu trong danh sách không còn node thì không xuất.

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void removeFirst() {
        if (!head) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeLast() {
        if (!head) {
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;

    int x;
    while (true) {
        cin >> x;
        if (x == -1) {
            break;
        }
        linkedList.append(x);
    }

    linkedList.removeFirst();
    linkedList.removeLast();
    linkedList.display();

    return 0;
}