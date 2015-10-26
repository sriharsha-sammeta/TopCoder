#include<iostream>
#include<string>

using namespace std;




class BearPlaysDiv23{
public:
	bool can[2000][2000];

	void run(int t[]){
		if (can[t[0]][t[1]] || can[t[1]][t[2]] || can[t[0]][t[2]])
			return;
		int s = t[0] + t[1] + t[2];
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (can[s / 3][s / 3])
					return;
				if (can[t[i]][t[j]])
					continue;
				can[t[i]][t[j]] = true;				
				can[t[j]][t[i]] = true;
				if (t[i] < t[j]){
					int t2[] = {t[i]+t[i],t[j]-t[i],t[0+1+2-i-j]};
					run(t2);
				}
			}
		}
	}

	

	string equalPiles(int A, int B, int C){
		if ((A + B + C) % 3 == 0){
			int t[] = { A, B, C };
			run(t);
			int s = A + B + C;
			if (can[s / 3][s / 3])
				return "possible";
		}
		return "impossible";		
	}
};


class BearPlaysDiv2{
public:
	int memo[3000][3000];
	string piles(int A, int B, int C){
		//cout << A << "  " << B << "  " << C<<endl;
		if (A < 0 || B < 0 || C < 0)
			return "impossible";
		if (A == B && B == C)
			return "possible";
		if (memo[A][B] || memo[B][C] || memo[A][C]){
			string res;
			if (A != B){
				memo[A][B] = 1;
				memo[B][A] = 1;
				if (A < B){
					res = piles(A + A, B - A, C);
				}
				else{
					res = piles(A - B, B + B, C);
				}
				if (res == "possible")
					return res;
			}
			if (A != C){

				memo[A][C] = 1;
				memo[C][A] = 1;
				if (A < C){
					res = piles(A + A, B, C - A);
				}
				else{
					res = piles(A - C, B, C + C);
				}
				if (res == "possible")
					return res;
			}
			if (B != C){
				memo[B][C] = 1;
				memo[C][B] = 1;
				if (B < C){
					res = piles(A, B + B, C - B);
				}
				else{
					res = piles(A, B - C, C + C);
				}
				if (res == "possible")
					return res;
			}
		}
		return "impossible";
	}
	string equalPiles(int A, int B, int C){
		if ((A + B + C) % 3 != 0){
			return "impossible";
		}
		else{			
			return piles(A,B,C);
		}

	}

};


int main(){
	BearPlaysDiv23 *obj=new BearPlaysDiv23();
	cout<<obj->equalPiles(499, 500, 477)<<endl;
	return 0;
}