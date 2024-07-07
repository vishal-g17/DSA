#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool isbst(BinaryTreeNode<int> *root, int min ,int max){
    //base case
    if(root==NULL){
        return true;
    }
    if(root->data >= min && root-> data <= max){
        bool left = isbst(root->left, min , root-> data);
        bool right = isbst(root->right, root ->data, max);
        return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isbst(root, INT_MIN, INT_MAX);
}