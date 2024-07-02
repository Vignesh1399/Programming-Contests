#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x,p,k;
	cin >> n >> x >> p >> k;
	vector<ll> ar(n);
	for(auto &i : ar)
	cin >> i;
	sort(ar.begin(),ar.end());
	if(k<=p){
		if(ar[p-1]>x){
			cout << -1 << "\n";
			return ;
		}
		else if(ar[p-1] == x){
			cout << 0 << "\n";
			return ;
		}
		else{
			ll cnt = 0;
			for(ll i=p-1;i<n;i++)
			cnt += (ar[i]<x);
			cout << cnt << "\n";
			return ;
		}
	}
	else{
		if(ar[p-1]<x){
			cout << -1 << "\n";
			return ;
		}
		else if(ar[p-1] == x){
			cout << 0 << "\n";
			return ;
		}
		else{
			ll cnt = 0;
			for(ll i=p-1;i>=0;i--)
			cnt += (ar[i]>x);
			cout << cnt << "\n";
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

