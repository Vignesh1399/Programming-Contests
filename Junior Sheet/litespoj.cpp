#include <bits/stdc++.h>
#define ll int
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct data{
	ll x,y;
	data(){
		x = 0;
		y = 1;
	}
};
struct segtree{
	vector<struct data> S;
	vector<ll> push;
	ll n;
	void merge(struct data &cur,struct data &left, struct data &right){
		cur.x = left.x + right.x;
		cur.y = left.y + right.y;
	}
	void build(ll node, ll s, ll e){
		if(s == e){
			struct data d;
			S[node] = d;
			return ;
		}
		ll mid = (s+e)/2;
		build(2*node,s,mid);
		build(2*node+1,mid+1,e);
		merge(S[node],S[2*node],S[2*node+1]);
	}
	void init(ll m){
		n = 4*(m+1);
		push.assign(n,0);
		S.resize(n);
		build(1,1,m);
	}
	void prop(ll node, struct data &cur, ll s, ll e){
		push[node] %= 2;
		if(push[node] == 0)
		return ;
		if(s != e){
			push[2*node] += push[node];
			push[2*node+1] += push[node];
		}
		if(push[node] == 1)
		swap(cur.x,cur.y);
		push[node] = 0;
	}
	void update(ll node, ll s, ll e, ll L, ll R){
		prop(node,S[node],s,e);
		if(L>e || R<s)
		return ;
		if(L<=s && R>=e){
			push[node]++;
			prop(node,S[node],s,e);
			return ;
		}
		ll mid = (s+e)/2;
		update(2*node,s,mid,L,R);
		update(2*node+1,mid+1,e,L,R);
		merge(S[node],S[2*node],S[2*node+1]);
	} 
	struct data query(ll node, ll s, ll e, ll L, ll R){
		prop(node,S[node],s,e);
		struct data ans;
		if(L>e || R<s)
		return ans;
		if(L<=s && R>=e){
			push[node]++;
			prop(node,S[node],s,e);
			return S[node];
		}
		ll mid = (s+e)/2;
		ans = query(2*node,s,mid,L,R);
		ans.x += query(2*node+1,mid+1,e,L,R).x;
		merge(S[node],S[2*node],S[2*node+1]);
		return ans;
	}
};
void solve(){
	ll n,q;
	cin >> n >> q;
	segtree s;
	s.init(n);
	while(q--){
		ll type,a,b;
		struct data ans;
		cin >> type >> a >> b;
		if(!type){
			s.update(1,1,n,a,b);
		}
		else{
			ans = s.query(1,1,n,a,b);
			cout << ans.x << "\n";
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

