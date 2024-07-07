#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    int t;
    cin>>t;
    while(t--){
        char a[4]= {'v','i','k','a'};
        int row;
        int col;
        cin>>row>>col;
        char arr[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>arr[i][j];
            }
        }
        int k=0;
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(arr[j][i]==a[k]){
                    k++;
                    // cout<<k<<" "<<a[k]<<arr[j][i];
                    break;
                }
 
            }
        }
        if(k==4){
            cout<<"YES"<<endl;;
        }
        else{
            cout<<"NO"<<endl;
        }
 
    }
    return 0;
}