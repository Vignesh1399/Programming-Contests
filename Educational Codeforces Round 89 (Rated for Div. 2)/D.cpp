#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll sf[10000001];
void pre(){
	for(ll i=1;i<=1e7;i++)
	sf[i] = i;
	for(ll i=2;i*i<=1e7;i++){
		for(ll j=i*i;j<=1e7;j+=i)
		sf[j] = min(sf[j],i);
	}
}

void solve(){
	pre();
	ll n;
	cin >> n;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	vector<ll> l1,l2;	
	for(ll i=1;i<=n;i++){
		set<ll> s;
		while(ar[i] != 1){
			s.insert(sf[ar[i]]);
			ar[i] /= sf[ar[i]];
		}
		if(sz(s) < 2){
			l1.pb(-1);
			l2.pb(-1);
			continue;
		}
		l1.pb(*s.begin());
		s.erase(s.begin());
		ll val = 1;
		for(auto i : s)
		val *= i;
		l2.pb(val);
	}
	for(auto i : l1)
	cout << i << " ";
	cout << "\n";
	for(auto i : l2)
	cout << i << " ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

