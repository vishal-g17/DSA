#include<bits/stdc++.h>
using namespace std;

class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isterminal;

    //constructor
    Trienode(char ch){
        data = ch;
        for(int i=0; i<26;i++){
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class Trie{
    public:
    Trienode* root;

    Trie (){
        root= new Trienode('\0');
    }

    void insertUtil(Trienode* root, string word){
        //base case
        if(word.length()==0){
            root->isterminal = true;
            return;
        }

        //assumption, word will be in CAPS
        int index = word[0] - 'A';
        Trienode* child;

        //present
        if(root->children[index] != NULL){
            child = root -> children[index];
        }
        else{
            //absent
            child = new Trienode(word[0]);
            root->children[index] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));

    }

    void insertword(string word){
        insertUtil(root,word);
    }


    bool search(Trienode* root, string word){
        //base case
        if(word.length()==0){
            return root->isterminal;
        }

        //asumption of CAPS
        int index = word[0]-'A';
        Trienode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            return false;
        }

        //recursion
        return search(child, word.substr(1));
    }

    bool searchword(string word){
        return search(root, word);
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    // Trie t;
    // t.insertword("abcd");

    Trie *t = new Trie();

    t->insertword("abcd");
    cout<<"present or not"<<endl;
    cout<<t->searchword("abcd")<<endl;

    
  
    return 0;
}