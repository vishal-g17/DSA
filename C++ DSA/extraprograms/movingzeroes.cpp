#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

void movezeroes(vector<int>& nums){
    int nonzero = 0;
    for(int j =0; j<nums.size(); j++){
        if(nums[j]!=0){
            swap(nums[j],nums[nonzero]);
            nonzero++;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
   //matlab ek aisa array diya hoga 0 1 0 3 4 0 or hme ise aisa bnana h 1 3 4 0 0 0 
}