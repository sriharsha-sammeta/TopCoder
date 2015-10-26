#include<cstdio>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

#define sz(A) int(A.size())

int dp[50][50][98];


class StripePainter{

	string stripes;

	int minSteps(int i, int j, int color){
		if (i <= j && i >= 0 && j <= sz(stripes) - 1){
			if (dp[i][j][color] >= 0){
				return dp[i][j][color];
			}
			else if (stripes[i] == color){
				return minSteps(i + 1, j, color);
			}
			else{
				int minVal = INT_MAX;
				for (int k = i; k <= j; k++){
					minVal = min(minVal, 1 + minSteps(i, k, stripes[i]) + minSteps(k + 1, j, color));
				}
				dp[i][j][color] = minVal;
				return dp[i][j][color];
			}
		}
		return 0;
	}

public:
	int minStrokes(string stripes){
		for (int i = 0; i < 50; i++){
			for (int j = 0; j < 50; j++){
				for (int k = 0; k < 98; k++){
					dp[i][j][k] = -1;
				}
			}
		}
		this->stripes = stripes;
		return minSteps(0, sz(stripes) - 1, '?');
	}
};


int main(){
	StripePainter obj;
	printf("%d %d %d\n",'Z','?', obj.minStrokes("RGBGR"));
	return 0;
}