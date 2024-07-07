#include<iostream>
#include<vector>
using namespace std;
class Solution {
    //ye vala sol jada best lga mujhe
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end  = row*col-1;
        
        int mid = start + (end-start)/2;
        
        while(start<=end) {
            
            int element = matrix[mid/col][mid%col];// divide mid by col size for getting row index and mod for getting column index
            
            if(element == target) {
                return 1;
            }
            
            if(element < target) {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
            mid = start + (end-start)/2;    
        }
        return 0;
    }
};