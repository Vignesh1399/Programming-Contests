#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;

void solve(){
    ll n,m;
    cin>>n>>m;
    ll cl=m,ch=m;
    vector<ll> t(n+1,0),l(n+1,0),h(n+1,0);
    for(ll i=1;i<=n;i++)
    cin>>t[i]>>l[i]>>h[i];
    for(ll i=1;i<=n;i++){
        cl-=(t[i]-t[i-1]);
        ch+=(t[i]-t[i-1]);
        if(l[i]>ch || h[i]<cl){
            cout<<"NO\n";
            return ;
        }
        else{
            cl=max(cl,l[i]);
            ch=min(ch,h[i]);
        }
    }
    cout<<"YES\n";
}

int main() {
    FAST;
    ll t=1,n,a,b,m;
    cin>>t;
    while(t--){
    	solve();	
    }
    return 0;
}

