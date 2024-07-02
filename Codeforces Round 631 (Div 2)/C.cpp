#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m,start = 1;
	vector<ll> ar(m+1,0),p;
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	cin>>ar[i];
	for(ll i=1;i<=m-1;i++){
		if(start<=n-ar[i]+1){
			p.pb(start);
			start += 1;
		}
		else{
			start = -1
			break;
		}
	}
	if(start<n)
	cout<<-1;
	else{
		for(auto i:p)
		cout<<i<<" ";
	}
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

