// string longestCommonPrefix(vector<string> &arr, int n)
// {
//     string ans= "";
//     //fpr traversing all char of first str
//     for(int i=0;i<arr[0].length();i++){
//         char ch = arr[0][i];

//         bool match = true;

//         //for comparing ch with rest other strings
//         for(int j=1;j<n;j++){
//             //not match
//             if(arr[j].size() < i || ch != arr[j][i]){
//                 match = false;
//                 break;
//             }
//         }
//         if(match == false){
//             break;
//         }
//         else{
//             ans.push_back(ch);
//         }

//     }
//     return ans;
// }

//cde 2
class Trienode{
    public:
    char data ;
    Trienode* children[26];
    int childcnt;
    bool isterminal ;

    Trienode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]= NULL;
        }
        childcnt =0;
        isterminal =false;
    }
};

class Trie{
    public:
    Trienode* root;
    Trie(char ch){
        root = new Trienode(ch);
    }


    void insertUtil(Trienode* root, string word){
    //base case
    if(word.length()==0){
        root->isterminal = true;
        return;
    }

    //assumption, word will be in CAPS
    int index = word[0] - 'a';//there is no assumptioons
    Trienode* child;

    //present
    if(root->children[index] != NULL){
        child = root -> children[index];
    }
    else{
        //absent
        child = new Trienode(word[0]);
        root->childcnt++;
        root->children[index] = child;
    }

    //recursion
    insertUtil(child, word.substr(1));

}

    void insertword(string word){
        insertUtil(root,word);
    }

    void lcp(string str, string &ans){
        for(int i=0;i<str.length();i++){
            char ch = str[i];

            if(root->childcnt == 1){
                ans.push_back(ch);
                //aage badh jao
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isterminal){
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n){
    Trie *t = new Trie('\0');

    //insert all strings int trie
    for(int i=0;i<n;i++){
        t->insertword(arr[i]);
    }

    string first = arr[0];
    string ans;

    t->lcp(first,ans);
    return ans;
}

