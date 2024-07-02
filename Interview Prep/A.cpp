#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll rearr(vector<ll> &ar, ll n){
	ll p1 = 0;
	ll p2 = n-1;
	while(p1<p2){
		if(ar[p1]>0){
			swap(ar[p1],ar[p2]);
			p1++;
		}
		else if(ar[p2]<0){
			swap(ar[p1],ar[p2]);
			p2--;
		}
		else{
			p1++;
			p2--;
		}
	}
	return p1;
}
void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n);
	for(auto &i : ar)
	cin >> i;
	ll p1 = rearr(ar,n);
	for(auto i : ar)
	cout <<i << " ";
	cout << "\n";
	for(ll i=0;i<n && p1<n;i+=2){
		swap(ar[p1],ar[i]);
		p1 ++;
	}
	for(auto i : ar)
	cout <<i << " ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

