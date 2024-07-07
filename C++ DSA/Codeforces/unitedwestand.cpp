#include <bits/stdc++.h>
 // pehle arraysort kia fir half me divide kr dia bs ye dekhna hai ki middle two elements equal nhi hone chahiye usme -1 dena hai ye me soch chuka tha pr is case me -1 dena hai ye nhi soch [ppaya tha]
using namespace std;
 
#define ll     long long
#define _test   int _TEST; cin>>_TEST; while(_TEST--)
#define ff     first
#define ss     second
#define pb     push_back
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    _test
    {
        int n;
        cin>>n;
 
        vector<int> a(n);
        for(auto &e: a)     cin>>e;
 
        sort(a.begin(), a.end());
 
        int f = 0;
 
        for(int i=0; !f && i<n-1; i++)
        {
            if(a[i] != a[i+1])
            {
                f = 1;
 
                cout<<i+1<<" "<<n-i-1<<"\n";
 
                for(int j=0; j<=i; j++)
                    cout<<a[j]<<" ";
                cout<<"\n";
 
                for(int j=i+1; j<n; j++)
                    cout<<a[j]<<" ";
                cout<<"\n";
            }
        }
 
        if(!f)
            cout<<-1<<"\n";
    }
}