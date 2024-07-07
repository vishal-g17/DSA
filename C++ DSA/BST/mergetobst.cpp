/*************************************************************

    Following is the Binary Tree node structure:

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

// void inorder(TreeNode*root, vector<int>&in){
//     if(root==NULL){
//         return ;
//     }
//     inorder(root->left, in);
//     in.push_back(root->data);
//     inorder(root->right, in);
// }

// vector<int> mergeArray(vector<int> &a, vector<int>&b){
//     vector<int> ans(a.size()+b.size());

//     int i=0,j=0;
//     int k=0;
//     while(i<a.size() && j<b.size()){
//         if(a[i]<b[j]){
//             ans[k++]= a[i];
//             i++;
//         }

//         else{
//             ans[k++]= b[j];
//             j++;
//         }
//     }

//     while (i<a.size()){
//         ans[k++]=a[i];
//         i++;
//     }
//     while (j<b.size()){
//         ans[k++]=b[j];
//         j++;
//     }
//     return ans;
// }

// TreeNode* inordertobst(int s, int e, vector<int>& in){
//     //base case
//     if(s>e){
//         return NULL;
        
//     }
    
//     int mid= (s+e)/2;
//     TreeNode* root = new TreeNode(in[mid]);
//     root->left = inordertobst(s,mid-1,in);
//     root->right = inordertobst(mid+1,e,in);
//     return root;
// }



// TreeNode*mergeBST(TreeNode *root1, TreeNode *root2)
// {
//     //steo to store inorder
//     vector<int> bst1, bst2;
//     inorder(root1, bst1);
//     inorder(root2, bst2);

//     vector<int> mergeArray = mergeArray(bst1, bst2);

//     int s=0, e= mergeArray.size()-1;
//     return inordertobst(s,e, mergeArray);

// } 




//ptani is cod eme kya ho gya chl hi nhi rha hai


//code 2

void convertIntoSortedDLL(TreeNode<int> *root, TreeNode<int>* &head){
    //base case
    if(root==NULL){
        return NULL;
    }

    convertIntoSortedDLL(root->right, head);
    root->right = head;

    if(head != NULL){
        head->left = root;
    }
    heat = root;

    convertIntoSortedDLL(root->left, head);
}

TreeNode<int> mergeLL(TreeNode<int> * head1, TreeNode<int>* head2){
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1 ->data < head2 -> data){
            if(head==NULL){
                head = head1;
                tail= head1;
                head1= head1->right;
            }
            else{
                tail->right= head1;
                head1->right = tail;
                tail = head1;
                head1 = head1->right;
            }
        }

        else{
            if(head ==NULL){
                head = head2;
                tail = head2;
                head1 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail= head2;
                head2= head2->right;
            }
        }
    }

    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail=head;
        head1= head1->right;
    }

    while(head2 != NULL){
        tail->right= head2;
        head2 ->left = tail;
        tail= head;
        head2 = head2->right;
    }

    return head;
}

int cntnodes(TreeNode<int> *head){
    int cnt=0;
    TreeNode<int>* temp = head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}

TreeNode<int> * sortedtobst(TreeNode<int> * &head, int n){
    //basecase
    if(n<= 0 || root ==NULL){
        return NULL;
    }

    TreeNode<int> *left = sortedtobst(head, n/2);

    TreeNOde<int> *root = head;
    root->left = left;
    head= head->next;

    root->right = sortedtobst(head, n- n/2 -1);

    return root;
}



TreeNode<int>*mergeBST(TreeNode *root1, TreeNode *root2){
    TreeNode<int> *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1 ->left = NULL;

    TreeNode<int> *head2 =NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    TreeNode<int>* head = mergeLL(head1, head2);

    retrun sortedtobst(head, cntNodes(head));
}






















