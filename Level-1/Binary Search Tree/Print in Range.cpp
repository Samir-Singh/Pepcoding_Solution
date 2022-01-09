void pir(Node* root, int d1, int d2)
{
    if(root == NULL)
        return;

    if(d1 < root->data && d2 < root->data)
        pir(root->left, d1, d2);
    else if(d1 > root->data && d2 > root->data)
        pir(root->right, d1, d2);
    else
    {
        pir(root->left, d1, d2);
        cout<<root->data<<endl;
        pir(root->right, d1, d2);
    }
}
