#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	sort(ar.begin()+1,ar.end());
	set<ll> s;
	for(ll i=1;i<=n;i++){
		if(ar[i]%k !=0)
		s.insert(ar[i]);
		else if(ar[i]%k==0 && s.find(ar[i]/k) == s.end())
		s.insert(ar[i]);
	}
	cout<<sz(s);
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

