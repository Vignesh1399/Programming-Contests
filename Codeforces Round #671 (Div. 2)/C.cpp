#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x;
	cin >> n >> x;
	vector<ll> ar(n);
	for(auto &I : ar)
	cin >> I;
	ll diff = 0;
	bool  flag  = 0,f2 = 0;
	for(ll i=0;i<n;i++){
		diff += ar[i] - x;
		if(diff != 0)
		flag = 1;
		if(ar[i] - x == 0)
		f2 = 1;
	}
	if(diff == 0 && !flag)
	cout << 0;
	else if(diff == 0 || f2 == 1)
	cout << 1;
	else
	cout << 2;
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

