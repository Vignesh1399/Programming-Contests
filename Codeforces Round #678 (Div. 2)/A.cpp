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
	ll n,m;
	cin >> n >> m;
	vector<ll> ar(n);
	ll sum = 0;
	for(auto &i:ar){
	cin >> i;
	sum += i;
	}
	if(sum == m)
	cout << "YES\n";
	else
	cout << "NO\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

