#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll findk(vector<ll> &ar){
    sort(ar.begin(),ar.end());
    ll n=ar.size();
    if(n==0)
    return 1;
    return (ar[0]+ar[n-1])/2;
}

void solve(){
	ll n;
    cin>>n;
    vector<ll> v(n+2,0),ar(n+2,0),br;
    for(ll i=1;i<=n;i++){
        cin>>ar[i];
    }
    for(ll i=1;i<=n;i++){
        if(ar[i-1]==-1||ar[i+1]==-1){
            if(ar[i]!=-1 && !v[i]){
                br.pb(ar[i]);
                v[i]=1;
            }
        }
    }
    ll k=findk(br);
    ll ans=0;
    for(ll i=2;i<=n;i++){
        ll ti=ar[i];
        ll ti1=ar[i-1];
        if(ar[i]==-1){
            ti=k;
        }
        if(ar[i-1]==-1)
        ti1=k;
        ans=max(ans,abs(ti-ti1));
    }
    
    cout<<ans<<" "<<k<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,n,a,b,m;
    cin>>t;
    while(t--){
    	solve();
		
    }
    return 0;
}

