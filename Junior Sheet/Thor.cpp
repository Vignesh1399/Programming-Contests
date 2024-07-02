#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,q;
	cin >> n >> q;
	queue<ll> ar[n+1];
	queue<pair<ll,ll>> Q;
	vector<bool> mark(3e5+1,0);
	ll unread=0,event=1;
	while(q--){
		ll t,x;
		cin >> t >> x;
		if(t==1){
			Q.push({event,x});
			ar[x].push(event);
			event++;
			unread++;
		}
		else if(t==2){
			while(!ar[x].empty()){
				ll v = ar[x].front();
				if(!mark[v]){
					mark[v] = 1;
					unread--;
				}
				ar[x].pop();
			}
		}
		else{
			while(!Q.empty() && Q.front().first <= x){
				pair<ll,ll> p = Q.front();
				if(!mark[p.first]){
					unread--;
					mark[p.first] = 1;
				}
				Q.pop();
			}
		}
		cout<<unread<<"\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

