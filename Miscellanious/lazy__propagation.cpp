#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct data{
	ll mn;
	data() : mn(0) {};
};
struct SegTree{
	ll N;
	vector<data> st,lazy;
	void init(ll n){
		N = n;
		st.resize(4*n+1);
		lazy.resize(4*n+1);
	}
	void merge(data &cur, data &l, data &r){
		cur.mn = l.mn + r.mn;
	}
	void update(ll L, ll R, ll val,ll node=1,ll s=1, ll e=N){
		if(lazy[node].mn != 0){
			st[node] += lazy[node] * (e-s+1);
			if(s != e){
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if(L>e || R<s)
		return ;
		if(s<=L && e>=R){
			st[node] += val * (e-s+1);
			if(s != e){
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}
		ll mid = s+e>>1;
		update(L,R,val,2*node,s,mid);
		update(L,R,val,2*node+1,mid+1,e);
		merge(st[node],st[2*node],st[2*node+1]);
	}
	data Query(ll node, ll s, ll e, ll L, ll R)
}

void solve(){
	
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

