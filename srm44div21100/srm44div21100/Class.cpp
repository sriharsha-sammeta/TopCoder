#include <vector>

using namespace std;
class PowerOutage2{
public:
	int getMaxDistFrom(int root,vector<int>&fromJunction,vector<int>&toJunction,vector<int>ductlength){

		int start = find(fromJunction.begin(), fromJunction.end(), root) - fromJunction.begin();
		
		if (start<fromJunction.size()){
			int max = 0;
			int sum = 0;
			for (int i = start; i < fromJunction.size(); i++){
				sum = ductlength[i] + getMaxDistFrom(toJunction[i], fromJunction, toJunction, ductlength);
				if (sum > max){
					max = sum;
				}
			}

			return max;
		}

		return 0;
	}


	int estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength){
		int minSum = 0;
		int maxDist=getMaxDistFrom(0, fromJunction, toJunction, ductLength);
		for (int i = 0; i < ductLength.size(); i++){
			minSum += (2 * ductLength[i]);
		}
		minSum -= maxDist;

		return minSum;
	}

};