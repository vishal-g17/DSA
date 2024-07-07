#include<iostream>
#include<map>
using namespace std;
struct Node
{
  int data;
  Node* left;
  Node* right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}  //constructor for node
};

// int findposition(int in[], int element, int n){
//         for(int i=0;i<n;i++){
//             if(in[i]==element){
//                 return i;
//             }
//         }
//         return -1;
//     }

void createmapping(int in[], map<int,int> nodeToIndex, int n){
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]]=i;
        }
    }
Node* solve(int in[], int post[], int index, int inorderStart ,int inorderEnd, int n, map<int,int> &nodeToIndex){
    // base case
    if(index <0 || inorderStart > inorderEnd){
        return NULL;
    }
    // create a root node for element
    int element = post[index--];
    Node* root = new Node(element);
    // find element index in inorder
    int position = nodeToIndex[element];
    // int position = findposition(in, element, n);

    // recursive call in postorder and inorder we make first right sub tree
    root->right= solve(in, post, index, position +1, inorderEnd, n, nodeToIndex);
    root->left= solve(in, post, index, inorderStart, position-1, n, nodeToIndex);

    return root;
}
Node* buildtree(int in[], int post[], int n){
    int postOrderIndex=n-1;
    //creates nodes to index mapping
    map<int, int> nodeToIndex;
    createmapping(in, nodeToIndex, n);
    Node* ans = solve(in, post, postOrderIndex,0, n-1, n);
    return ans;
}


// code me 2 method hai jo comment me hai usse dusri approach hai jo jada tc me hai or mapping vala optimise hai