#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void update(vector<ll> &bit, ll x, ll val){
	for(ll i=x;i<sz(bit);i+=(i & -i))
	bit[i] += val;
}
ll sum(vector<ll> &bit, ll x){
	ll sum = 0;
	for(ll i=x;i>=1;i-=(i&-i))
	sum += bit[i];
	return sum;
}
void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n);
	for(auto &i : ar){
		cin >> i;
	}
	ll me = *max_element(ar.begin(),ar.end());
	vector<ll> bit(me+1);
	ll res = 0;
	for(ll i=n-1;i>=0;i--){
		update(bit,ar[i],1);
		res += sum(bit,ar[i]-1);
	}
	cout << res << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

