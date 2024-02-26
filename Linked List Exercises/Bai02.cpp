// CÂU 02
// Xuất tất cả các node có thành phần dữ liệu là số nguyên tố trong danh sách.
//
// INPUT:
// Nhập danh sách liên kết đơn trong câu 1.
//
// OUTPUT
// Xuất tất cả các node theo yêu cầu trên cùng một dòng, mỗi giá trị cách nhau một khoảng trắng.
// Nếu trong danh sách không có số nguyên tố thì xuất số 0.

#include <iostream>
#include <cmath> // sqrt

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

    void displayPrimes() {
        Node* current = head;
        bool hasPrimes = false;

        while (current) {
            if (isPrime(current->data)) {
                cout << current->data << " ";
                hasPrimes = true;
            }
            current = current->next;
        }

        if (!hasPrimes) {
            cout << "0";
        }

        cout << endl;
    }

private:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
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

    linkedList.displayPrimes();

    return 0;
}