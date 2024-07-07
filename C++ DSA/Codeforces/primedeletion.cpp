#include <bits/stdc++.h>
 
using namespace std;
 
#define ll     long long
#define _test   int _TEST; cin>>_TEST; while(_TEST--)
#define pb     push_back
 
int main()
{
    _test
    {
        string s;
        cin>>s;
 
        int n = s.size();
 
        int x, y;
 
        for(int i=0; i<n; i++)
        {
            if(s[i] == '7')     x = i;
            if(s[i] == '1')     y = i;
        }
 
        if(x < y)       cout<<"71\n";
        else            cout<<"17\n";
    }
}