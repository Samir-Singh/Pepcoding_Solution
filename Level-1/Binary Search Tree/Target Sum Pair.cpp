int find(Node *root, int x)
{
  if(root == NULL)
    return 0;
  if(root->data == x)
    return 1;
  if(x > root->data)
    return find(root->right, x);
  if(x < root->data)
    return find(root->left, x);
  return 0;
}
   void travelAndPrint(Node * root , Node * node , int target){

      if(node == NULL)
        return;

      travelAndPrint(root, node->left, target);

      int temp = target-node->data;
      if(node->data < temp)
        if(find(root, temp))
          cout<<node->data<<" "<<temp<<endl;

      travelAndPrint(root, node->right, target);

  }
