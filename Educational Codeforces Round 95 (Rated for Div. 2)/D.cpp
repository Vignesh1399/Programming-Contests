#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,q,t,x;
	cin >> n >> q;
	set<ll> points;
	multiset<ll> gaps;
	gaps.insert(0);
	vector<ll> ar(n);
	for(auto &i : ar){
		cin >> i;
		points.insert(i);
	}
	sort(ar.begin(),ar.end());
	for(ll i=1;i<sz(ar);i++)
	gaps.insert(ar[i] - ar[i-1]);
	cout << *(--points.end()) - *(points.begin()) - *(--gaps.end()) << "\n";
	while(q--){
		cin >> t >> x;
		if(t == 1){
			points.insert(x);
			auto itr = points.upper_bound(x);
			auto itl = points.lower_bound(x);
			if(itr != points.end()){
				gaps.insert(*itr - x);
			}
			if(itl != points.begin()){
				--itl;
				gaps.insert(x - *itl);
				if(itr != points.end())
				gaps.erase(gaps.find(*itr - *itl));
			}
		}
		else{
			auto itr = points.upper_bound(x);
			auto itl = points.lower_bound(x);
			if(itr != points.end()){
				gaps.erase(gaps.find(*itr - x));
			}
			if(itl != points.begin()){
				--itl;
				gaps.erase(gaps.find(x - *itl));
				if(itr != points.end())
				gaps.insert(*itr - *itl);
			}
			points.erase(x);
		}
		if(sz(points))
		cout << *(--points.end()) - *(points.begin()) - *(--gaps.end()) << "\n";
		else
		cout << 0 << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

