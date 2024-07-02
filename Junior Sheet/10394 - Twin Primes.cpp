#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
#define BOUND 20000000
using namespace std;

vector<bool> prime(BOUND,true);

void preprocess(vector<pair<ll,ll>> &sthprime){
	for(ll i=2;i*i<=BOUND;i++){
		for(ll j=i*i;j<=BOUND;j+=i){
			prime[j] = false;
		}
	}
	for(ll i=3;i<=BOUND-2;i+=2){
		if(prime[i]&&prime[i+2])
		sthprime.pb({i,i+2});	
	}
}
void solve(){
	vector<pair<ll,ll>> primes;
	preprocess(primes);
	ll s;
	while(cin>>s){
		cout<<"("<<primes[s-1].first<<", "<<primes[s-1].second<<")\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

