// we need to prove that we only search numbers after

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        sort(num.begin(), num.end());
        int res, dis = INT_MAX;
        for(int i = 0; i < n - 2; i++)
        {
            int target2 = target - num[i], tmpdis;
            int tmpres = twoSumClosest(num, i+1, target2);
            if((tmpdis = abs(tmpres - target2)) < dis)
            {
                res = tmpres + num[i];
                dis = tmpdis;
                if(res == target)
                    return res;
            }
        }
        return res;
    }
    
    int twoSumClosest(vector<int> &sortedNum, int start, int target)
    {
        int head = start, tail = sortedNum.size() - 1;
        int res, dis = INT_MAX;
        while(head < tail)
        {
            int tmp = sortedNum[head] + sortedNum[tail];
            if(tmp < target)
            {
                if(target - tmp < dis)
                {
                    res = tmp;
                    dis = target - tmp;
                }
                head++;
            }
            else if(tmp > target)
            {
                if(tmp - target < dis)
                {
                    res = tmp;
                    dis = tmp - target;
                }
                tail--;
            }
            else
                return target;
        }
        return res;
    }
};