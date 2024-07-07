// #include<bits/stdc++.h>
// int signum(int a, int b){
// 	if(a==b){
// 		return 0;
// 	}
// 	else if(a>b){
// 		return 1;
// 	}
// 	else{
// 		return -1;
// 	}
// }

// void callMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int> >> &mini, int &median){
// 	switch(signum(maxi.size(), mini.size())){
// 		case 0 : if(element > median){
// 			mini.push(element);
// 			median = mini.top();
// 		}
// 		else{
// 			maxi.push(element);
// 			median = maxi.top();
// 		}
// 		break;

// 		case 1: if(element> median){
// 			mini.push(element);
// 			median = (mini.top() + maxi.top())/2;
// 		}
// 		else{
// 			mini.push(maxi.top());
// 			maxi.pop();
// 			maxi.push(element);
// 			median = (mini.top()+maxi.top())/2;
// 		}
// 		break;

// 		case -1: if(element>median){
// 			maxi.push(mini.top());
// 			mini.pop();
// 			mini.push(element);
// 			median = (mini.yop() + maxi.top())/2;
// 		}
// 		else{
// 			maxi.push(element);
// 			median = (mini.top() + maxi.top())/2;
// 		}
// 		break;
// 		}
// }
// vector<int> findMedian(vector<int> &arr, int n){
	
// 	vector<int> ans;
// 	priority_queue<int> maxheap;
// 	priority_queue<int, vector<int>, greater<int> >minheap;
// 	int median = 0;
// 	for(int i=0;i<n;i++){
// 		callMedian(arr[i], maxheap, minheap, median);
// 		ans.push_back(median);
// 	}
// 	return ans;
// }
 





#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int signum(int a, int b) {
    if (a == b) {
        return 0;
    } else if (a > b) {
        return 1;
    } else {
        return -1;
    }
}

void balanceHeaps(priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini) {
    while (maxi.size() > mini.size() + 1) {
        mini.push(maxi.top());
        maxi.pop();
    }

    while (mini.size() > maxi.size() + 1) {
        maxi.push(mini.top());
        mini.pop();
    }
}

void callMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median) {
    switch (signum(maxi.size(), mini.size())) {
        case 0:
            if (element > median) {
                mini.push(element);
                median = mini.top();
            } else {
                maxi.push(element);
                median = maxi.top();
            }
            break;

        case 1:
            if (element > median) {
                mini.push(element);
            } else {
                maxi.push(element);
                mini.push(maxi.top());
                maxi.pop();
            }
            median = (mini.top() + maxi.top()) / 2;
            break;

        case -1:
            if (element > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
            } else {
                maxi.push(element);
            }
            median = (mini.top() + maxi.top()) / 2;
            break;
    }
}

vector<int> findMedian(vector<int> &arr, int n) {
    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int median = 0;
    for (int i = 0; i < n; i++) {
        callMedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }
    return ans;
}

// int main() {
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int n = arr.size();
//     vector<int> result = findMedian(arr, n);

//     for (int i = 0; i < n; i++) {
//         cout << result[i] << " ";
//     }

//     return 0;
// }
