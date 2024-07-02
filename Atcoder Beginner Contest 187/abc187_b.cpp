
// Problem: B - Gentle Pairs
// Contest: AtCoder - AtCoder Beginner Contest 187
// URL: https://atcoder.jp/contests/abc187/tasks/abc187_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,ans=0;
	cin >> n ;
	vector<pair<ll,ll>> ar(n);
	for(ll i=0;i<n;i++){
		cin >> ar[i].F >> ar[i].S;
	}
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			if(abs(ar[i].S - ar[j].S)<=abs(ar[i].F - ar[j].F))
			ans++;
		}
	}
	cout << ans ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

