#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m=1;
	cin>>n;
	vector<ll> ar(n,0),color(n,0);
	for(ll i=0;i<n;i++)
	cin>>ar[i];
	for(ll i=2;i<=35;i++){
		ll flag = 0;
		for(ll j=0;j<n;j++){
			if(color[j] == 0 && ar[j]%i == 0){
				color[j] = m;
				flag = 1;
			}
		}
		if(flag)
		m++;
	}
	cout<<m-1<<"\n";
	for(ll i=0;i<n;i++)
	cout<<color[i]<<" ";
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

