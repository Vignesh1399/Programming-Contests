/*
Use a Mathematical Trick
consider the leg to be the cathetus
*/ 

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m,k;
	cin >> n;
	if(n%2){
		m = (n*n + 1)/2;
		k = m - 1;
	}
	else{
		m = n*n/4 + 1;
		k = m - 2;
	}
	if(m && k && (n*n + k*k == m*m))
	cout<< k <<" "<< m ;
	else
	cout<< -1;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

