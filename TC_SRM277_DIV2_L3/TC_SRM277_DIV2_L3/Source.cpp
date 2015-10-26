#include<iostream>
#include<vector>
#include"math.h"

#define sz(A) int(A.size())
#define szA(A) sizeof(A)/sizeof(A[0])

using namespace std;

class UnionOfIntervals{
	
private:
	bool predicateChecker(vector<int>&lowerBound, vector<int>&upperBound, int n,double value){
		double calcIndex = 0;
		for (int i = 0; i < sz(lowerBound); i++){
			if (value>lowerBound[i]){
				calcIndex += (value - lowerBound[i]);
			}
			if (value > upperBound[i]){
				calcIndex -= (value - (upperBound[i] + 1));
			}				
		}		
		return calcIndex <= n;
	}
public:
	int nthElement(vector<int>lowerBound, vector<int> upperBound, int n){
		double lo = 2000000000;
		double hi = -2000000000;
		for (int i = 0; i < sz(lowerBound); i++){
			if (lowerBound[i] < lo)
				lo = lowerBound[i];
		}
		for (int i = 0; i < sz(upperBound); i++){
			if (upperBound[i] > hi)
				hi = upperBound[i];
		}
		while (lo < hi){
			double mid = lo + ceil((hi - lo) / 2.0);
			if (predicateChecker(lowerBound,upperBound,n,mid)){
				lo = mid;
			}
			else{
				hi = mid - 1;
			}
		}
		return lo;
	}
};


int main(){
	UnionOfIntervals uot;
	int a1[] = { -1500000000 };
	int a2[] = { 1500000000 };
	vector<int>lb(a1, a1 + szA(a1));
	vector<int>ub(a2, a2 + szA(a2));
	cout << uot.nthElement(lb, ub, 1500000091) << endl;
	return 0;
}