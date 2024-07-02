#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,q,l,r,sum=0;
	cin >> n >> q;
	vector<ll> ar(n+1,0),pr(n+2,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=1;i<=q;i++){
		cin >> l >> r;
		pr[l]++;
		pr[r+1]--;
	}
	for(ll i=1;i<=n;i++){
		pr[i] += pr[i-1];
	}
	sort(pr.begin()+1,pr.end(),greater<ll>());
	sort(ar.begin()+1,ar.end(),greater<ll>());
	for(ll i=1;i<=n;i++)
	sum += ar[i] * pr[i];
	cout<<sum;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

