#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;
typedef long long int lli;
class ChessMetric{
		
public:

	lli howMany(int size, vector<int> start, vector<int> end, int numMoves){
		vector<vector<vector<lli> > >dp(size+4, vector< vector<lli> >(size+4, vector<lli>(numMoves + 1, 0)));
		
		dp[start[0] + 2][start[1] + 2][0] = 1;
		
		for (int m = 1; m <= numMoves; m++){
			for (int i = 2; i < (size+2); i++){
				for (int j = 2; j < (size+2); j++){
					if (dp[i][j][m - 1] != 0){
						
						dp[i][j + 1][m] += dp[i][j][m - 1];
						dp[i][j - 1][m] += dp[i][j][m - 1];
						dp[i + 1][j][m] += dp[i][j][m - 1];
						dp[i - 1][j][m] += dp[i][j][m - 1];

						dp[i + 1][j + 1][m] += dp[i][j][m - 1];
						dp[i + 1][j - 1][m] += dp[i][j][m - 1];
						dp[i - 1][j + 1][m] += dp[i][j][m - 1];
						dp[i - 1][j - 1][m] += dp[i][j][m - 1];

						dp[i + 1][j + 2][m] += dp[i][j][m - 1];
						dp[i - 1][j + 2][m] += dp[i][j][m - 1];
						
						dp[i + 2][j + 1][m] += dp[i][j][m - 1];
						dp[i + 2][j - 1][m] += dp[i][j][m - 1];

						dp[i + 1][j - 2][m] += dp[i][j][m - 1];
						dp[i - 1][j - 2][m] += dp[i][j][m - 1];

						dp[i - 2][j + 1][m] += dp[i][j][m - 1];
						dp[i - 2][j - 1][m] += dp[i][j][m - 1];
					}
				}
			}
		}
		return dp[end[0] + 2][end[1] + 2][numMoves];
	}
};

int main(){
	ChessMetric obj;
	//printf("%d\n", obj.howMany(3, { 0, 0 }, { 1, 2 }, 1));
	//printf("%d\n", obj.howMany(3,{0, 0},{0, 0},2));
	printf("%lld\n", obj.howMany(100, { 0, 0 }, { 0, 99 }, 50));
	//cout << obj.howMany(100, { 0, 0 }, { 0, 99 }, 50) << endl;
	return 0;
}


//dp[i][j + 1][m] += dp[i][j][m - 1];
//dp[i][j - 1][m] += dp[i][j][m - 1];
//dp[i + 1][j][m] += dp[i][j][m - 1];
//dp[i - 1][j][m] += dp[i][j][m - 1];
//
//dp[i + 1][j + 1][m] += dp[i][j][m - 1];
//dp[i + 1][j - 1][m] += dp[i][j][m - 1];
//dp[i - 1][j + 1][m] += dp[i][j][m - 1];
//dp[i - 1][j - 1][m] += dp[i][j][m - 1];
//
//dp[i + 1][j + 2][m] += dp[i][j][m - 1];
//dp[i - 1][j + 2][m] += dp[i][j][m - 1];
//
//dp[i + 2][j + 1][m] += dp[i][j][m - 1];
//dp[i + 2][j - 1][m] += dp[i][j][m - 1];
//
//dp[i + 1][j - 2][m] += dp[i][j][m - 1];
//dp[i - 1][j - 2][m] += dp[i][j][m - 1];
//
//dp[i - 2][j + 1][m] += dp[i][j][m - 1];
//dp[i - 2][j - 1][m] += dp[i][j][m - 1];
