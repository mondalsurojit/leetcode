/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void preorder(struct TreeNode* root, int** index) {
    if (root == NULL)
        return;
    **index = root->val;
    (*index)++;
    preorder(root->left, index);
    preorder(root->right, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* arr = malloc(sizeof(int) * (*returnSize));
    int* index = arr;
    preorder(root, &index); //Here I am doing pass by reference (address of index), as if I do pass by value a copy of index will be passed and changes will be done on the copy of the value of index, and not on the original value of index
    return arr;
}