#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;

void solve(){
    ll n,k,len=0,s=1;
    cin>>n>>k;
    set<ll> dis;
    vector<ll> ar(n+1,0),seen(k+1,0);
    for(ll i=1;i<=n;i++){
        cin>>ar[i];
        dis.insert(ar[i]);
        if(sz(dis)<k)
        len=max(len,i-s+1);
        else {
        len=max(len,i-seen[ar[s]]);
        dis.erase(ar[s]);
        s=seen[ar[s]]+1;
        }
        seen[ar[i]]=i;
    }
    cout<<len<<"\n";
}

int main() {
    FAST;
    ll t=1,n,a,b,m;
    cin>>t;
    while(t--) solve();	
    return 0;
}

