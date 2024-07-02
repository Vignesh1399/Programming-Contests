#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1);
	vector<pair<ll,ll>> ans;
	multiset<ll> s;
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		s.insert({i,i});
	}
	vector<bool> block(n+1,0),v(n+1,1);
	vector<ll> match(n+1,0);
	bool flag = 1;
	ll p1 = 1,p2 = 2,p3 = 2;
	while(p1<=n){
		if(ar[p1] == 2){
			while(p2<=n && (block[p2] || ar[p2]!=1))
			p2++;
			if(p2>n){
				flag = 0;
				break;
			}
			match[p1] = p2;
			block[p2] = 1;
		}
		if(ar[p1] == 3){
			while(p3<=n && (block[p3] || ar[p3] == 0))
			p3++;
			if(p3>n){
				flag = 0;
				break;
			}
			match[p1] = p3;
			block[p3] = 1;
		}
		p1++;
		p2 = max(p2,p1+1);
		p3 = max(p3,p1+1);
	}
	if(!flag){
		cout << -1 << "\n";
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(ar[i] == 1){
			if(v[i])
			ans.eb(*s.begin(),i);
			s.erase(*s.begin());
		}
		if(ar[i] == 2 || ar[i] == 3){
			ans.eb(*s.begin(),i);
			ans.eb(*s.begin(),match[i]);
			if(ar[i] == 3)
			v[match[i]] = 1;
			if(ar[i] == 2)
			v[match[i]] = 0;
			s.erase(*s.begin());
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

