// CÂU 01
// Tạo cây nhị phân tìm kiếm với mỗi node là một số nguyên dương >=1.
//
// INPUT:
// Nhập lần lượt các giá trị x, thêm x vào cây. Nhập x= -1 để kết thúc quá trình nhập.
//
// OUTPUT
// Xuất ra kết quả duyệt cây theo thứ tự tăng dần trên cùng một dòng, mỗi giá trị cách nhau một khoảng trắng.

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

void inOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->value << " ";
        inOrderTraversal(root->right);
    }
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

    inOrderTraversal(root);
    cout << endl;

    return 0;
}