#include<iostream>
#include<string>

using namespace std;
class BearCheats{
public:
	string eyesight(int A, int B){
		bool digitFound = false;

		while (A != 0 && B != 0){
			if (A % 10 != B % 10){
				if (!digitFound)
					digitFound = true;
				else
					return "glasses";
			}
			A = A / 10;
			B = B / 10;
		}
		return "happy";
	}

};

int main(){
	BearCheats obj;
	cout << obj.eyesight(4,8) << endl;
}