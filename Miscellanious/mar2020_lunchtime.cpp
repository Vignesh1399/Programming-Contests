#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;

void solve(){
    ll n,a,x,k;
    cin >> n;
    ll cs = 1, csum = 0, last = 0;
    vector<ll> diff(2,0);
    while(n--){
        ll t;
        cin >> t;
        if(t == 1){
            cin >> a >> x;
            csum += a* x;
            if (a == cs)
            last += x; 
            diff[1] += x;    
            if(a<cs)
            diff[a+1] -= x;
        }
        else if(t == 2){
            cin >> k;
            cs++;
            csum += k;
            diff.pb(k - last);
            last = k;
        }
        else{
            csum -= last;
            last = last - diff[cs];
            cs--;
            diff.pop_back();
        }
        cout<<fixed<<setprecision(10);
        double ans = (csum*1.0)/cs; 
        cout<<ans<<"\n";
    }
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

