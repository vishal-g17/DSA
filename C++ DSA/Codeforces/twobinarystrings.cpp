#include <bits/stdc++.h>
 
using namespace std;
 
#define ll     long long
#define _test   int _TEST; cin>>_TEST; while(_TEST--)
#define pb     push_back
 
int main()
{
    _test
    {
        string a, b;
        cin>>a>>b;
 
        int f = 0;
 
        for(int i=0; i<a.size()-1; i++)
            f |= (a[i]==b[i] && a[i]=='0' &&  a[i+1]==b[i+1] && a[i+1]=='1');
 
        if(f)       cout<<"YES\n";
        else        cout<<"NO\n";
    }
}