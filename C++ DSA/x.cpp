// #include<bits/stdc++.h>
// using namespace std;
 
// #define ll long long int 
// #define vi vector<int>
// #define vll vector<long long int>

// int mini(int a, int b, int c){
//     if(a<b && a<c){
//         return a;
//     }
//     if(b<a && b<c){
//         return b;
//     }
//     if(c<b && c<a){
//         return c;
//     }
// }
// int maxi(int a, int b, int c){
//     if(b>a && b>c){
//         return b;
//     }
//     if(a>b && a>c){
//         return a;
//     }
//     if(c>b && c>a){
//         return c;
//     }
// }
 
// int main() {
//     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
//     int t;
//     cin>>t;
//     while(t--){
//         int a,b,c;
//         cin>>a>>b>>c;
//         // int a1,a2,a3,a4,a5,a6;
//         int minii= mini(a,b,c);
//         int maxii = maxi(a,b,c);
//         // if(a==mini){
//         //     a1= b-mini;
//         //     a2 = b-a1;
//         // }
//         vector<int>v;
//         if(maxii % minii ==0 && maxii/minii < 5){
//             cout<<"YES"<<endl;
//         }
//         else{
//             cout<<"NO"<<endl;
//         }
//     }
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
 
// #define ll long long int 
// #define vi vector<int>
// #define vll vector<long long int>
 
// int main() {
//     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
//     int t;
//     cin>>t;
//     while(t--){
//         int a,b,c;
//         cin>>a>>b>>c;
//         int mini = min({a,b,c});

//         bool flag = false;
//         int cnt=0;
//         if(a% mini !=0 || b%mini != 0 || c% mini != 0){
//             flag = false;
//         }
//         while(a != mini){
//             if(a%mini != 0 || cnt>3){
//                 flag = false;
//                 break;
//             }
//             a= a- mini;
//             cnt++;
//         }
//         while(b != mini){
//             if(b%mini != 0 || cnt>3){
//                 flag = false;
//                 break;
//             }
//             b= b- mini;
//             cnt++;
//         }
//         while(c != mini){
//             if(c% mini != 0 || cnt>3){
//                 flag = false ;
//                 break;
//             }
//             c = c- mini;
//             cnt++;
//         }
//         if(cnt >3){
//             flag = false;
//         }
//         if(flag == true){
//             cout<<"YES"<<endl;
//         }
//         else{
//             cout<<"NO"<<endl;
//         }
//     }
//     return 0;
// }






#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int mini = min({a, b, c});

        bool flag = true; // Set flag to true by default
        int cnt = 0;

        if (a % mini != 0 || b % mini != 0 || c % mini != 0) {
            flag = false; // If any of the numbers is not divisible by mini, set flag to false
        }

        while (a != mini) {
            if (a % mini != 0 || cnt > 3) {
                flag = false;
                break;
            }
            a = a - mini;
            cnt++;
        }
        while (b != mini) {
            if (b % mini != 0 || cnt > 3) {
                flag = false;
                break;
            }
            b = b - mini;
            cnt++;
        }
        while (c != mini) {
            if (c % mini != 0 || cnt > 3) {
                flag = false;
                break;
            }
            c = c - mini;
            cnt++;
        }

        if (cnt > 3) {
            flag = false;
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
