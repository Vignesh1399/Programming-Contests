#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

class ChristmasCrackerHappiness {
  public:
  int solve(int N, vector <int> winner, vector <int> loser) {
      vector<bool> win(N+1,0);
      int cur = 0;
      for(int i=0;i<sz(winner);i++){
      	if(!win[winner[i]])
      	cur++;
      	win[winner[i]] = 1;
      }
      int cnt = 0;
      for(int i=0;i<N;i++){
      	if(!win[i])
      	cnt++;
      }
      int ans = cnt-1;
      ans = max(ans,0);
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
			int N                     = 2;
			int winner[]              = {};
			int loser[]               = {};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasCrackerHappiness().solve(N, vector <int>(winner, winner + (sizeof winner / sizeof winner[0])), vector <int>(loser, loser + (sizeof loser / sizeof loser[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 5;
			int winner[]              = {0, 1, 0, 3, 2, 0, 4, 0};
			int loser[]               = {3, 3, 4, 1, 0, 2, 1, 3};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasCrackerHappiness().solve(N, vector <int>(winner, winner + (sizeof winner / sizeof winner[0])), vector <int>(loser, loser + (sizeof loser / sizeof loser[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 12;
			int winner[]              = {3, 1, 4, 1, 5, 9, 2, 6};
			int loser[]               = {5, 3, 5, 8, 9, 7, 9, 3};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasCrackerHappiness().solve(N, vector <int>(winner, winner + (sizeof winner / sizeof winner[0])), vector <int>(loser, loser + (sizeof loser / sizeof loser[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int N                     = ;
			int winner[]              = ;
			int loser[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasCrackerHappiness().solve(N, vector <int>(winner, winner + (sizeof winner / sizeof winner[0])), vector <int>(loser, loser + (sizeof loser / sizeof loser[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int N                     = ;
			int winner[]              = ;
			int loser[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasCrackerHappiness().solve(N, vector <int>(winner, winner + (sizeof winner / sizeof winner[0])), vector <int>(loser, loser + (sizeof loser / sizeof loser[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int winner[]              = ;
			int loser[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasCrackerHappiness().solve(N, vector <int>(winner, winner + (sizeof winner / sizeof winner[0])), vector <int>(loser, loser + (sizeof loser / sizeof loser[0])));
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
