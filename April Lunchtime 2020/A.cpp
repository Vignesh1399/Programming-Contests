#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 998244353;
vector<ll> p(1e5+1,0);



ll power(ll b, ll e){
	ll res=1;
	b%=MOD;
	while(e>0){
		if(e&1)
		res = (res*b)%MOD;
		b = (b*b)%MOD;
		e/=2;
	}
	return res;
}

void precalc(){
	for(ll i=0;i<=1e5+2;i++)
	p[i] = power(2,i);
}



void solve(){
	ll n,k,x,flag=0,ans=0;
	//pr[i]: no of nos >= i;
	cin >> n ;
	vector<ll> ar(n,0),pref(1e5+4,1),suf(1e5+4,1);
	multiset<ll> m;
	for(ll i=1;i<=n;i++){
		cin >> ar[i-1];
		m.insert(ar[i-1]);
	}
	sort(ar.begin(),ar.end());
	for(ll i=1e5+2;i>=0;i--){
		ll idx = lower_bound(ar.begin(), ar.end(), i) - ar.begin();
		suf[i] = (p[n-idx])%MOD;
	}
	 
	for(ll i=1;i<=1e5;i++){
		pref[i] = (pref[i-1] * ((p[m.count(i)]-1 + MOD)%MOD))%MOD;
	}

	for(ll i=1;i<=1e5+1;i++){
		ll x = (pref[i-1] * suf[i+1])%MOD;
		ans = (ans + (i*x)%MOD)%MOD;
	}
	cout<<ans;
	cout<<"\n";
}

int main() {
	precalc();
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

