#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void reorder(vector<int> &ar, int pivot) {
    int place = 0, search = 0;
    pivot = ar[pivot];
    while(search < sz(ar)) {
        if(ar[place] < pivot)
            ++place;
        else {
            if(ar[search] < pivot){
                swap(ar[place], ar[search]);
                place++;
            }
            search++;
        }
        search = max(search, place);
    }
    search = place;
    while(search < sz(ar)) {
        if(ar[place] == pivot)
            ++place;
        else {
            if(ar[search] == pivot){
                swap(ar[place], ar[search]);
                place++;
            }
            search++;
        }
        search = max(search, place);
    }
}

void solve() {
    //vector<int> ar = {2,2,3,5,1,6,2,1};
    vector<int> ar = {2,2,3,5,1,6,2,2};
    int pivot = 2;
	reorder(ar, pivot);
	for(auto i : ar)
	cout << i << " ";
}

int main() {
    FAST;
    ll t = 1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

