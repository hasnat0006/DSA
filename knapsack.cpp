#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &i:v) cin>>i;
	for(auto i:v) cout<<i<<" ";
	cout<<"\n";
}