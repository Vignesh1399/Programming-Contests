
/* https://github.com/Ashishgup1/Competitive-Coding/blob/master/Segment%20Tree.cpp */
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
			struct data d = {0};
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