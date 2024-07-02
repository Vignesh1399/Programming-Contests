#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m;
	vector<ll> ar(n+1,0),p(n+1,0),pr(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=1;i<=m;i++){
		cin >> p[i];
		pr[p[i]]++;
	}
	for(ll i=1;i<=n;i++)
	pr[i] += pr[i-1];
	vector<ll> br = ar;
	sort(br.begin(),br.end());
	ll ptr = n;
	bool flag = 0;
	while(ptr>=1){
		for(ll i=ptr;i>=1;i--){
			if(ar[i] == br[ptr]){
				if(ptr - i <= pr[ptr-1] - pr[i-1]){
					
				}
				else{
					flag = 1;
					//cout << i << " " << ptr << " ";
				}
				for(ll j=i;j<=ptr-1;j++){
					swap(ar[j],ar[j+1]);
				}
				break;
			}
		}
		ptr--;
	}
	if(flag)
	cout << "NO";
	else
	cout << "YES";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

