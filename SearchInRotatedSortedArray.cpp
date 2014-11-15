class Solution {
public:
	int search(int A[], int n, int target) {

		int low = 0;
		int high = n;
		int mid;
		while (low < high) {
			mid = (high - low)/2 + low;

			if (A[mid] == target)
				return mid;
			else if (A[mid] > target) {
				if (A[low] > target) {
					++low;
				}
				else {
					high = mid;
				}
			}
			else {
				if (A[high-1] < target) {
					--high;
				}
				else {
					low = mid + 1;
				}
			}

		}

		return -1;

	}
};