#include<cstdio>
#include<string>
#include<climits>
#include<algorithm>

using namespace std;
#define sz(A) int(A.size())

int dp[10][10][101];

class QuickSums{

	string numbers;
	int calcMinPlus(int i, int j, int sum){
		int minVal = INT_MAX;

		if (i <= j && i >= 0 && j < sz(numbers) && sum >= 0){				
			for (int k = i; k <= j; k++){
				int inter = stoi(string(numbers.begin() + i, numbers.begin() + k + 1));
				if (k + 1 <= j){
					if (sum - inter >= 0){
						inter = calcMinPlus(k + 1, j, sum - inter);
						if (inter >= 0){
							minVal = min(minVal, 1 + inter);
						}
					}
					else{
						break;
					}
				}
				else{
					if (sum - inter == 0){
						minVal = 0;
					}
				}
			}			
		}
		if (minVal == INT_MAX)
			minVal = -1;

		return minVal;
	}


public:
	int minSums(string numbers, int sum){
		this->numbers = numbers;
		return calcMinPlus(0, sz(numbers) - 1, sum);
	}
};


int main(){
	QuickSums obj;
	string input = "99999";
	printf("%d\n", obj.minSums(input, 45));
	printf("%d\n", obj.minSums("1110", 3));
	printf("%d\n", obj.minSums("0123456789", 45));
	printf("%d\n", obj.minSums("99999", 100));
	printf("%d\n", obj.minSums("382834", 100));
	printf("%d\n", obj.minSums("9230560001", 71));
	return 0;
}