#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

vector<ll> p(31,1);
void pre(){
	for(ll i=1;i<=30;i++)
	p[i] = p[i-1] * 2;
}

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first != b.first)
	return a.first>b.first;
	return a.second<b.second;
}
void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> ar(n+1,0),bit(31,0);
	vector<pair<ll,ll>> val(31,{0,0});
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=30;j++)
		bit[j] += (ar[i]>>j)&1;
	}
	for(ll i=0;i<=30;i++){
		val[i] = {bit[i] * p[i],i};
	}
	sort(val.begin(),val.end(),comp);
	ll ans = 0;
	for(ll i=0;i<k;i++){
		ans += p[val[i].second];
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    pre();
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

