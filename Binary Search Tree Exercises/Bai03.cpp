// CÂU 03
// Xuất tất cả các node có tổng số node cây con trái bằng tổng số node cây con phải.
// (không tính các node không có cây con)
//
// INPUT:
// Nhập cây nhị phân tìm kiếm trong câu 1.
//
// OUTPUT
// Xuất tất cả các node theo yêu cầu trên cùng một dòng theo thứ tự tăng dần, mỗi giá trị cách nhau một khoảng trắng.
// Nếu trong cây không có node nào thoả yêu cầu thì xuất số 0.

#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* insertNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void outputNodes(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    if (leftCount == rightCount && leftCount > 0) {
        cout << root->value << " ";
    }

    outputNodes(root->left);
    outputNodes(root->right);
}

int main() {
    TreeNode* root = nullptr;

    int x;
    while (true) {
        cin >> x;
        if (x == -1) {
            break;
        }
        root = insertNode(root, x);
    }

    outputNodes(root);
    cout << endl;

    return 0;
}