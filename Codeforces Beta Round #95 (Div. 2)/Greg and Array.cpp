#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m,k,x,y,p=0;
	cin >> n >> m >> k;
	vector<ll> ar(n+1,0),opr(m+2,0),pr(n+2,0),l(m+1,0),r(m+1,0),d(m+1,0),add(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=1;i<=m;i++)
	cin >> l[i] >> r[i] >> d[i];
	for(ll i=1;i<=k;i++){
		cin >> x >> y;
		opr[x]++;
		opr[y+1]--;
	}
	for(ll i=1;i<=m;i++){
		p += opr[i];
		pr[l[i]] += d[i]*p;
		pr[r[i] + 1] -= d[i]*p;
	}
	for(ll i=1;i<=n;i++)
	add[i] = add[i-1] + pr[i]; 
	for(ll i=1;i<=n;i++){
		ar[i] += add[i];
		cout<<ar[i]<<" ";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

