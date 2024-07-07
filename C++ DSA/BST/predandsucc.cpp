/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    //find key
    TreeNode* temp = root;
    int pred= -1;
    int succ = -1;

    while(temp->data != key){
        if(temp->data >key){
            succ = temp ->data;
            temp = temp ->left;
        }
        else{
            pred = temp ->data;
            temp = temp ->right;
        }
    }

    //pred & succ

    //pred
    TreeNode* lefttree= temp->left;
    while(lefttree != NULL ){
        pred = lefttree ->data;
        lefttree = lefttree->right;
    }

    //succ
    TreeNode* righttree = temp->right;
    while(righttree != NULL){
        succ = righttree->data;
        righttree = righttree->left;
    }

    // pair<int,int>ans = make_pair(pred,succ);
    // return ans ;
    // or
    return {pred,succ};

}