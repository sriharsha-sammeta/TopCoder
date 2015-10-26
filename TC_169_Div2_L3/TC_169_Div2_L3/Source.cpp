#include<iostream>
#include <vector>

#define sz(A) int(A.size())
#define szA(arr) sizeof(arr)/sizeof(arr[0]) 
using namespace std;

class FairWorkload{


	bool predicate(vector<int>&folders,int &workers,int maxValue){
		int countOfWorkers = 1;
		int sum = 0;
		for (int i = 0; i < sz(folders); i++){
			if (sum + folders[i] > maxValue){
				countOfWorkers++;
				sum = 0;
			}
			sum += folders[i];
		}
		return (countOfWorkers<=workers);
	}

public:
	int getMostWork(vector <int> folders, int workers){

		int maxValue=0;
		int sum = 0;
		for (int i = 0; i < sz(folders); i++){
			if (folders[i]>maxValue)
				maxValue = folders[i];
			sum += folders[i];
		}

		int lo = maxValue;
		int hi = sum;

		while (lo < hi){

			int mid = (lo + hi) / 2;
			bool result = predicate(folders, workers, mid);
			if (result){
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
	FairWorkload *obj = new FairWorkload();
	int arr[] = { 10, 20, 30, 40,50,60,70,80,90};
	vector<int>v(arr,arr+szA(arr));

	cout << obj->getMostWork(v, 3) << endl;

}