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
	ll n;
	cin >> n;
	vector<ll> ar(n,0),h(n,0);
	for(auto &i : ar)
	cin >> i;
	ll p1 = 0, p2 = 1;
	while(p2<n){
		h[p2] = h[p1] + 1;
		p2++;
		while(p2<n){
			if(p2<n && ar[p2]>ar[p2-1]){
				h[p2] = h[p1] + 1;
				p2++;
			}
			else
			break;
		}
		p1++;
	}
	ll ans = 0;
	for(auto i : h)
	ans = max(ans,i);
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

