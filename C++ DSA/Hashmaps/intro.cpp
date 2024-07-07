#include<bits/stdc++.h>
using namespace std;

 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    //creation
    unordered_map<string, int>m;

    //insertion

    //1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    //2
    pair<string, int> pair2 = make_pair("love", 2);
    m.insert(pair2);

    //3
    m["mera"] =1;

    //what will happen
    m["mera"] = 2;

    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;

    // cout<<m.at("unknownkey")<<endl;
    cout<<m["unknownkey"]<<endl;// jb hm aise acces krte hai to ek entry bn jaati hai to ab zero dikhayega
    
    //ab ise krta hu to zero dikhayega ye kyuki usne entry to bna di h
    cout<<m.at("unknownkey")<<endl;

    //size
    cout<<m.size()<<endl;

    //to chk presence of a key
    cout<<m.count("love")<<endl;
    //gives zero for no key and 1 for present

    //erase
    m.erase("love");
    cout<<m.size()<<endl;

    //accesing

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
        //first for key and second for value
    }

    //or 2nd method

    //iterator
    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }


//it prints in unorder as map is unorderedmap...........if we dont write unorder so it gives jaise daala hai vaise hi deta

    return 0;
}