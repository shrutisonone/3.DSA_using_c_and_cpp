int sizeofBinaryTree_recur(struct BinaryTree *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return sizeofBinaryTree((root->left)+sizeofBinaryTree_recur(root->right));
    }
}