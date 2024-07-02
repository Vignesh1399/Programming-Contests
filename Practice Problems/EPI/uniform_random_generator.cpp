#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

int random(){
    return rand() % 2;
}

int uniform_random_generator(int a, int b) {
    int range_size = b - a + 1;
    int num_bits = 0;
    int cur_num = b-a+1;
    while(cur_num > range_size-1) {
        cur_num = 0;
        for(int bit=0; (1 << bit) < range_size; ++bit) {
            int r = random();
            //cout << r << " ";
            cur_num = ((cur_num << 1) | r);          
        }
    }
    return a + cur_num;
}

void solve() {
	cout << uniform_random_generator(8,8) << "\n";
	cout << uniform_random_generator(1e5,1e6) << "\n";
}

int main() {
    FAST;
    ll t = 1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

