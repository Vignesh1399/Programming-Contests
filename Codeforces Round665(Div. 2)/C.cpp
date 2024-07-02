#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll k=1;

bool check(vector<ll> &ar, ll n, ll a, ll b, ll c){
	ll cmax = 0,cnta=0,cntb=0;
	vector<ll> br(n,0);
	for(ll i=0;i<n;i++){
		if(ar[i]>=cmax){
			cnta++;
			br[i]++;
		}
		cmax = max(cmax,ar[i]);
	}
	cmax = 0;
	for(ll i=n-1;i>=0;i--){
		if(ar[i]>=cmax){
			cntb++;
			br[i]++;
		}
		cmax = max(cmax,ar[i]);
	}
	ll cntc = 0;
	for(ll i=0;i<n;i++){
		cntc += (br[i] == 2);
	}
	return (cntc == c && cntb == b && cnta == a);
}
void getcomb(ll i,ll n, vector<ll> &ar, bool &flag, ll a, ll b, ll c){
	if(i == n || flag){
		if(!flag)
		flag = check(ar,n,a,b,c);
		return ;
	}
	for(ll j=1;j<=n;j++){
		if(!flag){
		ar[i] = j;
		getcomb(i+1,n,ar,flag,a,b,c);
		}
		else
		return ;
	}
}
void solve(){
	ll n,a,b,c;
	bool ck = 0;
	cin >> n >> a >> b >> c;
	vector<ll> ar(n);
	getcomb(0,n,ar,ck,a,b,c);
	if(!ck){
		cout << "Case #"<<k++<<": " << "IMPOSSIBLE"<< "\n";
	}
	else{
		cout << "Case #"<<k++<<": " ;
		for(auto i : ar)
		cout << i << " ";
		cout << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

