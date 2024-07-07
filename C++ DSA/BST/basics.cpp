#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this-> data =d;
        this-> left =NULL;
        this-> right =NULL;
    }

};

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

Node* insertIntoBST(Node* &root, int d){
    //base case
    if(root==NULL){
        root = new Node(d);
        return root;
    }

    if(d>root->data){
        //right part me insert krna
        root->right = insertIntoBST(root->right, d);
    }
    else{
        //left part me insert krna
        root-> left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        insertIntoBST(root, data);
        cin>>data;
    }
}

Node* minval(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxval(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deletion(Node* root, int val) {
    // base case
    if (root == NULL) {
        return root;
    }
    if (root->data == val) {
        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        else if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 children
        else {
            int mini = minval(root->right)->data;
            root->data = mini;
            root->right = deletion(root->right, mini);
            return root;
        }
    }
    else if (root->data > val) {
        // left part me jao
        root->left = deletion(root->left, val);
        return root;
    }
    else {
        // right part me jao
        root->right = deletion(root->right, val);
        return root;
    }
}

 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);

    cout<<"Printing BST"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"Printing Preorder"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Printing inorder"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Printing postorder"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"minvalue is "<<minval(root)->data<<endl;
    cout<<"maxvalue is "<<maxval(root)->data<<endl;

    root= deletion(root, 30);
    cout<<endl;

    cout<<"Printing BST"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"Printing Preorder"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Printing inorder"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Printing postorder"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"minvalue is "<<minval(root)->data<<endl;
    cout<<"maxvalue is "<<maxval(root)->data<<endl;

    return 0;
}