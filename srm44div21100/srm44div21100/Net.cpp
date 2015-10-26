#include<iostream>
#include<string>
#include<vector>
#include "Class.cpp"
using namespace std;

class PowerOutage{
public:
	void display(const vector<int>& vec){
		for (int i = 1; i < vec.size(); i++){
			cout << vec[i]<<"\t";
		}
		cout << endl;
	}

	int getElementAtIndex(int index, vector<int>&vec){
		if (index == 0)
			return 0;
		else{
			if (index>0 && index <= vec.size()){
				return vec[index - 1];
			}
		}
		return -1;
	}
	int getDistBetweenTwoIndicesIfExists(vector <int>& fromVec, vector <int> & toVec, vector <int> & ductLength, int from, int to){

		if (from == to){
			return -1;
		}
		if (from > to){
			int temp = from;
			from = to;
			to = temp;
		}
		int valAtFrom = getElementAtIndex(from, toVec);
		if (valAtFrom != -1){
			if (to > 0 && to <= fromVec.size() && to <= ductLength.size()){
				if (valAtFrom == fromVec[to - 1]){
					return ductLength[to - 1];
				}
			}
		}
		return -1;
	}
	int getMinDistFromOrigin(vector <int>& fromVec, vector <int> & toVec, vector <int> & ductLength, vector<int>& minDist, vector<int>& res, int to){

		if (minDist[to] > 0){
			return minDist[to];
		}
		int temp = getDistBetweenTwoIndicesIfExists(fromVec, toVec, ductLength, 0, to);
		if (temp != -1){
			minDist[to] = temp;
			if (res[to] != -1){
				res[to] = 0;
			}
			return minDist[to];
		}
		else{
			
			for (int i = to - 1; i > 0; i--){
				int res1 = getMinDistFromOrigin(fromVec, toVec, ductLength, minDist, res, i);
				int res2 = getDistBetweenTwoIndicesIfExists(fromVec, toVec, ductLength, i, to);
				if (res1 != -1 && res2 != -1){
					res[i] = -1;
					minDist[to] = res1 + res2;
					return res1 + res2;
				}
			}
			return -1;
		}
	}

int estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength){
	vector<int> minDist;
	minDist.resize(toJunction.size() + 1);
	//memset(&minDist, -1, toJunction.size());

	vector<int>res;
	res.resize(toJunction.size() + 1);
	int max=0;
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

int main(){
	vector<int>fromJunction;
	vector<int>toJunction;
	vector<int>ductLength;

	//{0, 0, 0, 1, 4, 4, 6, 7, 7, 7, 20}
	//{1, 3, 4, 2, 5, 6, 7, 20, 9, 10, 31}
	//{10, 10, 100, 10, 5, 1, 1, 100, 1, 1, 5}
	fromJunction.push_back(0); toJunction.push_back(1); ductLength.push_back(10);
	fromJunction.push_back(0); toJunction.push_back(3); ductLength.push_back(10);
	fromJunction.push_back(0); toJunction.push_back(4); ductLength.push_back(100);
	fromJunction.push_back(1); toJunction.push_back(2); ductLength.push_back(10);
	fromJunction.push_back(4); toJunction.push_back(5); ductLength.push_back(5);
	fromJunction.push_back(4); toJunction.push_back(6); ductLength.push_back(1);
	fromJunction.push_back(6); toJunction.push_back(7); ductLength.push_back(1);
	fromJunction.push_back(7); toJunction.push_back(20); ductLength.push_back(100);
	fromJunction.push_back(7); toJunction.push_back(9); ductLength.push_back(1);
	fromJunction.push_back(7); toJunction.push_back(10); ductLength.push_back(1);
	fromJunction.push_back(20); toJunction.push_back(31); ductLength.push_back(5);
	
	//PowerOutage *p = new PowerOutage();
	//p->estimateTimeOut(fromJunction, toJunction, ductLength);
	PowerOutage2 *p = new PowerOutage2();
	cout << p->getMaxDistFrom(0, fromJunction, toJunction, ductLength) << endl;
	cout << p->estimateTimeOut(fromJunction, toJunction, ductLength);
	return 0;
}



