#include<iostream>
#include<vector>

class PowerOutage{

	int estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength){
		vector<int> minDist;
		minDist.resize(toJunction.size() + 1);
		//memset(&minDist, -1, toJunction.size());

		vector<int>res;
		res.resize(toJunction.size() + 1);
		int max = 0;
		int temp = 0;
		int maxi = 0;
		for (int i = toJunction.size(); i > 0; i--){
			temp = getMinDistFromOrigin(fromJunction, toJunction, ductLength, minDist, res, i);
			if (temp > max){
				max = temp;
				maxi = i;
			}
		}
		int minSum = 0;
		for (int i = 0; i < ductLength.size(); i++){
			minSum = minSum + ductLength[i] + ductLength[i];
		}
		minSum = minSum - max;

		display(minDist);

		display(res);
		vector<int>ele;
		ele.push_back(-1);
		for (int i = 1; i <= toJunction.size(); i++){
			ele.push_back(getElementAtIndex(i, toJunction));
		}
		display(ele);
		cout << minSum << endl;
		return minSum;
	}
};