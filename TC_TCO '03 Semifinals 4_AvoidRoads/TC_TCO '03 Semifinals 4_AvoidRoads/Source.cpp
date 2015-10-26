#include<cstdio>
#include<vector>
#include<sstream>
#include<string>
#include<set>

using namespace std;
typedef long long int lli;
#define tr(V,it) for(auto it = V.begin();it!=V.end();it++)
#define szA(arr) sizeof(arr)/sizeof(arr[0])
#define MP make_pair
typedef pair<int, int> pii;
class AvoidRoads{

	vector<vector<lli> >dp;
	//vector<vector<lli> >blackList;
	set<pair<pii, pii> >blacklist;

public:
	lli numWays(int width, int height, vector<string> bad){
		dp = vector<vector<lli> >(height + 2, vector<lli>(width + 2, 0));
		//blackList = vector<vector<lli> >(height + 2, vector<lli>(width + 2, false));
		dp[height][0] = 1;
		dp[height + 1][1] = 0;

		tr(bad, it){
			istringstream stream(*it);
			int startx, starty, endx, endy;
			stream >> starty >> startx >> endy >> endx;
			blacklist.insert(MP(MP(height - startx, starty + 1), MP(height - endx, endy + 1)));

			//blackList[height - startx][starty + 1] = 1;
			//blackList[height - endx][endy + 1] = 1;
		}		
		return noOfWays(width, height);
	}

private:
	lli noOfWays(int width,int height){

		for (int i = height; i >=0; i--){
			for (int j = 1; j <= width + 1; j++){
				if (blacklist.find(MP(MP(i, j), MP(i, j - 1))) == blacklist.end() && blacklist.find(MP(MP(i, j - 1), MP(i, j))) == blacklist.end()){
					dp[i][j] = dp[i][j - 1];
				}
				if (blacklist.find(MP(MP(i, j), MP(i + 1, j))) == blacklist.end() && blacklist.find(MP(MP(i + 1, j), MP(i, j))) == blacklist.end()){
					dp[i][j] += dp[i + 1][j];
				}
			}
		}
		return dp[0][width + 1];
	}
};

int main(){
	AvoidRoads obj;
	string arr[] = { "1 2 2 2", "1 1 2 1" };
	
	printf("%d\n", obj.numWays(2, 2, vector<string>(arr, arr + szA(arr)) ) );
	return 0;
}