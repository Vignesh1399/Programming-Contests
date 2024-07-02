#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	n*=2;
	vector<ll> ar(n);
	for(auto &i : ar)
	cin >> i;
	vector<ll> ans;
	for(ll i=0;i<n/2;i++){
		for(ll j=0;j<n;j++){
			if(ar[j] > 0){
			ans.pb(ar[j]);
			ar[j] = 0;
			break;
			}
		}
		for(ll j=0;j<n;j++){
			if(ans[i] == ar[j])
			ar[j] = 0;
		}
	}
	for(auto i : ans)
	cout << i << " ";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

