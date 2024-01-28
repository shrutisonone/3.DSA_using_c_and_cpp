#include<stdio.h>
#include<conio.h>

struct BinaryTree
{
  int data;
  struct BinaryTree *left;
  struct BinaryTree *right;
};

int findelement(struct BinaryTree *root,int value)
{
    if(!root)
     return NULL;
    else
    {
        if(root->data == value)
        {
            return value;
        }
        else 
        {
            int temp = findelement(root->left ,value);
                if(temp != 0)
                return temp;
                else
                return findelement(root->right , value);
        }
    }
    return 0;
}