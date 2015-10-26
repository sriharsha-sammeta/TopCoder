#include<iostream>
#include<vector>
#include<algorithm>

#define sz(A) int(A.size())
#define szA(A) sizeof(A)/sizeof(A[0])
using namespace std;


typedef vector<int> vi;

class BearSortsDiv23{
public:
	int probCount = 0;
	vi T;
	vi whereIS;
	bool LESS(int &i, int &j){		
		probCount++;
		return whereIS[i] < whereIS[j];
	}

	void myMergeSort(int begin, int end){
		if (begin < end){
			int mid = (begin + end) / 2;
			if ((begin + end) % 2 == 0)
				mid--;
			myMergeSort(begin, mid);
			myMergeSort(mid + 1, end);

			int i = begin;
			int j = mid + 1;
			vector<int>merged;
			while (i <= mid || j <= end){
				if (i > mid){
					merged.push_back(T[j]);
					j++;
				}
				else if (j > end){
					merged.push_back(T[i]);
					i++;
				}
				else{
					if (LESS(T[i], T[j])){
						merged.push_back(T[i]);
						i++;
					}
					else{
						merged.push_back(T[j]);
						j++;
					}
				}
			}

			i = begin;
			while (i <= end){
				T[i] = merged[i - begin];
				i++;
			}
		}

	}


	double getProbability(vector <int> seq){
		T = vi(sz(seq) + 1);
		whereIS = vi(sz(seq)+1);
		for (int i = 0; i < sz(seq); i++){
			whereIS[seq[i]] = i;
			T[i+1] = i+1;
		}
		myMergeSort(1, sz(seq));
		return log(0.5)* probCount;
	}
};



class BearSortsDiv2{
public:
	int probCount = 0;
	bool LESS(vi &sortedSeq, int &i, int &j, vi &seq){
		probCount++;
		auto resi = find(seq.begin(), seq.end(), sortedSeq[i]);
		auto resj = find(seq.begin(), seq.end(), sortedSeq[j]);
		if (resi != seq.end() && resj!=seq.end()){
			if (resi < resj){
				return true;
			}
		}
		return false;
	}

	void myMergeSort(vi &sortedSeq,int begin,int end,vi &seq){
		if (begin < end){
			int mid = (begin + end) / 2;
			if ((begin + end) % 2 == 0)
				mid -= 1;
			myMergeSort(sortedSeq, begin, mid, seq);
			myMergeSort(sortedSeq, mid + 1, end, seq);

			int i = begin;
			int j = mid + 1;
			vector<int>merged;
			while (i <= mid || j <= end){
				if (i > mid){
					merged.push_back(sortedSeq[j]);
					j++;
				}
				else if (j > end){
					merged.push_back(sortedSeq[i]);
					i++;
				}
				else{
					if (LESS(sortedSeq, i, j, seq)){
						merged.push_back(sortedSeq[i]);
						i++;
					}
					else{
						merged.push_back(sortedSeq[j]);
						j++;
					}
				}
			}

			i = begin;
			while (i <= end){
				sortedSeq[i] = merged[i-begin];
				i++;
			}
		}
		
	}


	double getProbability(vector <int> seq){
		vector<int>sortedSeq(seq.begin(),seq.end());
		sort(sortedSeq.begin(), sortedSeq.end());
		myMergeSort(sortedSeq, 0, sz(sortedSeq) - 1, seq);
		double res = 1;
		for (int i = 1; i <= probCount; i++){
			res = res*(long double)0.5;
		}	
		return log(res);
	}
};

int main(){

	BearSortsDiv23 obj23;
	BearSortsDiv2 obj2;
	//int input[] = { 1, 2 };
	//int input[] = { 1, 3, 2 };
	//int input[] = { 4, 2, 3, 1 };
	//int input[] = { 8, 3, 4, 1, 2, 5, 6, 7 };
	int input[] = { 10, 13, 18, 2, 4, 6, 24, 22, 19, 5, 7, 20, 23, 14, 21, 17, 25, 3, 1, 11, 12, 8, 15, 16, 9 };

	cout << obj2.getProbability(vi(input, input + szA(input))) << endl;
	cout << obj2.probCount << endl;

	cout << obj23.getProbability(vi(input, input + szA(input))) << endl;
	cout << obj23.probCount << endl;
	return 0;
}