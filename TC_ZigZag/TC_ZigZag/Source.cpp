#include<cstdio>
#include<vector>


using namespace std;
#define sz(A) int(A.size())
#define szA(A) sizeof(A)/sizeof(A[0])

class ZigZag{
public :
	enum state{
		up,down,notset
	};

	int longestZigZag(vector<int> sequence){
		vector<int>sum(sz(sequence), 0);

		state direction = notset;
		sum[0] = 1;
		
		for (int i = 1; i < sz(sequence); i++){
			switch (direction){
			case up:
				if (sequence[i] < sequence[i - 1]){
					sum[i] = sum[i - 1] + 1;
					direction = down;
				}
				else
					sum[i] = sum[i - 1];
				break;
			case down:
				if (sequence[i] > sequence[i - 1]){
					sum[i] = sum[i - 1] + 1;
					direction = up;
				}
				else
					sum[i] = sum[i - 1];
				break;
			default:
				if (sequence[i] != sequence[i - 1]){
					sum[i] = sum[i - 1] + 1;
					if (sequence[i]>sequence[i - 1]){
						direction = up;
					}
					else{
						direction = down;
					}
				}
				else{
					sum[i] = sum[i - 1];
				}
				break;
			}
		}
		return sum[sz(sequence) - 1];
	}
};
int main(){
	ZigZag obj;
	int arr[] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
	vector<int>input(arr,arr+szA(arr));
	printf("%d\n",obj.longestZigZag(input));
	return 0;
}