#include<iostream>
#include<string>
#include<map>

using namespace std;
#define sz(A) int(A.size())


int compare (string &a, string &b){
	if (sz(a) < sz(b)){
		return -1;
	}
	else if (sz(a) > sz(b)){
		return 1;
	}
	else{
		return a.compare(b);
	}
}

class ShortPalindromes{

	map<string, string>dp;
	string base;
	void performDp(){
		int dist = 0;
		while (dist < sz(base)){
			for (int i = 0; i+dist< sz(base); i++){
				string temp = base.substr(i, dist + 1);
				if (sz(temp)==1){
					dp[temp] = temp;
				}
				else{
					string A = temp.substr(0, 1);
					string B = temp.substr(sz(temp) - 1, 1);
					if (A == B){
						dp[temp] = A + dp[temp.substr(1, sz(temp) - 2)] + A;
					}
					else{						
						string left = A + dp[temp.substr(1, sz(temp) - 1)] + A;
						string right = B + dp[temp.substr(0, sz(temp) - 1)] + B;
						dp[temp] = (compare(left, right) <= 0) ? left : right;
					}
				}
			}			
			dist++;
		}
	}

	bool isPalindrome(string str){
		string rev = string(str.rbegin(), str.rend());
		return str == rev;
	}
public:
	

	string shortest(string base){
		this->base = base;
		performDp();			
		return dp[base];
	}
};

int main(){
	ShortPalindromes obj;
	cout << obj.shortest("TOPCODER")<<endl;
	return 0;
}