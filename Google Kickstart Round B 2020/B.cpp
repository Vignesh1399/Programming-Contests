#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(ll k){
	ll x,y,xn=0,yn=0,flag=0;
	cin >> x >> y;
	string s="";
	if(x<0){
	x = -x;
	xn=1;
	}
	if(y<0){
	y = -y;
	yn=1;
	}
	for(ll i=0;i<=30;i++){
		ll xb = (x>>i)&1;
		ll yb = (y>>i)&1;
		if(xb!=yb && xb && xn)
		s+="W";
		else if(xb!=yb && yb && yn)
		s+="S";
		else if(xb!=yb && xb)
		s+="E";
		else if(xb!=yb && yb)
		s+="N";
		else if(xb && yb)
		flag=1;
	}
	if(flag)
	cout<<"Case #"<<k<<": "<<"IMPOSSIBLE\n";
	else
	cout<<"Case #"<<k<<": "<<s<<"\n";
}

int main() {
    FAST;
    ll t=1,k=1;
    cin>>t;
    while(t--) solve(k++);	
    return 0;
}

