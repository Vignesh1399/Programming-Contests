#include <bits/stdc++.h>
#define ll int
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct point{
	vector<ll> v = {0,0,0,0,0};
};

struct Edge{
	ll u,v,weight;
};

bool comp(struct Edge a, struct Edge b){
	return a.weight<b.weight;
}
ll findset(ll a, vector<ll> &par){
	if(a == par[a])
	return a;
	return par[a] = findset(par[a],par);
}
void unionsets(ll a, ll b, vector<ll> &par, vector<ll> &s){
	a = findset(a,par);
	b = findset(b,par);
	if(a != b){
		if(s[a]>s[b]){
			par[b] = a;
			s[a] += s[b];
		}
		else{
			par[a] = b;
			s[b] += s[a];
		}
	}
}
void solve(){
	ll n,d;
	cin >> n >> d;
	vector<struct point> ar;
	vector<struct Edge> edges;
	vector<ll> s(n+1,1);
	vector<ll> par(n+1);
	for(ll i=0;i<=n;i++)
	par[i] = i;
	// Getting Input -- n*d
	for(ll i=0;i<n;i++){
		struct point p;
		for(ll j=0;j<d;j++)
		cin >> p.v[j];
		ar.eb(p);
	}
	if(n == 1){
		cout << 0 << "\n";
		return ;
	}
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			ll val = 0;
			for(ll k=0;k<5;k++)
			val += abs(ar[j].v[k] - ar[i].v[k]);
			struct Edge e1 = {i,j,-val};
			struct Edge e2 = {j,i,-val};
			edges.eb(e1);
			edges.eb(e2);
		}
	}
	ll cost = 0;
	set<ll> nodes;
	sort(edges.begin(),edges.end(),comp);
	for(Edge e : edges){
		if(findset(e.u,par) != findset(e.v,par)){
			cost += e.weight;
			unionsets(e.u,e.v,par,s);
		}
		/*
		nodes.insert({e.u,e.v});
		if(sz(nodes) == n)
		break;
		*/
	}
	cout << -cost << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

