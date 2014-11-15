class Solution {
public:
	int findMin(vector<int> &num) {
		// trivial O(n) can solve it
		// try to solve it using binary search

		int left = 0;
		int right = num.size();
		int mid = 0;

		while (left < right) {
			mid = (right-left)/2 + left;

			if (num[mid] > num[left]) { // reverse sequence
				if (num[left] > num[right-1])
					left = mid + 1;
				else {
					return num[left];
				}
			}
			else if (num[mid] < num[left]) {
				right = mid + 1;
				++left;
			}
			else
				return num[left];

		}


	}
};