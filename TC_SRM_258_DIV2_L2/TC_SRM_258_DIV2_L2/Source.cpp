#include<iostream>

using namespace std;
class AutoLoan{

private:

	bool predicate(double price, double monthlyPayment, int loanTerm, double estimatedRateOfInterestPerMonth){
		int countOfTerm = 0;
		while (countOfTerm <= loanTerm && price > 0){
			price += ((price*estimatedRateOfInterestPerMonth) / 100);
			price -= monthlyPayment;
			countOfTerm++;
		}
		return countOfTerm <= loanTerm;
	}

public:
	double interestRate(double price, double monthlyPayment, int loanTerm){
		double lo = 0;
		double hi = 100;
		double mid;
		while (lo < hi){
			mid = lo + (hi - lo) / 2;
			if (mid == lo)
				mid = hi;
			if (predicate(price, monthlyPayment, loanTerm, (mid / 12))){
				lo = mid;
			}
			else{
				hi = mid - 0.000000001;
			}
		}
		return lo;
	}
};
//7.68785581782
//Returns: 7.687856394581649
int main(){
	AutoLoan obj;
	double result = obj.interestRate(15000,364,48);
	cout << result << endl;
	return 0;
}