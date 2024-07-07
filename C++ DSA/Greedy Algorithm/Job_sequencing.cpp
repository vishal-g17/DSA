//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n){
        sort(arr, arr+n, cmp);
        int maxiDeadline = INT_MIN;

        for(int i=0; i<n; i++){
            maxiDeadline = max(maxiDeadline, arr[i].dead);
        }

        vector<int> Schedule(maxiDeadline+1, -1);

        int count =0; 
        int maxProfit =0;
        for(int i=0; i<n; i++){
            int currProfit = arr[i].profit;
            int currJobId = arr[i].id;
            int currDead = arr[i].dead;

            for(int k=currDead; k>0; k--){
                if(Schedule[k] == -1){
                    count++;
                    maxProfit += currProfit;
                    Schedule[k] = currJobId;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(maxProfit);
        return ans;
    }
};
