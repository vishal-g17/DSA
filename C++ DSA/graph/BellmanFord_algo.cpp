//code help code
//int bellmonFord(int n, int m,int src, vector<vector<int>> &edges) {
//     vector<int> dist(n+1, 1e9);//1e9 is like a infinity max number
//     dist[src]=0;

//     //n-1 times

//     for(int i=1; i<n;i++){
//         //traverse on edge list
//         for(int j=0;j<m;j++){
//             int u= edges[j][0];
//             int v= edges[j][1];
//             int wt = edges[j][2];

//             if(((dist[u]+wt) < dist[v])){
//                 dist[v] = dist[u] + wt;
//             }
//         }
//     }
//     //check -ive cycle
//     // bool flag =0;
//     // for(int j=0;j<m;j++){
//     //     int u= edges[j][0];
//     //     int v= edges[j][1];
//     //     int wt = edges[j][2];

//     //     if(dist[u] != 1e9 && ((dist[u]+wt) < dist[v])){
//     //         flag =1;
//     //     }
//     // }

//     // if(flag == 0){
//     //     return dist;
//     // }
//     // return -1;


// }

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {

    vector<int> distance(n+1,1e8);

    distance[src] = 0;

    for(int i =1; i<n; i++){

        for(int j = 0; j<m; j++){

            int u = edges[j][0];

            int v = edges[j][1];

            int w = edges[j][2];

            if ((distance[u] + w < distance[v])) {

              distance[v] = distance[u] + w;
            }
        }
    }

    // check -ive cycle
    bool flag =0;
    for(int j=0;j<m;j++){
        int u= edges[j][0];
        int v= edges[j][1];
        int w = edges[j][2];

        if(distance[u] != 1e8 && ((distance[u]+w) < distance[v])){
            flag =1;
        }
    }

    if(flag == 0){
        return distance;
    }


}