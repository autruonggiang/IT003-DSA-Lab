// CÂU 04
// Đếm tất cả các node nằm ở mức <= mức k với k nhập từ bàn phím. (mức của node gốc là 0)
//
// INPUT:
//-         Nhập cây nhị phân tìm kiếm trong câu 1.
//
//-         Nhập số nguyên k>=0 và k<=h-1 (với h là chiều cao của cây)
//
// OUTPUT
//-         Số nút thỏa yêu cầu.

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

int countNodesAtLevel(TreeNode* root, int level, int k) {
    if (root == nullptr) {
        return 0;
    }

    if (level <= k) {
        return 1 + countNodesAtLevel(root->left, level + 1, k) + countNodesAtLevel(root->right, level + 1, k);
    }

    return 0;
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

    int k;
    cin >> k;

    int result = countNodesAtLevel(root, 0, k);
    cout << result << endl;

    return 0;
}