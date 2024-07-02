#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 1e9+7;
vector<ll> fact(1e6+1,1);

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

void pre(){
	for(ll i=2;i<=1e6;i++){
		fact[i] = (fact[i-1] * i)%MOD;
	}
}

ll ncr(ll a, ll b){
	ll x = (fact[a-b]*fact[b])%MOD;
	ll den = power(x,MOD-2);
	return (fact[a]*den)%MOD;
}

void solve(){
	ll n,a,b,ans=0;
	pre();
	cin >> a >> b >> n;
	for(ll i=0;i<=n;i++){
		ll num = i*a + (n-i)*b;
		ll flag=0;
		while(num>0){
			ll rem = num%10;
			num/=10;
			if(rem!=a && rem!=b)
			flag=1;
		}
		if(!flag)
		ans = (ans + ncr(n,i))%MOD;
	}
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

