#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
  public:
  int solution(int K, vector<int> A) {
	// int count = 0;
	// for(int i = 0; i < A.size(); i++) {
	//   int min = A[i];
	//   int max = A[i];
	//   count++;
	//   for(int j = i + 1; j < A.size(); j++) {
	//     int cur = A[j];
	//     if(cur < min) min = cur;
	//     if(cur > max) max = cur;
	//     if(max - min <= K) {
	//       count++;
	//     } else {
	//       break;
	//     }
	//   }
	// }
	// return count;

	int N = A.size();
	vector<int> maxQ(N + 1), posmaxQ(N + 1), minQ(N + 1), posminQ(N + 1);

	int firstMax = 0, lastMax = -1, firstMin = 0, lastMin = -1, j = 0, result = 0;

	for (int i = 0; i < N; i++) {
		while (j < N) {
			// add new maximum element
			while (lastMax >= firstMax && maxQ[lastMax] <= A[j]) {
				lastMax--;
			}
			lastMax++;
			maxQ[lastMax] = A[j];
			posmaxQ[lastMax] = j;

			// add new minimum element
			while (lastMin >= firstMin && minQ[lastMin] >= A[j]) {
				lastMin--;
			}
			lastMin++;
			minQ[lastMin] = A[j];
			posminQ[lastMin] = j;

			if (maxQ[firstMax] - minQ[firstMin] <= K) {
				j++;
			} else {
				break;
			}
		}

		result += (j - i);
		if (result >= 1000000000) {
			return 1000000000;
		}

		if (posminQ[firstMin] == i) { 
			firstMin++; 
		}

		if (posmaxQ[firstMax] == i) {
			firstMax++;
		}
	}

	return result;
  }
};

int main() {
  Solution s;
  cout << to_string(s.solution(2, vector<int> {3,5,7,6,3})) << endl;
  return 0;
}