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
/**********************preorder traversal*///////////////////////
void preOrder(AvlBst* root)
{
    if(!root)
        return;
    cout<<root->data<< " ";
    preOrder(root->left);
    preOrder(root->right);
}
/**************************height of avl tree*///////////////////
int heightOfAvlBst(AvlBst* root)
{
    if(!root)
        return 0;
    else return max(heightOfAvlBst(root->left),heightOfAvlBst(root->right))+1;
}
/******************differnce of heights between left and right subtree*///////////////////
int heightDifferenceAvl(AvlBst* root)
{
    if(!root->left)
        return root->right->height;
    if(!root->right)
        return root->left->height;
    else
    return abs(root->left->height-root->right->height);
}



/*************************single rotation left*/////////////////////////////////////////
AvlBst* singleRoltationLeft(AvlBst* root)
{
    AvlBst* left=root->left;
    root->left=left->right;
    left->right=root;
    left->height=max(heightOfAvlBst(left->right),heightOfAvlBst(left->left))+1;
    root->height=max(heightOfAvlBst(root->left),heightOfAvlBst(root->right))+1;
    return left;
}
/****************************single rotation right*//////////////////////////////////
AvlBst* singleRoltationRight(AvlBst* root)
{
    AvlBst* x=root->right;
    root->right=x->left;
    x->left=root;
    x->height=max(heightOfAvlBst(x->right),heightOfAvlBst(x->left))+1;
    root->height=max(heightOfAvlBst(root->left),heightOfAvlBst(root->right))+1;
    return x;
}
/***********************************rotation in right subtree of left child*///////////////////////
AvlBst* doubleRotationLeft(AvlBst* root)
{
    root->left=singleRoltationRight(root->left);
    return singleRoltationLeft(root);
}
/****************************rotation in left subtree of right *////////////////////////////
AvlBst* doubleRotationRight(AvlBst* root)
{
    root->right=singleRoltationRight(root->right);
    return singleRoltationRight(root);
}
/********************inserting into avl tree*////////////////////
void insertIntoAvl(AvlBst* &root,int data)
{
    if(!root||root->data==data)
    {
        root=new AvlBst(data);

     //   root->height=heightOfAvlBst(root);
    }
    else
        if(data<root->data)
        {
            //cout<<root->data;
            insertIntoAvl(root->left,data);
            root->left->height=heightOfAvlBst(root->left);
             if(heightDifferenceAvl(root)==2)
             {
                 if(data<root->left->data)
                    root=singleRoltationLeft(root);
                 else
                    root=doubleRotationLeft(root);
             }
        }
    else
        {
            insertIntoAvl(root->right,data);
            root->right->height=heightOfAvlBst(root->right);
             if(heightDifferenceAvl(root)==2)
             {
                 if(data>root->right->data)
                    root=singleRoltationRight(root);
                 else
                    root=doubleRotationRight(root);
             }
        }
}
int main()
{
    AvlBst* root=NULL;
    insertIntoAvl(root,4);
    insertIntoAvl(root,2);
    insertIntoAvl(root,7);
    insertIntoAvl(root,6);
    insertIntoAvl(root,5);
    insertIntoAvl(root,8);
    preOrder(root);
    cout<<"\n";
    inOrderTraversal(root);
     //cout<<root->height;
    return 0;
}
