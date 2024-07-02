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
	ll x,y,z;
	data() : x(0),y(0),z(0) {};
};

struct Segtree{
	vector<struct data> S;
	vector<ll> push;
	ll n;
	void init(ll m,vector<struct data> &ar){
		n = 4*m+4;
		S.resize(n);
		push.assign(n,0);
		build(1,1,m,ar);
	}
	void merge(struct data &cur, struct data &left, struct data &right){
		cur.x = left.x + right.x;
		cur.y = left.y + right.y;
		cur.z = left.z + right.z;
	}
	void build(ll node, ll s, ll e, vector<struct data> &ar){
		if(s == e){
			S[node] = ar[s];
			return ;
		}
		ll mid = (s+e)/2;
		build(2*node,s,mid,ar);
		build(2*node+1,mid+1,e,ar);
		merge(S[node],S[2*node],S[2*node+1]);
	}
	void propagate(ll node,struct data &cur,ll s, ll e){
		push[node] %= 3;
		if(push[node] == 0)
		return ;
		if(s != e){
			push[2*node] += push[node];
			push[2*node+1] += push[node];
		}
		if(push[node] == 1){
			swap(cur.x,cur.z);
			swap(cur.z,cur.y);
		}
		else if(push[node]  == 2){
			swap(cur.x,cur.z);
			swap(cur.x,cur.y);
		}
		push[node] = 0;
	}
	void update(ll node, ll s, ll e, ll L, ll R){
		propagate(node,S[node],s,e);
		if(R<s || L>e)
			return ;
		if(L<=s && R>=e){
			push[node] += 1;
			propagate(node,S[node],s,e);
			return ;
		}
		ll mid = (s+e)/2;
		//if(L<=mid){
			update(2*node,s,mid,L,R);
		//}
		//if(R>mid){
			update(2*node+1,mid+1,e,L,R);
		//}
		merge(S[node],S[2*node],S[2*node+1]);
	}
	struct data query(ll node, ll s, ll e, ll L, ll R){
		propagate(node,S[node],s,e);
		struct data ans;
		if(R<s || L>e)
			return ans;
		if(s>=L && R>=e){
			return S[node];
		}
		ll mid = (s+e)/2;
		//if(L<=mid)
		ans.x = query(2*node,s,mid,L,R).x;
		//if(R>mid)
		ans.x += query(2*node+1,mid+1,e,L,R).x;
		return ans;
	}
};
void solve(){
	ll n,q;
	cin >> n >> q;
	vector<struct data> ar(n+1);
	for(int i=0;i<sz(ar);i++){
		ar[i].x = 1;
		ar[i].y = ar[i].z = 0;
	}
	Segtree S;
	S.init(n,ar);
	while(q--){
		ll type,a,b;
		struct data ans;
		cin >> type >> a >> b;
		if(!type)
		S.update(1,1,n,a+1,b+1);
		else{
			ans = S.query(1,1,n,a+1,b+1);
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

