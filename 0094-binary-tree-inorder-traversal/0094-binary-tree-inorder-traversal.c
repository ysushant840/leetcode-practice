
void inorder(struct TreeNode* root, int* arr, int* size) {
    if (root == NULL)
        return;

    inorder(root->left, arr, size);
    arr[(*size)++] = root->val;
    inorder(root->right, arr, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // Max 100 nodes
    *returnSize = 0;

    inorder(root, result, returnSize);

    return result;
}