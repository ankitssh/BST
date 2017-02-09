#include <iostream>

using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;

};

BstNode *root=NULL;

BstNode *CreateNewNode(int idata)
{

    BstNode *newnode=new BstNode();
    newnode->data=idata;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;

}

BstNode * insertNode(BstNode *node,int idata)
{
    if(node==NULL)
    {

        node=CreateNewNode(idata);

    }
    else if(idata<=node->data)
    {
        node->left=insertNode(node->left,idata);
    }

    else{

        node->right=insertNode(node->right,idata);

    }
    return node;


}

int maxElement(BstNode *node)
{
    if(node->right==NULL)
    {
        return node->data;


    }
    else
        maxElement(node->right);

}
bool searchData(BstNode *node,int idata)
{



    if(node==NULL)
        return false;
    else if(node->data==idata)
        return true;
    else if(idata<node->data)
        return searchData(node->left,idata);
    else
         return searchData(node->right,idata);
}


void Inoder(BstNode *node)
{

    if(node==NULL)
        return;
    else{


        Inoder(node->left);
        cout<<node->data<<endl;
        Inoder(node->right);

    }

}

void Preorder(BstNode *node)
{

    if(node==NULL)
        return;
    else{


    cout<<node->data<<endl;
        Preorder(node->left);

        Preorder(node->right);

    }

}


int main()
{

    root=insertNode(root,500);
   root= insertNode(root,300);
   root= insertNode(root,700);
    root=insertNode(root,200);
   root= insertNode(root,800);
   root= insertNode(root,900);
   root= insertNode(root,600);
   root= insertNode(root,10);
 root= insertNode(root,1033333);
   // cout<<searchData(root,1)<<endl;
   Preorder(root);
   cout<<"Min Element: "<<maxElement(root)<<endl;


    return 0;
}
