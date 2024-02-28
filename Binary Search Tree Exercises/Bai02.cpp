// CÂU 02
// Xuất cây theo từng mức (mức của node gốc là 0)
//
// INPUT:
// Nhập cây nhị phân tìm kiếm trong câu 1.
//
// OUTPUT
// Xuất các node trên cây theo từng mức.
//-         Mỗi giá trị cách nhau 1 khoảng trắng.
//
//-         Mỗi mức nằm trên 1 dòng.

#include <iostream>
#include <queue>

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

void printLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();
            
            cout << current->value << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;
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

    printLevelOrder(root);

    return 0;
}