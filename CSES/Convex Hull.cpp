#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct point{
	ll x,y;
};

bool cmp(struct point a, struct point b){
	if(a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

bool cw(struct point a, struct point b, struct point c){
	struct point v1 = {b.x - a.x,b.y - a.y};
	struct point v2 = {c.x - b.x,c.y -b.y};
	return (v1.x * v2.y - v1.y * v2.x) < 0ll;
}

bool ccw(struct point a, struct point b, struct point c){
	struct point v1 = {b.x - a.x,b.y - a.y};
	struct point v2 = {c.x - b.x,c.y -b.y};
	return (v1.x * v2.y - v1.y * v2.x) > 0ll;
}

void solve(){
	ll n;
	cin >> n;
	vector<struct point> p(n);
	for(auto &i : p){
		cin >> i.x >> i.y;
	}
	sort(p.begin(),p.end(),cmp);
	struct point p1 = p[0];
	struct point p2 = p.back();
	vector<struct point> up,down;
	up.pb(p1);
	down.pb(p1);
	for(ll i=1;i<n;i++){
		if(i == n-1 || cw(p1,p[i],p2)){
			while(sz(up)>=2 && ccw(up[sz(up)-2],up[sz(up)-1],p[i]))
				up.pop_back();
			up.pb(p[i]);
		}
		if(i == n-1 || !cw(p1,p[i],p2)){
			while(sz(down)>=2 && cw(down[sz(down)-2],down[sz(down)-1],p[i])){
				down.pop_back();
			}
			down.pb(p[i]);
		}
	}
	p.clear();
	for(ll i=0;i<sz(up);i++)
		p.pb(up[i]);
	for(ll i=1;i<sz(down)-1;i++)
		p.pb(down[i]);
	cout << sz(p) << "\n";
	for(auto i : p)
	cout << i.x << " " << i.y << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

