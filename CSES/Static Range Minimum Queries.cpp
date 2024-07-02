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
	Node() : mn(1e10) {}
	// Node() : mn(), mx() {}
};
 
struct Segtree{
	ll N;
	vector<struct Node> tree;
	void init(ll n,vector<ll> &ar){
		tree.resize(4*n + 1);
		N = n;
		build(0,1,n,ar);
	}
	
	void merge(struct Node &cur, struct Node &l, struct Node &r){
		cur.mn = min(l.mn,r.mn);
	}
	
	void build(ll node, ll L, ll R, vector<ll> &ar){
		if(L == R){
			tree[node].mn = ar[L];
			return ;
		}
		ll mid = (L + R) / 2;
		build(2*node + 1,L,mid,ar);
		build(2*node + 2, mid+1, R, ar);
		merge(tree[node],tree[2*node+1], tree[2*node+2]);
	}
	
	struct Node query(ll node, ll s, ll e, ll L, ll R){
		if(L<=s && R>=e)
			return tree[node];
		ll mid = (s + e)/2;
		struct Node q1,q2,ans;
		if(L <= mid)
			q1 = query(2*node+1,s,mid,L,R);
		if(R > mid)
			q2 = query(2*node+2,mid+1,e,L,R);
		merge(ans,q1,q2);
		return ans;
	}
};
 
void solve(){
	ll n,q;
	cin >> n >> q;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
	}
	struct Segtree S;
	S.init(n,ar);
	while(q--){
		ll a,b;
		cin >> a >> b;
		struct Node ans = S.query(0,1,n,a,b);
		cout << ans.mn << "\n";
	}
}
 
int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}