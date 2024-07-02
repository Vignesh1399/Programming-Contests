#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
//ll d[1001][1001];
void solve(){
	vector<pair<ll,ll>> ar(4);
	for(ll i=1;i<=3;i++){
		ll a,b;
		cin >> a >> b;
		ar[i] = {a,b};
	}
	sort(ar.begin()+1,ar.end());
	set<pair<ll,ll>> ans;
	// x, y 
	//d[ar[1].first][ar[1].second] = 1;
	for(ll i=ar[1].first;i<=ar[2].first;i++){
		//d[i][ar[1].second] = d[i-1][ar[1].second] + 1;
		ans.insert({i,ar[1].second});
	}
	ll dy = 1;
	if(ar[2].second<ar[1].second)
	dy = -1;
	for(ll i=ar[1].second;i!=ar[2].second;i += dy){
		//d[ar[2].first][i] = d[ar[2].first][i-1] + 1;
		ans.insert({ar[2].first,i});
	}
	//d[ar[2].first][ar[2].second] = d[ar[2].first][ar[2].second-1] + 1;
	ans.insert({ar[2].first,ar[2].second});
	ll low = ar[1].second, high = ar[2].second;
	ll temp = min(high,low);
	high = max(high,low);
	low = temp;
	if(ar[3].second>=low && ar[3].second<=high){
		for(ll i=ar[3].first;i>=ar[2].first;i--){
			//d[i][ar[3].second]  = d[i+1][ar[3].second] + 1;
			ans.insert({i,ar[3].second});
		}
	}
	else if(ar[3].second>high){
		for(ll i=ar[3].first;i>=ar[2].first;i--){
			//d[i][ar[3].second]  = d[i+1][ar[3].second] + 1;
			ans.insert({i,ar[3].second});
		}
		for(ll i = ar[3].second; i> high; i--){
			//d[ar[2].first][i] = d[ar[2].first][i]
			ans.insert({ar[2].first,i});
		}
	}
	else{	
		for(ll i=ar[3].first;i>=ar[2].first;i--){
			//d[i][ar[3].second]  = d[i+1][ar[3].second] + 1;
			ans.insert({i,ar[3].second});
		}
		for(ll i = ar[3].second; i<low; i++){
			//d[ar[2].first][i] = d[ar[2].first][i]
			ans.insert({ar[2].first,i});
		}
	}
	cout << sz(ans) << "\n";
	for(auto i : ans)
	cout << i.first << " " << i.second << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

