class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        if (numbers.size() < 2)
            exit(0);
        vector<int> numCopy(numbers);
        sort(numCopy.begin(),numCopy.end());
        int i = 0;
        int j = numCopy.size() - 1;
        while (i < j) {
            if (numCopy[i] + numCopy[j] < target)
                ++i;
            else if (numCopy[i] + numCopy[j] > target)
                --j;
            else 
                break;
        }
        
        int index1 = 0, index2 = 0;
        while (numbers[index1] != numCopy[i]) ++index1;
        while (numbers[index2] != numCopy[j] || index1 == index2) ++index2;
        vector<int> res;
        res.push_back(index1+1);
        res.push_back(index2+1);
        sort(res.begin(), res.end());
        return res;
    }
};