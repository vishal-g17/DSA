/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorder(TreeNode<int>* root, vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* inordertobst(int s, int e, vector<int>& in){
    //base case
    if(s>e){
        return NULL;
        
    }
    
    int mid= (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inordertobst(s,mid-1,in);
    root->right = inordertobst(mid+1,e,in);
    return root;
}


TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderVal;
    //store inorder->sorted values
    inorder(root, inorderVal);

    return inordertobst(0, inorderVal.size()-1,inorderVal);
}
