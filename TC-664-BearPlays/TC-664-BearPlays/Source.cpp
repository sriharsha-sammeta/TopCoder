#include<iostream>
#include "math.h"
#include<map>

#define min(a,b) ((a<b)?a:b)

using namespace std;

class BearPlays2{
public:
	int pileSize(int A, int B, int K){
		int S = A + B;
		long long int pow2 = 2;
		long long int res = 1;
		while (K!=0){
			if (K % 2 == 1){
				res = res*pow2;
				res %= S;
			}				
			pow2 = pow2*pow2;
			pow2 %= S;
			K = K / 2;
		}
		res = res*A;
		res = res%S;
		return min(res,S-res);
	}
};


class BearPlays{
public:
	map<int,int>V;
	int orginalK=0;
	
	
	int pileSize(long long int A, long long int B, long long int K){
		//cout << A << " " << B << " " << K << endl;
		if (K == 0)
			return (A <= B) ? A : B;	
		if (V.find(A)!=V.end()){ 
			long long int originalA = A;
			int repeaterCount=0;
			while (true){
				repeaterCount++;
				A = V[A];
				if (originalA == A)
					break;				
			}
			K = K%repeaterCount;			
			long long int total = A + B;
			for (int i = 1; i <= K; i++){
				A = V[A];
			}
			if (A <= (total - A))
				return A;
			else return (total - A);
		}
		if (orginalK == 0)
				orginalK = K;
		
		if (A <= B) {
			V[A] = A + A;	
			V[B] = B - A;
			return pileSize(A + A, B - A, K - 1);
		}
		else{
			V[A] = A - B;
			V[B] = B + B;
			return pileSize(A - B, B + B, K - 1);
		}
		
	}

	int pileSize(int A, int B, int K){
		return pileSize((long long int)A, (long long int)B, (long long int)K);
	}
};

int main(){
	
	BearPlays2 obj;
	
	cout << obj.pileSize(23842, 963812, 123456) << endl;
	return 0;
}