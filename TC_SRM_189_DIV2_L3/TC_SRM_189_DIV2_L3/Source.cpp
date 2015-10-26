#include<iostream>
#include"math.h"

using namespace std;

typedef long long int lli;

class Mortgage{

public:
	bool predicate(double loan,double interest, int term,int value){
		interest /= (12 * 1000);
		int count_term=0;
		term *= 12;
		while (count_term < term && loan>0){
			loan -= value;
			loan = ceil(loan + (loan*interest));
			count_term++;
		}
		if (loan > 0)
			return false;
		return true;
	}

	int monthlyPayment(int loan, int interest, int term){
		lli lo = 1;
		lli hi = loan + ceil(double(loan) * (double(interest) / double(12000)));//2000000000;
		while (lo < hi){
			lli mid = lo + (hi - lo) / 2;
			if (predicate(loan, interest, term, mid)){
				hi = mid;
			}
			else{
				lo = mid + 1;
			}
		}
		return lo;
	}
};
int main(){
	Mortgage mg;
	cout << mg.monthlyPayment(100, 1, 1000) << endl;
	return 0;
}