int deleteBinaryTree(struct deleteBinaryTree *root)
{
    if(root == NULL)
     return 0;
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    free(root);
}