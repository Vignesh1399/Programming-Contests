#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;

void solve(){    
    ll n,lbc=0,rbc=0,lbi=0,rbi=0;
    cin>>n;
    string s;
    cin>>s;
    ll sum=0;
    for(ll i=0;s[i];i++){
        if(s[i]=='('){
            lbi=i;
            lbc++;
        }
        else{
            if(rbc==0)
            rbi=i;
            rbc++;
        }
        if(rbc==lbc){
            if(lbi>rbi)
            sum+=abs(lbi-rbi)+1;
            lbc=rbc=0;
            lbi=rbi=i;
        }
    }
    if(lbc!=rbc)
    cout<<-1;
    else
    cout<<sum;
}

int main() {
    FAST;
    ll t=1,n,a,b,m;
    //cin>>t;
    while(t--) solve();	
    return 0;
}
 