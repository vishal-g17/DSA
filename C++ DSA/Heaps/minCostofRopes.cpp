long long mincost(long long arr[], long long n){

    //creating minheap
    priority_queue<long long , vector<long long>, greater<long long> > pq;

    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }

    long long cost=0;

    while(pq.size()>1){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long sum = a+b;
        cost = sum +cost;

        pq.push(sum);
    }

    return cost;
}