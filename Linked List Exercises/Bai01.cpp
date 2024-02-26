// CÂU 01
// Tạo danh sách liên kết đơn với thành phần dữ liệu của mỗi node là một số nguyên dương >=1.
//
// INPUT:
// Nhập lần lượt các giá trị x, thêm x vào danh sách. Nhập x= -1 để kết thúc quá trình nhập.
//
// OUTPUT
//Xuất tất cả node trong danh sách liên kết trên cùng một dòng, mỗi giá trị cách nhau một khoảng trắng.

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

    linkedList.display();

    return 0;
}