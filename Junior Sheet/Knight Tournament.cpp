#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m;
	set<ll> s;
	vector<ll> ar(n+1,0);
	for(ll i=0;i<n;i++){
		s.insert(i+1);
	}
	for(ll i=1;i<=m;i++){
		ll li,ri,xi;
		vector<ll> temp;
		cin >> li >> ri >> xi;
		auto itl = s.lower_bound(li);
		auto itr = s.upper_bound(ri);
		for(auto it = itl; it!=itr && (*it)<=ri; it++)
		temp.pb(*it);
		for(auto i:temp){
			if(i!=xi){
				s.erase(i);
				ar[i] = xi;
			}
		}
	}
	for(ll i=1;i<=n;i++)
	cout<<ar[i]<<" ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

