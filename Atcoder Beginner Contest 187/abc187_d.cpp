
// Problem: D - Choose Me
// Contest: AtCoder - AtCoder Beginner Contest 187
// URL: https://atcoder.jp/contests/abc187/tasks/abc187_d
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
ll sum = 0;
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return 2*a.F+a.S>2*b.F+b.S;
}
void solve(){
	ll n;
	cin >> n;
	ll ans = 0;
	ll t = 0;
	vector<pair<ll,ll>> ar(n);
	for(ll i=0;i<n;i++){
		cin >> ar[i].F >> ar[i].S;
		sum += ar[i].F;
	}
	sort(ar.begin(),ar.end(),comp);
	for(ll i=0;i<n;i++){
		t += ar[i].F + ar[i].S;
		sum -= ar[i].F;
		ans++;
		if(t>sum)
		break;
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

