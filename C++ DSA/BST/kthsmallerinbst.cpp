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

int solve(BinaryTreeNode<int>* root,int  &i, int k)
{
    //base case
    if(root == NULL ){
        return -1;
    }
    //left me
    int left = solve(root->left, i ,k);
    if(left != -1 ){
        return left;
    }
    //node me
    i++;
    if(i==k){
        return root->data;
    }
    //right
    return solve(root->right, i,k);

}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i=0;
    int ans = solve(root , i, k);
    return ans;
}