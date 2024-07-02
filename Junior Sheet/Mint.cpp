#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,t,x,p1=0,p2=0;
	while(1){
		cin >> n >> t;
		if(n==0 && t==0)
		break;
		vector<ll> ar(n+1,0);
		for(ll i=1;i<=n;i++){
			cin >> ar[i];
		}
		for(ll q=1;q<=t;q++){
			cin >> x;
			p1=0;
			p2=1e18;
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll k=j+1;k<=n;k++){
						for(ll m=k+1;m<=n;m++){
							ll a = (ar[i] * ar[j])/(__gcd(ar[i],ar[j]));
							ll b = (ar[k] * ar[m])/(__gcd(ar[k],ar[m]));
							ll c = (a*b)/(__gcd(a,b));
							ll rem = (x)%c;
							p1 = max(p1,x-rem);
							if(rem!=0)
							p2 = min(p2,x+c-rem);
							else
							p2 = min(p2,x);
						}
					}
				}
			}
			cout<<p1<<" "<<p2<<"\n";	
		}
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

