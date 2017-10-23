#include <iostream>

using namespace std;
/*********************Avl tree defination*/////////////////////
class AvlBst{
public:
    int data;
    int height;
    AvlBst* left;
    AvlBst* right;
    AvlBst(int data)
    {
        this->height=0;
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};
/********************inserting into avl tree*////////////////////
void insertIntoAvl(AvlBst* &root,int data)
{
    if(!root||root->data==data)
    {
        root=new AvlBst(data);
    }
    else
        if(data<root->data)
        insertIntoAvl(root->left,data);
    else
        insertIntoAvl(root->right,data);
}
/**************************inOrder traversal of avl tree*//////////////////////
void inOrderTraversal(AvlBst* root)
{
    if(!root)
        return;
    else
    {
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
}
/**************************height of avl tree*///////////////////
int heightOfAvlBst(AvlBst* root)
{
    if(!root)
        return 0;
    else
        return max(heightOfAvlBst(root->left),heightOfAvlBst(root->right))+1;
}
/******************differnce of heights between left and right subtree*///////////////////
int heightDifferenceAvl(AvlBst* root)
{
    return abs(heightOfAvlBst(root->left)-heightDifferenceAvl(root->right));

}

int main()
{
    AvlBst* root=NULL;
    insertIntoAvl(root,10);
    insertIntoAvl(root,6);
    insertIntoAvl(root,16);
    insertIntoAvl(root,4);
    insertIntoAvl(root,9);
    insertIntoAvl(root,13);
    insertIntoAvl(root,7);
    inOrderTraversal(root);
    return 0;
}
