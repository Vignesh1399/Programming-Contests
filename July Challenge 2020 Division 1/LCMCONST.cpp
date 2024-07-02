#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 1e9+7;

void solve(){
	ll n,m;
	cin >> n >> m;
	vector<ll> x(m+1),r(m+1),y(m+1);
	vector<bool> v(n+1,0);
	vector<pair<ll,ll>> list[n+1],A[n+1],temp;
	for(ll i=1;i<=m;i++){
		cin >> x[i] >> y[i] >> r[i];
		v[x[i]] = 1;
		v[y[i]] = 1;
		temp.clear();
		for(ll j=1;j<=2*r[i];j++){
			ll p,e;
			cin >> p >> e;
			temp.pb({p,e});
		}
		sort(temp.begin(),temp.end());
		ll pw = 0;
		for(ll j=1;j<sz(temp);j++){
			pw += temp[j-1].second;
			if(temp[j].first != temp[j-1].first){
				list[i].pb(temp[j-1].first,pw);
				pw = 0;
			}
		}
		pw += temp[sz(temp)-1].second;
		list[i].pb(temp[sz(temp)-1].first,pw);
		if(!sz(A[x[i]])) A[x[i]] = list[i];
		else{
			ll s1=0,s2=0,pass=0;
			while(s1<sz(A[x[i]]) && s2<sz(list[i])){
				if(A[x[i]][s1].first<list[i][s1].first)
					++s1;
				else if(A[x[i]][s1].first>list[i][s1].first)
					++s2;
				else{
					A[x[i]][s1] = {A[x[i]][s1].first,min(A[x[i]][s1].second,list[i][s2].second)};
					++pass;
					++s1;
					++s2;
				}
			}
			for(ll j=sz(A[x[i]])-1;j>=pass;j++)
				A[x[i]].pop_back();
		}
		if(!sz(A[y[i]])) A[y[i]] = list[i];
		else{
			ll s1=0,s2=0,pass=0;
			while(s1<sz(A[y[i]]) && s2<sz(list[i])){
				if(A[y[i]][s1].first<list[i][s1].first)
					++s1;
				else if(A[y[i]][s1].first>list[i][s1].first)
					++s2;
				else{
					A[y[i]][s1] = {A[y[i]][s1].first,min(A[y[i]][s1].second,list[i][s2].second)};
					++pass;
					++s1;
					++s2;
				}
			}
			for(ll j=sz(A[y[i]])-1;j>=pass;j++)
				A[y[i]].pop_back();
		}
	}
	// Infinity Case
	for(ll i=1;i<=n;i++){
		if(!v[i]){
			cout << -1 << "\n";
			return ;
		}
	}
	// End of Infinity Case
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<sz(A[i]);j++){
			
		}
	}
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

