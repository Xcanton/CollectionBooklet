/**
 * 
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 * 
 * Given two integer arrays inorder and postorder where inorder is the inorder traversal 
 * of a binary tree and postorder is the postorder traversal of the same tree, 
 * construct and return the binary tree.
 * 
 */


#include "../Definition.hpp"
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    int post_idx;
    unordered_map<int, int> idx_map;
public:
    TreeNode* ConstructNode(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder) {
        if(in_left > in_right) {
            return nullptr;
        }

        int current_node_val = postorder[post_idx];
        TreeNode* current_node = new TreeNode(current_node_val);

        int index = idx_map[current_node_val];
        post_idx--;
        current_node->left = ConstructNode(in_left, index-1, inorder, postorder);
        current_node->right = ConstructNode(index+1, in_right, inorder,postorder);
        return current_node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_idx = (int)postorder.size() - 1;

        int idx = 0;
        for (auto& val : inorder){
            idx_map[val] = idx++;
        }
        return ConstructNode(0, (int)inorder.size() - 1, inorder, postorder);
    }
};