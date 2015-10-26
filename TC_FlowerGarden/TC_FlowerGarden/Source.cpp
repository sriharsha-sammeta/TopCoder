#include<cstdio>
#include<vector>

using namespace std;

#define sz(A) int(A.size())
#define szA(arr) sizeof(arr)/sizeof(arr[0])

#define  block(i,j) !(wilt[i]<bloom[j] ||  bloom[i]>wilt[j])
typedef vector<int> vi;


//{5, 4, 3, 2, 1}
//{1, 5, 10, 15, 20}
//{5, 10, 14, 20, 25}
//Returns: { 3, 4, 5, 1, 2 }

// 5-10  1-6
// 5-10 8-15
// 5-10 1-5
class FlowerGarden{
public:

	vi getOrdering(vi height, vi bloom, vi wilt){		
		
		int noOfFlowers = sz(height);
		vi result(noOfFlowers,-1);
		vi alreadyUsed(noOfFlowers,false);

		for (int i = 0; i < noOfFlowers; i++){
			int maxH = 0;
			int pos = -1;
			for (int j = 0; j < noOfFlowers; j++){
				bool found = true;
				if (!alreadyUsed[j]){
					for (int k = 0; k < noOfFlowers; k++){						
						if (!alreadyUsed[k] && block(j, k) && height[j] > height[k]){
							found = false;
							break;
						}
					}
					if (found && height[j] > maxH){
						maxH = height[j];
						pos = j;
					}
				}
			}
			result[i] = maxH;
			alreadyUsed[pos] = true;
		}
		return result;
	}

};


int main(){
	FlowerGarden obj;
	int arr1[] = {5,4,3,2,1};
	int arr2[] = { 1, 5, 10, 15, 20 };
	int arr3[] = { 5, 10, 14, 20, 25 };
	vi result = obj.getOrdering(vi(arr1, arr1 + szA(arr1)), vi(arr2, arr2 + szA(arr2)), vi(arr3, arr3 + szA(arr3)));
	for (int i = 0; i < sz(result); i++)
		printf("%d\n", result[i]);
	return 0;
}