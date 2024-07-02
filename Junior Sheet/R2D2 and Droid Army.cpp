#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;


/* https://github.com/Ashishgup1/Competitive-Coding/blob/master/Segment%20Tree.cpp */
struct data{
	ll mn;
	data() : mn(0) {};
};

struct SegTree{
	ll N;
	vector<struct data> st;
	vector<ll> ar;
	
	void init(ll n){
		// To initialize
		N = n;
		st.resize(4*N+1);
		ar.resize(n+1);
	}
	void merge(struct data &cur, struct data &l, struct data &r){
		// Use any merging property
		cur.mn = max(l.mn , r.mn);
	}
	
	void build(ll node, ll s, ll e){
		if(s == e){
			st[node].mn = ar[s];
			return ;
		}
		ll mid = (s+e)/2;
		build(2*node,s,mid);
		build(2*node+1,mid+1,e);
		merge(st[node], st[2*node], st[2*node+1]);
	}
	struct data query(ll node, ll s, ll e, ll L, ll R){
		if(s>R || e<L){
			struct data d;
			return d;
		}
		else if(s>=L && e<=R)
			return st[node];
		ll mid = (s+e)/2;
		struct data p1 = query(2*node,s,mid,L,R);
		struct data p2 = query(2*node+1,mid+1,e,L,R);
		struct data ans;
		merge(ans,p1,p2);
		return ans;
	}
	void update(ll node, ll s, ll e, ll idx, ll val){
		if(s == e){
			st[node].mn += val;
			ar[s] += val;
			return ;
		}
		ll mid = (s+e)/2;
		if(idx<=mid)
		update(2*node,s,mid,idx,val);
		else
		update(2*node+1,mid+1,e,idx,val);
		merge(st[node],st[2*node],st[2*node+1]);
	}
};

void solve(){
	ll n,m,k;
	cin >> n >> m >> k;
	vector<vector<ll>> ar(n+1,vector<ll>(m+1,-1));
	for(ll i=1;i<=n;i++){
		for(ll j =1;j<=m;j++)
			cin >> ar[i][j];
	}	
	// Initialise Segment Tree
	SegTree s[6];
	for(ll j=1;j<=m;j++){
		s[j].init(n);
		for(ll i=1;i<=n;i++){
			s[j].ar[i] = ar[i][j];
		}
		s[j].build(1,1,n);
	}
	ll l = 1, r = 1;
	ll ans_sz = 0;
	vector<ll> ans;
	while(r<=n){
		vector<ll> cur_shots;
		ll total_shots = 0;
		for(ll j=1;j<=m;j++){
			struct data Q = s[j].query(1,1,n,l,r);
			cur_shots.pb(Q.mn);
			total_shots += Q.mn;
		}
		if(total_shots <= k){
			if(r-l+1>ans_sz){
				ans = cur_shots;
				ans_sz = r-l+1;
			}
			r++;
		}
		else
		++l;
		if(l>r)
		r = l;
	}
	if(!sz(ans)){
		for(ll i=1;i<=m;i++)
		cout << 0 << " ";
	}
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

