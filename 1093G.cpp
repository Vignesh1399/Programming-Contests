#include <bits/stdc++.h>
#define ll int
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
struct point{
	vector<ll> val = {0,0,0,0,0};
};
struct data{
	ll mn;
	ll mx;
	data(){
		mn = 1e9;
		mx = -1e9;
	}
};
struct Segtree{
	ll N;
	vector<struct data> st;
	void init(ll n){
		N = n;
		st.resize(4*n+2);
	}
	void merge(struct data &cur,struct data &l, struct data &r){
		cur.mn = min(l.mn,r.mn);
		cur.mx = max(l.mx,r.mx);
	}
	void build(ll node, ll s, ll e, vector<ll> &ar){
		if(s == e){
			st[node].mn = ar[s];
			st[node].mx = ar[s];
			return ;
		}
		ll mid = (s+e)/2;
		build(2*node,s,mid,ar);
		build(2*node+1,mid+1,e,ar);
		merge(st[node],st[2*node],st[2*node+1]);
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
			st[node].mn = val;
			st[node].mx = val;
			return ;
		}
		ll mid = (s+e)/2;
		if(idx<=mid){
			update(2*node,s,mid,idx,val);
		}
		else
			update(2*node+1,mid+1,e,idx,val);
		merge(st[node],st[2*node],st[2*node+1]);
	}
};
void buildCoefficient(vector<ll> cof[], ll k){
	ll total = (1<<k);
	for(ll i=0;i<total;i++){
		ll temp = i;
		for(ll j=0;j<k;j++){
			ll b = (temp&1);
			if(b == 0)
			cof[i].eb(-1);
			else
			cof[i].eb(1);
			temp /= 2;
		}
	}
}
void solve(){
	// Getting The Input
	ll n,k,q;
	cin >> n >> k;
	vector<struct point> ar(n);
	// n*k
	for(ll i=0;i<n;i++){
		for(ll j=0;j<k;j++)
		cin >> ar[i].val[j];		
	}
	// nk
	// Building coefficient array
	vector<ll> cof[32];
	buildCoefficient(cof,k);
	// Build 2^k segment trees with the array
	Segtree S[32];
	ll total = (1<<k);
	//2^k*(n*k+n)
	for(ll i=0;i<total;i++){
		S[i].init(n);
		vector<ll> initial = {0};
		for(ll j=0;j<n;j++){
			ll v = 0;
			for(ll x=0;x<k;x++){
				v += cof[i][x] * ar[j].val[x];
			}
			initial.eb(v);
		}
		S[i].build(1,1,n,initial);
	}
	// Get Queries
	//q*2^k*k*logn
	cin >> q;
	while(q--){
		ll o;
		cin >> o ;
		if(o == 1){
			ll idx;
			struct point p;
			cin >> idx;
			for(ll j=0;j<k;j++)
			cin >> p.val[j];
			for(ll i=0;i<total;i++){
				ll v = 0;
				for(ll x=0;x<k;x++)
				v += p.val[x] * cof[i][x];
				S[i].update(1,1,n,idx,v);
			}
		}
		else{
			ll L,R;
			cin >> L >> R;
			ll ans = -1e9;
			for(ll i=0;i<total;i++){
				struct data d = S[i].query(1,1,n,L,R);
				ans = max(ans,d.mx-d.mn);
			}
			cout << ans << "\n";
		}
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

