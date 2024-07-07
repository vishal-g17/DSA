#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/ 
// fn to get max total value in knapsack

class solution{
    public:
    static bool cmp(pair<double, Item> a, pair<double, Item> b){
        return a.first > b.first;
    }

    double fractionalKnapsack(int W, Item arr[], int n){
        vector<pair<double, Item>> v;

        for(int i=0; i<n; i++){
            double perUnitValue = (1.0*arr[i].value) / arr[i].weight;
            pair<double, Item> p = make_pair(perUnitValue, arr[i]);
            v.push_back(p);
        }
        sort(v.begin(), v.end(), cmp);

        double totalValue = 0;
        for(int i =0; i<n; i++){
            if(v[i].second.weight > W){
                //to me sirf fraction le skta hu
                totalValue += W*v[i].first;
            }
            else{
                totalValue += v[i].second.value;
                W= W - v[i].second.weight;
            }
        }
        return totalValue;
    }
};