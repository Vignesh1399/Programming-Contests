#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll lis(ll s, ll e, vector<ll> &mark, vector<ll> &ar){
	vector<ll> ans;
	for(ll i=s;i<=e;i++){
		if(mark[i] == 0){
			auto it = upper_bound(ans.begin(),ans.end(),ar[i]-i);
			if(it == ans.end())
			ans.eb(ar[i]-i);
			else
			*it = ar[i]-i;
		}
	}
	return sz(ans);
}
void solve(){
	ll n,k,nch=0;
	cin >> n >> k;
	vector<ll> ar(n+1),br(k+1),mark(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
	}
	for(ll i=1;i<=k;i++){
		cin >> br[i];	
	}
	for(ll i=2;i<=k;i++){
		if(ar[br[i]]-br[i]>=ar[br[i-1]] - br[i-1]);
		else{
			cout << -1;
			return ;
		}
	}
	ll p2 = 1;
	for(ll i=1;i<=n;i++){
		if(p2<=k && i<br[p2] && ar[i]-i<=ar[br[p2]]-br[p2]);
		else if(p2<=k)
		mark[i] = 1;
		if(p2-1>=1 && i>br[p2-1] && ar[i]-i>=ar[br[p2-1]]-br[p2-1]);
		else if(p2-1>=1)
		mark[i] = 1;
		if(p2<=k && i == br[p2]){
			nch++;
			p2++;
		}
	}
	for(ll i=1;i<=k;i++){
		if(i == 1)
		nch += lis(i,br[i],mark,ar);
		else
		nch += lis(br[i-1],br[i],mark,ar);
	}
	if(k>0)
	nch += lis(br[k],n,mark,ar);
	else
	nch += lis(1,n,mark,ar);
	cout << n-nch ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

