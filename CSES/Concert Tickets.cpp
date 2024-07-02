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
	vector<ll> pr(n),tic(m);
	multiset<ll> ms;
	for(auto &i : pr)	
		cin >> i;
	for(auto &i : tic)
		cin >> i;
	for(ll i=0;i<n;i++)
		ms.insert(pr[i]);
	for(ll i=0;i<m;i++){
		auto it = ms.upper_bound(tic[i]);
		if(sz(ms) == 0 || it == ms.begin())	
			cout << -1 << "\n";
		else{
			--it;
			cout << *it << "\n";
			ms.erase(it);
		}
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

