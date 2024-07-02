#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n);
	for(auto &i : ar)
	cin >> i;
	if(ar[0]+ar[1]<=ar[n-1]){
		cout << 1 << " " <<2 << " " << n << "\n";
	}
	else
	cout << -1 << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

