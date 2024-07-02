#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

class ChristmasLightsFixing {
  public:
  ll ncr(int n, int r, vector<ll> &fact){
  	ll ans = fact[n]/(fact[n-r]*fact[r]);
  	return ans;
  }
  
  void place(int pos, ll &step, vector<int> &ans, vector<vector<ll>> &dp, int len, int N, int curnum){
  	if(pos == len+1)
  	return ;
  	for(int num=curnum;num<N;num++){
  		ll x = dp[N-num-1][len-pos];
  		if(x<step){
  			step -= x;
  		}
  		else{
  			ans.push_back(num);
  			place(pos+1,step,ans,dp,len,N,num+1);
  			return ;
  		}
  	}
  }
  vector <int> fixingTime(int N, long long step) {
	vector<int> ans;
	int len = 0;
	vector<vector<ll>> dp(51,vector<ll>(51,1));
	for(int i=1;i<=50;i++){
		for(int j=1;j<i;j++)
		dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	}
	while(len<=N){
		len++;
		ll x = dp[N][len];
		if(x<step)
		step -= x;
		else
		break;
	}
	place(1,step,ans,dp,len,N,0);
	return ans;
  }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 5;
			long long step            = 16;
			int expected__[]          = {0, 1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChristmasLightsFixing().fixingTime(N, step);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int N                     = 40;
			long long step            = 1099511627775LL;
			int expected__[]          = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChristmasLightsFixing().fixingTime(N, step);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int N                     = 50;
			long long step            = 7;
			int expected__[]          = {6 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChristmasLightsFixing().fixingTime(N, step);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int N                     = 7;
			long long step            = 47;
			int expected__[]          = {1, 2, 6 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChristmasLightsFixing().fixingTime(N, step);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			long long step            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChristmasLightsFixing().fixingTime(N, step);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			long long step            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChristmasLightsFixing().fixingTime(N, step);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			long long step            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChristmasLightsFixing().fixingTime(N, step);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
