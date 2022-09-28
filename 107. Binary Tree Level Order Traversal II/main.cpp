#include <iostream>
#include "vector"
#include "stack"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void filler(TreeNode* root, vector<vector<int>>& vec, int level) {
    if (root == nullptr) {
        return;
    } else {
        vec[level].push_back(root->val);
        level--;
        filler(root->left, vec, level);
        filler(root->right, vec, level);
        //filler(root->right);
    }
}
int depth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left = depth(root->left);
    int right = depth(root->right);
    if (left > right) {
        return left + 1;
    } else {
        return right + 1;
    }
}
vector<vector<int>> recursiveLevelOrder(TreeNode* root) {
    int d = depth(root);
    vector<vector<int>> levels(d);
    filler(root, levels, d - 1);

    return levels;
}
int main() {
    TreeNode *root = new TreeNode(12);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);
    root->left = new TreeNode(10);
    root->left->right = new TreeNode(11);
    root->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->left->left = new TreeNode(1);
    root->left->left->left->right = new TreeNode(2);
    auto v = recursiveLevelOrder(root);
    for (auto item : v) {
        for (auto it : item) {
            cout << it << "->";
        }
        cout << endl;
    }
    return 0;
}
