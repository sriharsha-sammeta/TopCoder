#include<iostream>
#include"math.h"
using namespace std;
class 	SortEstimate{
private:
	bool predicate(double n,double c,double time){
		return (n*log2(n)) <= (time / c);
	}
public:
	double howMany(int c, int time){
		double lo = 0;
		double inc = 1000000000;
		double mid;		
		while (inc >= 1e-10){
			if (predicate(lo + inc, c, time)){
				lo += inc;
			}
			inc /= 2;
		}
		return lo;
	}
};
//7.637495090348122E7
//Largest possible return.
int main(){	
	SortEstimate obj;
	cout << obj.howMany(1,2000000000) << endl;
	return 0;
}