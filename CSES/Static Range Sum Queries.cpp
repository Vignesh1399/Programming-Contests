#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct Node{
	ll mn;
	Node() : mn(0) {}
};

struct Fenwick{
	ll N;
	vector<struct Node> tree;
	void init(ll n,vector<ll> &ar){
		tree.resize(n+1);
		N = n;
		for(ll i=1;i<=n;i++)
			update(i, ar[i]);
	}
	
	void update(ll idx, ll val){
		for(ll i=idx;i<=N;i += i&(-i)){
			tree[i].mn += val;
		}
	}
	
	ll Sum(ll x){
		struct Node ans;
		for(ll i=x;i>0;i -= i &(-i))
			ans.mn += tree[i].mn;
		return ans.mn;
	}
};

void solve(){
	ll n,q;
	cin >> n >> q;
	vector<ll> ar(n+1);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	struct Fenwick F;
	F.init(n,ar);
	while(q--){
		ll a,b;
		cin >> a >> b;
		cout << F.Sum(b) - F.Sum(a-1) << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

