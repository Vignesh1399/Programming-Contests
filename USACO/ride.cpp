/*
ID: vignesh38
TASK: ride
LANG: C++14                 
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b,ans;
    fin >> a >> b;
    int p1=1,p2=1;
    for(int i=0;a[i];i++)
    p1= p1 * (a[i]-'A' + 1) % 47;
    for(int i=0;b[i];i++)
    p2= p2 *(b[i]-'A' + 1) % 47;
    if(p1 == p2)
    ans = "GO";
    else
    ans = "STAY";
    fout << ans << endl;
    return 0;
}