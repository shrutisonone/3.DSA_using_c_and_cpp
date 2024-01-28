int sizeofBTusing_level_order(struct BinaryTree*root)
{
   struct BinaryTree *temp;

   if(!root)
   return -1;

   struct Queue *Q= createQueue();
   enQueue(Q,root);
   int count=0;

   while(!isEmpty(Q))
   {
     temp=deQueue(Q);
     count++;
    
    if(temp->left)
    {
        enQueue(Q,root->left);
    }
    if(temp->right)
    {
        enQueue(Q,root->right);
    }
    deleteQueue(Q);
    return count;
   }
}