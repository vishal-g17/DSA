#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

vector<int> rotateby90(vector<vector<int>> matrix,int rows, int cols){
    vector<int> ans;
    int count=0;
    int total= cols*rows;
    //printing column from bottom to top then increase index of column 
    while(count<total){
        for(int i=0;i<rows;i++){
            for(int j = cols-1;j>=0;j--){
                ans.push_back(matrix[j][i]);
                count++;
            }
        }
    }
    return ans;


} 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int m;
    // cout<<"enter row : ";
    cin>>n;
    cout<<endl;
    // cout<<"enter column : ";
    cin>>m;
    vector<vector<int>> mat(n, vector<int> (m));
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> rotatedmat = rotateby90(mat,n,m);
    // for(int i: rotatedmat){
    //     cout<<i<<" ";// it gives ans in form of 1d vector not in form of matrix 
    // }

    for(int i=1;i<10;i++){
        // for(int j=0;j<3;j++){
        cout<<rotatedmat[i-1]<<" ";
        if(i%3==0){
            cout<<endl;
        }
        // }
    }
    
    return 0;
}