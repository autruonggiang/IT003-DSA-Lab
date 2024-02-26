//CÂU 05
//Cho danh sách liên kết đơn A có thành phần dữ liệu là các số nguyên dương.
//
//Tách danh sách A thành 2 danh sách liên kết đơn B và C sao cho:
//	Danh sách B có các node chứa toàn giá trị chẳn của A
//	Danh sách C có các node chứa toàn giá trị lẻ của A.
//
//INPUT:
//Nhập danh sách liên kết đơn theo câu 1.
//
//OUTPUT
//Xuất 02 danh sách liên kết B, C trên 02 dòng. Mỗi giá trị cách nhau một khoảng trắng.

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void split_odd_even_lists(Node* headA, Node*& headB, Node*& headC) {
    Node* currentA = headA;
    Node* currentB = nullptr;
    Node* currentC = nullptr;

    while (currentA != nullptr) {
        if (currentA->data % 2 == 0) {
            if (headB == nullptr) {
                headB = new Node(currentA->data);
                currentB = headB;
            } else {
                currentB->next = new Node(currentA->data);
                currentB = currentB->next;
            }
        } else {
            if (headC == nullptr) {
                headC = new Node(currentA->data);
                currentC = headC;
            } else {
                currentC->next = new Node(currentA->data);
                currentC = currentC->next;
            }
        }

        currentA = currentA->next;
    }
}

void print_linked_list(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* headA = nullptr;
    Node* currentA = nullptr;
    int val;
    while (cin >> val && val != -1) {
        if (headA == nullptr) {
            headA = new Node(val);
            currentA = headA;
        } else {
            currentA->next = new Node(val);
            currentA = currentA->next;
        }
    }

    Node* headB = nullptr;
    Node* headC = nullptr;

    split_odd_even_lists(headA, headB, headC);

    print_linked_list(headB);

    print_linked_list(headC);

    while (headA != nullptr) {
        Node* temp = headA;
        headA = headA->next;
        delete temp;
    }

    while (headB != nullptr) {
        Node* temp = headB;
        headB = headB->next;
        delete temp;
    }

    while (headC != nullptr) {
        Node* temp = headC;
        headC = headC->next;
        delete temp;
    }

    return 0;
}