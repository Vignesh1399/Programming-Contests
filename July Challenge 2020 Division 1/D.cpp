#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
vector<bool> v;
void constructRLTree(vector<ll> rltree[], vector<ll> &h, ll n){
	stack<ll> s;
	vector<ll> ngr(n+1,0);
	for(ll i=1;i<=n;i++){
		if(s.empty())
		s.push(i);
		else{
			while(!s.empty() && h[i]>h[s.top()]){
				ngr[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}
	while(!s.empty()){
		ngr[s.top()] = s.top();
		s.pop();
	}
	for(ll i=n;i>=1;i--){
		//if(ngr[i] != i){
			rltree[0].pb(ngr[i]);
			rltree[ngr[i]].pb(i);
		//}
	}
}

void constructLRTree(vector<ll> lrtree[], vector<ll> &h, ll n){
	vector<ll> ngl(n+1,0);
	stack<ll> s;
	for(ll i=n;i>=1;i--){
		if(s.empty())
			s.push(i);
		else{
			while(!s.empty() && h[i]>h[s.top()]){
				ngl[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}	
	while(!s.empty()){
		ngl[s.top()] = s.top();
		s.pop();
    }
    for(ll i=1;i<=n;i++){
    	//if(ngl[i] != i){
    		lrtree[0].pb(ngl[i]);
    		lrtree[ngl[i]].pb(i);
		//}
    }
}
void doEulerTour(ll root, vector<ll> g[], vector<ll> &entr, vector<ll> &ext, ll &timer){
	//cout << root << " ";
	entr[root] = timer++;
	v[root] = 1;
	for(auto i : g[root])
		if(!v[i])
		doEulerTour(i,g,entr,ext,timer);
	ext[root] = timer++;
	//cout << root << " ";
}
struct data{
	ll mn;
	data() : mn(0) {};
};

struct SegTree{
	ll N;
	vector<data> st;
	
	void init(ll n){
		// To initialize
		N = n;
		st.resize(4*N+1);
	}
	void merge(data &cur, data &l, data &r){
		// Use any merging property
		cur.mn = l.mn + r.mn;
	}
	
	void build(ll node, ll s, ll e){
		if(s == e){
			st[node].mn = 0;
			return ;
		}
		ll mid = (s+e)/2;
		build(2*node,s,mid);
		build(2*node+1,mid+1,e);
		merge(st[node], st[2*node], st[2*node+1]);
	}
	data query(ll node, ll s, ll e, ll L, ll R){
		if(s>R || e<L){
			struct data d;
			d.mn = 0;
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
	ll n,q,timer=0;
	cin >> n >> q;
	ll nodes = 2*n + 2;
	vector<ll> ar(n+1,0),h(n+1,0),rltree[n+1],lrtree[n+1];
	vector<ll> entr1(n+1,0),ext1(n+1,0),entr2(n+1,0),ext2(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> h[i];
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	constructRLTree(rltree,h,n);
	constructLRTree(lrtree,h,n);
	v.assign(n+1,0);
	doEulerTour(0,rltree,entr1,ext1,timer);
	timer = 0;
	v.assign(n+1,0);
	doEulerTour(0,lrtree,entr2,ext2,timer);
	SegTree Srl,Slr;
	nodes--;
	Slr.init(nodes);
	Srl.init(nodes);
	for(ll i=0;i<=n;i++){
		Srl.update(1,1,nodes,entr1[i],ar[i]);
		Slr.update(1,1,nodes,entr2[i],ar[i]);
		Srl.update(1,1,nodes,ext1[i],-ar[i]);
		Slr.update(1,1,nodes,ext2[i],-ar[i]);
	}
	while(q--){
		ll type,b,c;
		cin >> type >> b >> c;
		if(type == 1){
			Srl.update(1,1,nodes,entr1[b],c);
			Slr.update(1,1,nodes,entr2[b],c);
			Srl.update(1,1,nodes,ext1[b],-c);
			Slr.update(1,1,nodes,ext2[b],-c);
			continue;
		}
		data ans;
		if(b>c){
			if(entr1[b] <= entr1[c] && ext1[b] >= ext1[c])
			ans = Srl.query(1,1,nodes,entr1[b],entr1[c]); 
			else
			ans.mn = -1;
		}
		else{
			if(entr2[b] <= entr2[c] && ext2[b] >= ext2[c])
			ans = Slr.query(1,1,nodes,entr2[b],entr2[c]); 
			else
			ans.mn = -1;
		}
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

