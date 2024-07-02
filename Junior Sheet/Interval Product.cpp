#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct data{
	ll mn;
	data() : mn(-2) {} ;
};

struct SegTree{
	vector<data> tree;
	vector<data> ar;
	ll N;
	
	void init(ll n){
		N = 4*n + 1;
		tree.resize(N);
		ar.resize(n+1);
	}
	
	void merge(struct data &cur, struct data &l, struct data &r){
		cur.mn = l.mn * r.mn;
	}
	
	void build(ll node, ll s, ll e){
		if( s == e )
		tree[node] = ar[s];
		else{
			ll mid = (s+e)/2;
			build(2*node, s, mid);
			build(2*node+1, mid+1, e);
			merge(tree[node],tree[2*node], tree[2*node+1]);
		}
	}
	
	void update(ll node, ll s, ll e, ll idx, struct data &val){
		if( s == e ){
			tree[node] = val;
			ar[idx] = val;
			return ;
		}
		ll mid = (s + e)/2;
		if(mid >= idx)
		update(2*node, s, mid, idx, val);
		else
		update(2*node+1, mid+1, e, idx, val);
		merge(tree[node],tree[2*node], tree[2*node+1]);
	}
	
	struct data query(ll node, ll s, ll e, ll L, ll R){
		if(R<s || L>e){
			data sample;
			sample.mn = 1;
			return sample;
		}
		if(L<=s && R>=e){
			return tree[node];
		}
		ll mid = (s+e)/2;
		struct data l = query(2*node, s, mid, L, R);
		struct data r = query(2*node+1, mid+1, e, L, R);
		struct data ans;
		merge(ans,l,r);
		return ans;
	}
};

void solve(){
	ll n;
	while(cin >> n){
		ll q;
		cin >> q;
		SegTree S;
		S.init(n);
		for(ll i=1;i<=n;i++){
			cin >> S.ar[i].mn;
			if(S.ar[i].mn>0)
			S.ar[i].mn = 1;
			else if(S.ar[i].mn<0)
			S.ar[i].mn = -1;
			else
			S.ar[i].mn = 0;
			
		}
		S.build(1,1,n);
		while(q--){
			char type;
			cin >> type;
			ll l,r;
			cin >> l >> r;
			data ans;
			if(type == 'P'){
				ans = S.query(1,1,n,l,r);
				if(ans.mn>0)
				cout<<"+";
				else if(ans.mn<0)
				cout<<"-";
				else
				cout<<"0";
			}
			else{
				if(r>0)
				r = 1;
				else if(r<0)
				r = -1;
				else
				r = 0;
				ans.mn = r;
				S.update(1,1,n,l,ans);
			}
		}
		cout << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

