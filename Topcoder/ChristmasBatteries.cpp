#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

class ChristmasBatteries {
  public:
  int mostFun(int B, int N, int X, int Y, int Z, int M) {
      vector<vector<int>> dp(N+1,vector<int>(B+1,0));
      X %= M;
      Y %= M;
      Z %= M;
      int val = 0;
      for(int i=0;i<N;i+=5){
      	int ci = i%M;
      	int xii = ((X * ci) % M * ci) % M;
      	int yi = (Y * ci)%M;
      	val += (xii + yi + Z) % M;
      	int j=i;
      	while(j<i+5 && j<N)
      	dp[j++][0] = val;
      }
      for(int i=0;i<N;i++){
      	int ci = i%M;
      	int xii = ((X * ci) % M * ci) % M;
      	int yi = (Y * ci)%M;
      	for(int j=1;j<=B;j++){
      		if(i == 0){
      			dp[i][j] = dp[i][j-1];
      		}
      		else{
      			dp[i][j] = dp[i-1][j];
      			if(j - (i%5) >= 0)
      			dp[i][j] = max(dp[i][j],dp[i-1][j-(i%5)] + (xii + yi + Z) % M);
      		}
      	}
      }
      int ans = dp[N-1][B];
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			int B                     = 0;
			int N                     = 5;
			int X                     = 1;
			int Y                     = 1;
			int Z                     = 1;
			int M                     = 1000;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int B                     = 3;
			int N                     = 5;
			int X                     = 1;
			int Y                     = 1;
			int Z                     = 1;
			int M                     = 1000;
			int expected__            = 14;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int B                     = 3;
			int N                     = 5;
			int X                     = 1;
			int Y                     = 1;
			int Z                     = 1;
			int M                     = 13;
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int B                     = 4;
			int N                     = 10000;
			int X                     = 123;
			int Y                     = 456;
			int Z                     = 789;
			int M                     = 1;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int B                     = 7;
			int N                     = 4;
			int X                     = 3;
			int Y                     = 5;
			int Z                     = 7;
			int M                     = 997;
			int expected__            = 100;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int B                     = 2;
			int N                     = 12345;
			int X                     = 234;
			int Y                     = 34;
			int Z                     = 5;
			int M                     = 117;
			int expected__            = 143371;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int B                     = ;
			int N                     = ;
			int X                     = ;
			int Y                     = ;
			int Z                     = ;
			int M                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int B                     = ;
			int N                     = ;
			int X                     = ;
			int Y                     = ;
			int Z                     = ;
			int M                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int B                     = ;
			int N                     = ;
			int X                     = ;
			int Y                     = ;
			int Z                     = ;
			int M                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
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
