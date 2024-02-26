//CÂU 04
//Nối 2 danh sách liên kết đơn A, B cho trước theo thứ tự xen kẽ tạo thành danh sách liên kết đơn C.
//Nếu 1 trong 2 danh sách kết thúc trước, danh sách kết quả C sẽ nhận tiếp giá trị của các node trong danh sách còn lại.
//
//INPUT:
//Nhập 2 danh sách liên kết đơn theo câu 1.
//
//Chú ý: 1 trong 2 danh sách hoặc cả 2 danh sách có thể là rỗng.
//
//OUTPUT
//Xuất danh sách liên kết đã nối theo yêu cầu trên cùng một dòng, mỗi giá trị cách nhau một khoảng trắng.

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* merge_alternate_lists(Node* headA, Node* headB) {
    Node* dummy = new Node(0);
    Node* current = dummy;

    while (headA != nullptr || headB != nullptr) {
        if (headA != nullptr) {
            current->next = headA;
            headA = headA->next;
            current = current->next;
        }

        if (headB != nullptr) {
            current->next = headB;
            headB = headB->next;
            current = current->next;
        }
    }

    return dummy->next;
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
    Node* currentB = nullptr;
    while (cin >> val && val != -1) {
        if (headB == nullptr) {
            headB = new Node(val);
            currentB = headB;
        } else {
            currentB->next = new Node(val);
            currentB = currentB->next;
        }
    }

    Node* headC = merge_alternate_lists(headA, headB);

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