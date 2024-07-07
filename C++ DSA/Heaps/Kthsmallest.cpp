int kthsmallest(int arr[], int l, int r, int k){
    //l starting index of arr
    //r ending index of arr size-1
    
    priority_queue<int> pq;

    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<=r;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}