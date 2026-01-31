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
void inorder(struct TreeNode* root, int** index) {
    if (root == NULL)
        return;
    inorder(root->left, index);
    **index = root->val;
    (*index)++;
    inorder(root->right, index);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* arr = malloc(sizeof(int) * (*returnSize));
    int* index = &arr[0]; // same as arr
    inorder(root, &index);
    return arr;
}