#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	set<ll> s;
	map<ll,ll> m;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		s.insert(ar[i]);
		m[ar[i]]++;
	}
	ll p=0,ans=0;
	for(auto i:s){
		if(p+m[i]>=i){
			ans = p+m[i];
		}
		p += m[i];
		//cout<< i <<" ";
	}
	cout<<ans+1;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

