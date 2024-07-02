#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,n,a,b,m;
    cin>>n;
    vector<ll> ar(n+1,0),pr(n+1,LLONG_MAX),sf(n+2,LLONG_MAX);
    for(ll i=1;i<=n;i++){
        cin>>ar[i];
        pr[i]=pr[i-1]&(~ar[i]);
    }
    for(ll i=n;i>=1;i--){
        sf[i]=sf[i+1]&(~ar[i]);
    }
    ll ans=-1,idx=0;
    for(ll i=1;i<=n;i++){
        
        if((pr[i-1]&ar[i]&sf[i+1])>ans){
            ans=pr[i-1]&ar[i]&sf[i+1];
            idx=i;
        }
    }
    cout<<ar[idx]<<" ";
    for(ll i=1;i<=n;i++){
        if(i!=idx){
            cout<<ar[i]<<" ";
        }
    }
    return 0;
}

