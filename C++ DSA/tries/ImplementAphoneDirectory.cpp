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
        int index = word[0] - 'a';
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

    void printSuggestions(Trienode* curr , vector<string>&temp, string prefix){
        if(curr ->isterminal){
            temp.push_back(prefix);

            //why we removed return keyword from here ?
        }

        for(char ch = 'a';ch <= 'z';ch++){
            Trienode* next = curr ->children[ch- 'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>>getSuggestions(string str){
        Trienode* prev = root;
        vector<vector<string>>output;
        string prefix= "";

        for(int i=0;i<str.length();i++){
            char lastch = str[i];

            prefix.push_back(lastch);

            //check for lastch
            Trienode* curr = prev->children[lastch - 'a'];

            //if not found
            if(curr ==NULL){
                break;
            }

            //if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev= curr;
        }
        return output;
    }

};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //creation of trie
    Trie *t = new Trie();

    //insert all contact in trie
    for(int i=0;i<contactList.size();i++){
        string str = contactList[i];
        t->insertword(str);
    }

    //return ans;
    return t->getSuggestions(queryStr);
}