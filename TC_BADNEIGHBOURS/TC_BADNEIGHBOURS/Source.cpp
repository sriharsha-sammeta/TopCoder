#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define sz(A) int(A.size())
#define szA(A) sizeof(A)/sizeof(A[0])

class BadNeighbors{
public:

	int maxDonations(vector<int> donations){

		vector<int>fromFirst(sz(donations)+1,0);
		vector<int>notFromFirst(sz(donations)+1,0);
		
		fromFirst[0] = 0;
		fromFirst[1] = donations[0];

		notFromFirst[0] = 0;
		notFromFirst[1] = 0;
		
		for (int i = 2; i <= sz(donations); i++){
						
			fromFirst[i] = max(donations[i-1] + fromFirst[i - 2], fromFirst[i - 1]);
						
			notFromFirst[i] = max(donations[i-1] + notFromFirst[i - 2], notFromFirst[i - 1]);

		}
		return max(fromFirst[sz(donations) - 1], notFromFirst[sz(donations)]);

	}
};

int main(){
	int arr[] = { 10, 3, 2, 5, 7, 8 };
	vector<int> donations(arr, arr + szA(arr));
	BadNeighbors obj;
	printf("%d\n",obj.maxDonations(donations));

	return 0;
}