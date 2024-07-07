#include<bits/stdc++.h> 
using namespace std; 

bool isPresent(int arr[][3], int target, int row, int col) {

  for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            
            if( arr[row][col] == target) {
                return 1;
            }
            
        }
    }
    return 0;
}

//to print row wise sum
void printColSum(int arr[][3], int row, int col) {
    cout << "Printing Sum -> " << endl;
    for(int col=0; col<3; col++) {
        int sum = 0;
        for(int row=0; row<3; row++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }

    cout << endl;
}


//to print row wise sum
void printSum(int arr[][3], int row, int col) {
    cout << "Printing Sum -> " << endl;
    for(int row=0; row<3; row++) {
        int sum = 0;
        for(int col=0; col<3; col++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }

    cout << endl;
}

int largestRowSum(int arr[][3], int row, int col) {

    int maxi = INT_MIN;
    int rowIndex = -1;

    for(int row=0; row<3; row++) {
        int sum = 0;
        for(int col=0; col<3; col++) {
            sum += arr[row][col];
        }

        if(sum > maxi ) {
            maxi = sum;
            rowIndex = row;
        }
       
    }

    cout << "the maximum sum is " << maxi << endl;
    return rowIndex;
}

int main() {

    //create 2 d array
    int arr[3][3];
    //int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,14,16};
    //int arr[3][4] = {{1,11,111,1111}, {2,22,222,2222}, {3,33,333,3333}};

    cout << "Enter the elements " <<  endl;
    //taking input -> row wise input
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cin >> arr[row][col];
        }
    }


/*
//taking input -> col wise input
    for(int col=0; col<4; col++) {
        for(int row=0; row<3; row++) {
            cin >> arr[row][col];
        }
    }

*/

    cout << "Printing the array " << endl;
    //print 
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
/*
    cout <<" Enter the element to search " << endl;
    int target;
    cin >> target;

    if(isPresent(arr, target, 3, 3)) {
        cout <<" Element found " << endl;
    }
    else{
        cout <<" Not Found" << endl;
    }

    printColSum(arr, 3, 3 );
    */
   int ansIndex = largestRowSum(arr,3,3);
   cout << " Max row is at index " << ansIndex << endl;

    return 0;






// #include<bits/stdc++.h>
// using namespace std;
 
// #define ll long long int 
// #define vi vector<int>
// #define vll vector<long long int>
 
// int main() {
//     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//     int arr[3][4];
//     // int arr[3][4]= {1,2,3,4,5,6,7,8,9,10,11,12};// it also give row wise entry
//     // int arr[3][4]={{1,11,111,1111}, {2,22,222,2222},{3,33,333,3333}};  it also give row wise entry

// //i row hai and j column hai

// //taking input row   wise
//     for(int i=0;i<3;i++){
//         for(int j=0;j<4;j++){
//             cin>>arr[i][j];
//         }
//     }
// //output row wise 
//     for(int i=0;i<3;i++){
//         for(int j=0;j<4;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// // //taking input collumn wise
// //     for(int i=0;i<4;i++){
// //         for(int j=0;j<3;j++){
// //             cin>>arr[j][i];
// //         }
// //     }
// // //output column  wise 
// //     for(int i=0;i<4;i++){
// //         for(int j=0;j<3;j++){
// //             cout<<arr[j][i]<<" ";
// //         }
// //         cout<<endl;
// //     }


   
// }
}