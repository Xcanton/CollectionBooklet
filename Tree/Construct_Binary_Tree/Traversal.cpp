#include <vector>
#include "../Definition.hpp""


std::vector<int> ans;

// 前序遍历
void preorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    ans.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
}

// 中序遍历
void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}

// 后序遍历
void postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    ans.push_back(root->val);
}

int main() {
    return 0;
}