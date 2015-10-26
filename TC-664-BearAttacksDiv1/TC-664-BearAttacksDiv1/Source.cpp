#include<iostream>
#include<vector>

#define sz(A) int(A.size())
#define CON 1000000007
using namespace std;

typedef vector<int> vi;
class BearAttacks{

public:
	vector<vi>roads;
	int N;

	void setAttackedCities(vector<vi> &permOfAttackedCities,vi &attackedCities,int pos,int noOfCitiesAttacked){
		if (noOfCitiesAttacked <= 0){			
			permOfAttackedCities.push_back(attackedCities);
		}
			
		else{			
			for (int i = pos; i < N; i++){
				attackedCities.push_back(i);
				setAttackedCities(permOfAttackedCities,attackedCities,i + 1, noOfCitiesAttacked - 1);
				attackedCities.pop_back();
			}
		}
	}

	int expectedValue(){
		vector<vi> permOfAttackedCities;
		vi attackedCities;
		
		for (int i = 0; i < N; i++){			
			attackedCities.clear();
			setAttackedCities(permOfAttackedCities, attackedCities, 1, i);
		}
		for (int i = 0; i < sz(permOfAttackedCities); i++){
			attackedCities = permOfAttackedCities[i];
			for (int j = 0; j < N; j++){

			}
		}



		return 0;
	}
	int fact(int n){
		int res = 1;
		for (int i = 1; i <= n; i++){
			res = res*i;
			res = res %CON;
		}
		return res;
	}
	int expectedValue(int N, int R0, int A, int B, int M, int LOW, int HIGH){
		roads = vector<vector<int> >(N);
		this->N = N;
		int R = R0;
		long long int BILLION = 1000000000;
		for (int i = 1; i <= N - 1; i++){
			R = (A * R + B) % M;
			int MIN = ((i - 1) * LOW) / BILLION;
			int MAX = ((i - 1) * HIGH) / BILLION;
			int dest = MIN + (R % (MAX - MIN + 1));
			roads[i].push_back(dest);
			roads[dest].push_back(i);
		}
		int E = expectedValue();
		int factOfN = fact(N);
		int res = res *E;
		res %= CON;
		res *= factOfN;
		res %= CON;
		return res;
	}
};
int main(){
	BearAttacks obj;
	obj.expectedValue(3, 0, 2, 3, 100, 938593850, 1000000000);
	return 0;
}