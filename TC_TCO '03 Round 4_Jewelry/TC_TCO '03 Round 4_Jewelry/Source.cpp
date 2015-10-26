#include<cstdio>
#include<vector>
#include<algorithm>
#include<numeric>
#include<math.h>

using namespace std;

#define sz(A) int(A.size())
#define szA(A)  sizeof(A)/sizeof(A[0])

long waysBelow[31][30001];
long waysAbove[31][30001];

typedef long long int lli;

class Jewelry{

	void caliculateWaysBelow(vector<int> &values, lli maxSum, lli maxNoOfElements){
		waysBelow[0][0] = 1;
		for (int i = 1; i <= maxSum; i++){
			waysBelow[0][i] = 0;
		}
		
		for (int i = 1; i <= maxNoOfElements; i++){
			for (int sum = 0; sum <= maxSum; sum++){
				if (values[i-1]<= sum){
					waysBelow[i][sum] = waysBelow[i - 1][sum - values[i - 1]] + waysBelow[i - 1][sum];
				}
				else{
					waysBelow[i][sum] = waysBelow[i - 1][sum];
				}
			}
		}
	}

	void caliculateWaysAbove(vector<int> &values, lli maxSum, lli maxNoOfElements){
		waysAbove[maxNoOfElements][0] = 1;
		for (int i = 1; i <= maxSum; i++){
			waysAbove[maxNoOfElements][i] = 0;
		}

		for (int i = maxNoOfElements - 1; i >= 0; i--){
			for (int sum = 0; sum <= maxSum; sum++){
				if (values[i] <= sum){
					waysAbove[i][sum] = waysAbove[i + 1][sum - values[i]] + waysAbove[i + 1][sum];
				}
				else{
					waysAbove[i][sum] = waysAbove[i + 1][sum];
				}
			}
		}
	}

	lli choose(double N, int R){
		if (R < ceil(N / 2))
			R = N - R;
		lli ans = 1;
		for (lli i = R + 1, j = 1; i <= N; j++, i++){
			ans *= i;
			ans /= j;
		}
		return ans;
	}

public:
	long howMany(vector<int> values){		
		sort(values.begin(), values.end());
		lli maxSum = 0;
		for (int i = 0; i < sz(values); i++){
			maxSum += values[i];
		}
		int maxNoOfElements = sz(values);
		caliculateWaysBelow(values, maxSum, maxNoOfElements);
		caliculateWaysAbove(values, maxSum, maxNoOfElements);

		vector<pair<int, int>>groups;
		pair<int, int>tempGroup;
		for (int i = 0; i<maxNoOfElements; i++){
			tempGroup.first = i;
			tempGroup.second = 1;
			while (i < maxNoOfElements - 1 && values[i] == values[i + 1]){
				tempGroup.second++;
				i++;
			}
			groups.push_back(tempGroup);
		}
		lli count = 0;
		lli temp = 0;

		for (auto it = groups.begin(); it != groups.end(); it++){
			int i = it->first;
			int size = it->second;
			for (int j = 1; j <= size; j++)
			{
				for (int sum = values[i] * j; sum <= maxSum; sum++)
				{
					lli choice = choose(size, j);
					temp = choice *((waysBelow[i][sum - (values[i] * j)]) * waysAbove[i + j][sum]);
					if (temp != 0){
						count += temp;
						//printf("%lld %d %d\n", temp, i + j, sum);
					}
				}
			}
		}
		return count;
	}
};


int main(){
	Jewelry obj;
	int arr[] =

	{ 7, 7, 8, 9, 10, 11, 1, 2, 2, 3, 4, 5, 6 };
	printf("%lld\n",obj.howMany(vector<int>(arr, arr + szA(arr))));

	return 0;
}