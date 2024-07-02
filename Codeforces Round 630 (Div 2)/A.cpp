#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;
bool check(ll x,ll y,ll x1,ll y1,ll x2,ll y2){
	return x>=x1 && x<=x2 && y>=y1 && y<=y2;
}

void solve(){
	ll a,b,c,d,x1,y1,x2,y2,x,y;
	cin>>a>>b>>c>>d;
	cin>>x>>y>>x1>>y1>>x2>>y2;
	ll h1=1,h2=0,v1=1,v2=0;
	//h1 = check(x + b,y,x1,y1,x2,y2);
	if( a && a == b){
	h1 = check(x+1,y,x1,y1,x2,y2);
	//v1 = check(x,y+1,x1,y1,x2,y2);
	h1 = h1 || check(x-1,y,x1,y1,x2,y2);
	//v1 = v1 || check(x,y-1,x1,y1,x2,y2);
	
	}
	if( c && c ==  d){
	v1 = check(x,y+1,x1,y1,x2,y2);
	//h1 = h1 || check(x-1,y,x1,y1,x2,y2);
	v1 = v1 || check(x,y-1,x1,y1,x2,y2);
	}
	h2 = check(x+b-a,y,x1,y1,x2,y2);
	v2 = check(x,y+d-c,x1,y1,x2,y2);
	if(h1 && h2 && v1 && v2)
	cout<<"YES";
	else
	cout<<"NO";
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

