#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k,sum=0;
	cin >> n >> k;
	vector<ll> ar(n+1,0),br(n+1,0),c;
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=1;i<=n;i++)
	cin >> br[i];
	sort(ar.begin()+1,ar.end());
	sort(br.begin()+1,br.end(),greater<ll>());
	for(ll i=1;i<=n;i++){
		if(i<=k)
		c.pb(max(ar[i],br[i]));
		else
		c.pb(ar[i]);
	}
	for(auto i:c)
	sum += i;
	cout<<sum<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

