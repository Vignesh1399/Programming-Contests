#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

bool ok(ll x, vector<ll> &ar, vector<ll> &qr){
	ll cntl,cntr;
	cntl = cntr = 0;
	for(ll i=0;i<sz(ar);i++){
		if(ar[i]<=x)
		cntl++;
		else
		cntr++;
	}
	for(ll i=0;i<sz(qr);i++){
		if(qr[i]>0){
			if(qr[i]<=x)
			cntl++;
			else
			cntr++;
		}
		else{
			if(abs(qr[i])<=cntl)
			cntl--;
			else
			cntr--;
		}
	}
	return cntl>0;
}

void solve(){
	ll n,q,cnt=0;
	cin >> n >> q;
	cnt = n;
	vector<ll> ar(n,0),qr(q,0);
	for(ll i=0;i<n;i++){
		cin >> ar[i];
	}
	for(ll i=0;i<q;i++){
		cin >> qr[i];
		if(qr[i]<0)
		cnt--;
		else
		cnt++;
	}
	if(!cnt){
		cout << cnt; 
		return ;
	}
	ll lb = 1,ub = n;
	while(lb <= ub){
		ll mid = lb+ub >> 1;
		bool yes = ok(mid,ar,qr);
		if(yes)
		ub = mid-1;
		else
		lb = mid+1;
		//cout << mid << " " << yes << "\n"; 
	}
	cout << lb ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

