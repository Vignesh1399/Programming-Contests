#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void check(vector <pair<pair<ll,ll>,ll>> &ar, vector<ll> &ans, ll idx, ll x, ll y,ll sno){
	ll dist = (x - ar[idx].first.first) * (x - ar[idx].first.first) + y * y;
	if(dist <= ar[idx].first.second * ar[idx].first.second){
		if(ans[ar[idx].second] == -1)
		ans[ar[idx].second] = sno;
	}
}

void solve(){
	ll n,m;
	cin >> n;
	vector<pair<pair<ll,ll>,ll>> ar(n);
	vector<ll> ans(n,-1);
	ll k = 0;
	for(auto &i:ar){
		cin >> i.first.first >> i.first.second;
		i.second = k++;
	}
	sort(ar.begin(),ar.end());
	cin >> m;
	for(ll i=0;i<m;i++){
		ll x,y;
		cin >> x >> y;
		ll idx = upper_bound(ar.begin(),ar.end(),make_pair(make_pair(x,y),0ll)) - ar.begin();
		if(idx == n)
		check(ar,ans,idx-1,x,y,i+1);
		else if(idx == 0)
		check(ar,ans,idx,x,y,i+1);
		else{
			check(ar,ans,idx,x,y,i+1);
			check(ar,ans,idx-1,x,y,i+1);
		}
	}
	ll cnt = 0;
	for(auto i : ans){
		if(i!=-1)
		cnt++;
	}
	cout << cnt << "\n";
	for(auto i : ans)
	cout << i << " ";
	
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

