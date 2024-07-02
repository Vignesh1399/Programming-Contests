#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n ;
	vector<ll> ar(n),l(n),p;
	for(auto &i : ar)
	cin >> i;
	for(auto &i : l)
	cin >> i;
	for(ll i=0;i<sz(ar);i++){
		if(l[i] == 0){
			p.pb(ar[i]);
		}
	}
	sort(p.begin(),p.end(),greater<ll>());
	ll k=0;
	for(ll i=0;i<n;i++){
		if(!l[i])
		ar[i] = p[k++];
	}
	for(auto i : ar)
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

