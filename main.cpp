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
    {    if(root->left)
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        if(root->right)
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
/*************************************given a height h give an algorithm for generating HB(0)*////////////////////////////
AvlBst* giveTreeHB(int h,int &i)
{
    if(h==-1)
        return NULL;
    else
    {
        AvlBst* head=new AvlBst(0);
        i++;
        cout<<h<<" ";
        if((h-1)>=-1)
        head->left=giveTreeHB(h-1,i);
        else
            return NULL;
        if((h-2)>=-1)
        head->right=giveTreeHB(h-2,i);
        else
            return NULL;
    }
}

/**************
AvlBst* giveTreeHB(int h,int &i)
{
    if(h==-1)
        return NULL;
    else
    {
        AvlBst* head=new AvlBst(i);
        i++;
        head->left=giveTreeHB(h-1,i);
        head->right=giveTreeHB(h-2,i);
    }
}*////////
int main()
{
    AvlBst* root=NULL;
    /*insertIntoAvl(root,10);
    insertIntoAvl(root,6);
    insertIntoAvl(root,16);
    insertIntoAvl(root,4);
    insertIntoAvl(root,9);
    insertIntoAvl(root,13);
    insertIntoAvl(root,7);
    inOrderTraversal(root);
    */
    int h,i=0;
    cin>>h;
    root=giveTreeHB(h,i);
    cout<<"c";
    inOrderTraversal(root);
    cout<<"\nN="<<i;
    return 0;
}
