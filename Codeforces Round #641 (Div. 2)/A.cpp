#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

vector<ll> prime(2e5+1,1);
void sieve(){
	prime[1] = 0;
	for(ll i=2;i*i<=2e5;i++){
		if(!prime[i])
		continue;
		for(ll j = i*i;j<=2e5;j+=i)
		prime[j] = 0;
	}
}

ll primefac(vector<ll> &ar, ll n){
	ll ans = 1;
	vector<ll> store;
	for(ll i=2;i<=2e5;i++){
		if(prime[i]){
		store.pb(i);
		}
	}
	for(ll i=0;i<sz(store);i++){
		ll cnt = 0,temp=1;
		while(cnt < 2){
			cnt = 0;
			for(ll j=1;j<=n;j++){
				if(ar[j] % store[i] != 0){
					++cnt;
				}
				else if(store[i] <= ar[j])
				ar[j] /= store[i];
			}
			if(cnt<2)
			temp *= store[i];
		}
		ans *= temp;
	}
	return ans;
}


void solve(){
	ll n,k;
	sieve();
	cin >> n ;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	ll ans = primefac(ar, n);
	cout<<ans;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

