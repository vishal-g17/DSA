#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    /*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/

// bool searchInBST(BinaryTreeNode<int> *root, int x) {
//     //base case
//     if(root->data ==x){
//         return true;
//     }
//     if(root==NULL){
//         return false;
//     }

//     if(root->data >x){
//         //left partr me
//         return searchInBST(root->left, x);
//     }
//     else{
//         //right part me
//         return searchInBST(root->right, x);
//     }

// }


//code 2 by iterative for not getting TLE
bool searchInBST(BinaryTreeNode<int> *root, int x){
    BinaryTreeNode<int> *temp = root;

    while(temp != NULL){
        if(temp ->data ==x){
            return true;
        }
        if(temp -> data >x){
            temp = temp ->left;
        }

        else{
            temp =temp->right;
        }
    }
    return false;
}
 

    return 0;
}