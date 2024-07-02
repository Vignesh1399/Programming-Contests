#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct trip{
	ll l,r,c;
};

bool comp(struct trip a, struct trip b){
	if(a.l != b.l)
	return a.l < b.l;
	return a.c < b.c;
}

vector<struct trip> dur[200001];
vector<ll> sufc[200001];

ll bin_search(vector<struct trip> &ar, ll start){
	ll lb = 0,ub = sz(ar)-1;
	while(lb<=ub){
		ll mid = (lb+ub)/2;
		if(ar[mid].l <= start)
		lb = mid + 1;
		else 
		ub = mid - 1;
	}
	return lb;
}

void solve(){
	ll n,x;
	cin >> n >> x;
	for(ll i=1;i<=n;i++){
		ll left,right,cost;
		cin >> left >> right >> cost;
		dur[right - left +1].pb({left,right,cost}); 
	}
	for(ll i=1;i<=2e5;i++)
	sort(dur[i].begin(),dur[i].end(),comp);
	for(ll i=1;i<=2e5;i++){
		if(!sz(dur[i])) continue;
		sufc[i].pb(dur[i].back().c);
		for(ll j=sz(dur[i])-2;j>=0;j--){
			ll x = sufc[i].back();
			sufc[i].pb(min(x,dur[i][j].c));
		}
		reverse(sufc[i].begin(),sufc[i].end());
	}
	ll ans = 1e10;
	for(ll i=1;i<=x;i++){
		for(ll j=0;j<sz(dur[i]);j++){
			ll temp = dur[i][j].c;
			ll idx = bin_search(dur[x-i],dur[i][j].r);
			//cout <<x-i << " " << idx << "\n";
			if(idx == sz(dur[x-i])) continue;
			temp += sufc[x-i][idx];
			ans = min(ans,temp);
		}
		//cout << ans << " \n";
	}
	if(ans == 1e10)
	cout << -1;
	else
	cout << ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

