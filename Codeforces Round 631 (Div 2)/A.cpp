#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x;
	cin>>n>>x;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++)
	cin>>ar[i];
	sort(ar.begin(),ar.end());	
	for(ll i=n+x;i>=1;i--){
		ll missing=0;
		for(ll j=1;j<=i;j++){
			if(!binary_search(ar.begin(),ar.end(),j))
			missing++;
		}
		if(missing<=x){
		cout<<i<<"\n";
		return ;
		}
	}
	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

