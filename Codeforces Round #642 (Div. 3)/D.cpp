#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct cmp{
	bool operator() (const pair<ll,ll> &a, const pair<ll,ll> &b) const{
		ll lena = a.second - a.first + 1;
		ll lenb = b.second - b.first + 1;
		if(lena == lenb) return a.first<b.first;
		return lena > lenb;
	}
};

void solve(){
	ll n;
	cin >> n;
	set<pair<ll,ll>, cmp> s;
	vector<ll> ar(n,0);
	s.insert({0ll,n-1});
	for(ll i=1;i<=n;i++){
		auto it = *s.begin();
		ll idx = (it.first+it.second)/2;
		ar[idx] = i;
		s.erase(*s.begin());
		if(idx-1 >= it.first)
		s.insert({it.first,idx-1});
		if(it.second >= idx+1)
		s.insert({idx+1,it.second});
	}
	for(auto i:ar)
	cout<<i<<" ";
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

