#include<iostream>
using namespace std;

int main() {
	string a;
	cin>>a;
	int even=0;
	int odd=0;
	int b = a.length();
	for(int i=0;i<b;i++){
		int num = a[i] - '0';
		cout<<num<<endl;
		if(a[i]%2 ==0){
			even = even+a[i];
			
		}
		else{
			odd = odd+a[i];
			
		}
	}
	cout<<even<<" "<<odd;
}
