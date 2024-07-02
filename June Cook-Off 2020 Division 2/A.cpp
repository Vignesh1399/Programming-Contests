#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,b,m;
	cin >> n >> b >> m;
	vector<ll> ar(n,0),br(m+1,0);
	ll b1 = 0;
	for(ll i=0;i<n;i++){
		if(i%b == 0)
		b1++;
		ar[i] = b1;
	}
	ll cnt = 1;
	for(ll i=1;i<=m;i++){
		cin >> br[i];
		if(i==1) continue;
		if(ar[br[i]] != ar[br[i-1]])
		cnt++;
	}
	cout << cnt << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

