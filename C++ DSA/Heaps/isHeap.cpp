int countnode(struct Node* root){
    //base case
    if(root == NULL){
        return 0;
    }
    int ans = 1+ countnode(root->left) + countnode(root->right);
    return ans;
}

bool iscbt(struct Node* root, int index , int cnt){
    if(root == NULL){
        return true;
    }
    if(index>= cnt){
        return false;
    }
    else{

    bool left = iscbt(root->left, 2*index+1, cnt);
    bool right = iscbt(root->right, 2*index +2, cnt); 
    return (left && right);      
    }
}

bool isMaxOrder(struct Node* root){
    if(root->left == NULL && root->right ==NULL){
        return true;
    }
    if(root->right == NULL){
        return (root-> data > root->left->data);
    }
    else(
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
 
    )
}


bool isheap(struct Node* tree){
    int index =0;
    int totalcnt = countnode(tree);
    if(iscbt(tree, index, totalcnt) && isMaxOrder(tree)){
        return true;
    }
    else{
        return false;
    }
}