// #include<bits/stdc++.h>
// class node{
//     public:
//     int data;
//     int row;
//     int col;

//     node(int d, int r, int c){
//         data = r;
//         row= r;
//         col= c;
//     }
// };
// class compare{
//     public:
//     bool operator()(node* a, node* b){
//         return a->data > b->data;
//     }
// };

// int kSorted(vector<vector<int>> &a, int k, int n) {
//     int maxi = INT_MAX;
//     int mini = INT_MIN;
//     priority_queue<node*, vector<node*>, compare> minheap;

//     //step 1 create a min heap for starting element of eah list and ytracking mini maxi value

//     for(int i=0;i<k;i++){
//         int element = a[i][0];
//         mini = min(mini, element);
//         maxi = max(maxi, element);
//         minheap.push(new node(element, i, 0));
//     }

//     int start = mini, end = maxi;

//     //process ranges

//     while(!minheap.empty()){

//         //mini fetches
//         node* temp = minheap.top();
//         minheap.pop();
//         mini= temp->data;

//         //range or answer updation

//         if(maxi - mini < end- start){
//             start = mini;
//             end= maxi;
//         }

//         //next element exists

//         if(temp->col +1 < n){
//             maxi = max(maxi, a[temp->row][temp->col +1]);
//             minheap.push(new node(a[temp->row][temp->col +1], temp->row, temp->col+1));
//         }
//         else{
//             //next element does not exist
//             break;
//         }
//     }

//     return {end-start +1};

// }


#include <bits/stdc++.h>
class node {
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;  // Fix the assignment here
        row = r;
        col = c;
    }
};
class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>>& a, int k, int n) {
    int maxi = INT_MIN;  // Change this to INT_MIN
    int mini = INT_MAX;  // Change this to INT_MAX
    priority_queue<node*, vector<node*>, compare> minheap;

    // Step 1: Create a min heap for the starting element of each list and track mini and maxi values

    for (int i = 0; i < k; i++) {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minheap.push(new node(element, i, 0));
    }

    int start = mini, end = maxi;

    // Process ranges

    while (!minheap.empty()) {
        // Mini fetches
        node* temp = minheap.top();
        minheap.pop();
        mini = temp->data;

        // Range or answer updation

        if (maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        // Next element exists

        if (temp->col + 1 < n) {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minheap.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        } else {
            // Next element does not exist
            break;
        }
    }

    return end - start + 1;  // Return an integer, not a set
}
