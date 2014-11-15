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
			
			if (num[mid] > num[left]) {
			    if (num[mid] <= num[right-1]) {
			        // common sequence
			        right = mid;
			    }
			    else if (num[mid] > num[right-1]) {
			        left = mid + 1;
			    }
			}
			else if (num[mid] < num[left]) {
			    if (num[mid] <= num[right-1]) {
			        right = mid + 1;
			        ++left;
			    }
			}
			else { // num[mid] == num [left]
			    ++left;
			}

		}

		return num[left-1];

	}
};