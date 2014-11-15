class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {

		int low = 0;
		int height = n;
		vector<int> res(2,-1);
		int mid;

		while (low < height) {
			mid = (height-low)/2 + low;
			if (A[mid] >= target) {
				height = mid;
			}
			else {
				low = mid+1;
			}
		}
		res[0] = height;

		low = 0;height = n;
		while (low < height) {
			mid = (height-low)/2 + low;
			if (A[mid] > target) {
				height = mid;
			}
			else {
				low = mid+1;
			}
		}

		res[1] = low-1;

		if(res[0] > res[1]) {
			return vector<int>(2,-1);
		}

		if (res[0] == res[1] && A[res[0]] != target) {
			return vector<int>(2,-1);
		}

		return res;


	}
};