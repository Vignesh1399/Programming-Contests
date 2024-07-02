#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,a,b,flag=0;
	cin>>n;
	pair<ll,ll> p = {0ll,0ll};
	for(ll i=1;i<=n;i++){
		cin>>a>>b;
		if(a>=p.first && b>=p.second && (a-p.first)>=(b-p.second))
		p = {a,b};
		else
		flag=1;
	}
	if(flag)
	cout<<"NO";
	else
	cout<<"YES";
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

