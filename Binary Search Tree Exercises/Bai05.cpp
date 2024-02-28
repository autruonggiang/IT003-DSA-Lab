// CÂU 05
// Xóa node có giá trị khóa = x, với x nhập từ bàn phím.
//
//INPUT:
//-         Nhập cây nhị phân tìm kiếm trong câu 1.
//-         Nhập số nguyên x.
//
// OUTPUT
// Xuất cây theo thứ tự Node-Left-Right, xuất trên cùng 1 hàng, mỗi phần tử cách nhau 1 khoảng trắng.
//-         Nếu x không có trong cây, xuất cây ban đầu.
//-         Nếu x có trong cây, xuất cây đã xóa x.
//
// Lưu ý: nếu xóa node có 2 cây con, chọn phần tử thay thế là phần tử phải nhất của cây con trái.

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

int findMaxValueInLeftSubtree(TreeNode* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->value;
}

TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        root->value = findMaxValueInLeftSubtree(root->left);
        root->left = deleteNode(root->left, root->value);
    }

    return root;
}


void preOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        cout << root->value << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
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

    int valueToDelete;
    cin >> valueToDelete;

    root = deleteNode(root, valueToDelete);

    preOrderTraversal(root);
    cout << endl;

    return 0;
}