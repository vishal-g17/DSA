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
Node* solve(int in[], int pre[], int index, int inorderStart ,int inorderEnd, int n, map<int,int> &nodeToIndex){
    // base case
    if(index >=n || inorderStart > inorderEnd){
        return NULL;
    }
    // create a root node for element
    int element = pre[index++];
    Node* root = new Node(element);
    // find element index in inorder
    int position = nodeToIndex[element];
    // int position = findposition(in, element, n);

    // recursive call
    root->left= solve(in, pre, index, inorderStart, position-1, n, nodeToIndex);
    root->right= solve(in, pre, index, position +1, inorderEnd, n, nodeToIndex);

    return root;
}
Node* buildtree(int in[], int pre[], int n){
    int preOrderIndex=0;
    //creates nodes to index mapping
    map<int, int> nodeToIndex;
    createmapping(in, nodeToIndex, n);
    Node* ans = solve(in, pre, preOrderIndex,0, n-1, n,nodeToIndex);
    return ans;
}


// code me 2 method hai jo comment me hai usse dusri approach hai jo jada tc me hai or mapping vala optimise hai