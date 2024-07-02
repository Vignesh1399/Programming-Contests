#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> ar(n+1,0),w(k+1,-1e10);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	ll itrw = 0,itr = 0;
	for(ll i=1;i<=k;i++){
		ll x;
		cin >> x;
		if(x>1)
		w[++itrw] = x;
		else
		++itr;
	}
	sort(ar.begin()+1,ar.end());
	sort(w.begin()+1,w.end(),greater<ll>());
	deque <ll> q;
	for(ll i=1;i<=n;i++)
	q.push_back(ar[i]);
	ll ans = 0;
	for(ll i=1;i<=itr;i++){
		ll m = q.back();
		q.pop_back();
		ll c = 1,mn = m;
		ans += mn+m;
	}
	for(ll i=1;i<=itrw;i++){
		ll m = q.back();
		q.pop_back();
		ll c = 1,mn = m;
		while(c<w[i]){
			++c;
			mn = min(mn,q.front());
			q.pop_front();
		}
		ans += mn+m;
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

