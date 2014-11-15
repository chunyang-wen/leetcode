class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        vector<vector<int> > res;
        unordered_map<int, vector<pair<int, int> > >pairs;
        pairs.reserve(n*n);
        sort(num.begin(), num.end());
        
        for(int i = 0; i < n; i++)
            for(int j = i+1 ; j < n; j++)
                pairs[num[i]+num[j]].push_back(make_pair(i,j));
        
        for(int i = 0; i < n - 3; i++)
        {
            if(i != 0 && num[i] == num[i-1])continue;//防止第一个元素重复
            for(int j = i+1; j < n - 2; j++)
            {
                if(j != i+1 && num[j] == num[j-1])continue;//防止第二个元素重复
                if(pairs.find(target - num[i] - num[j]) != pairs.end())
                {
                    vector<pair<int, int>> &sum2 = pairs[target - num[i] - num[j]];
                    bool isFirstPush = true;
                    for(int k = 0; k < sum2.size(); k++)
                    {
                        if(sum2[k].first <= j)continue;//保证所求的四元组的数组下标是递增的
                        if(isFirstPush || (res.back())[2] != num[sum2[k].first])
                        {
                            res.push_back(vector<int>{num[i], num[j], num[sum2[k].first], num[sum2[k].second]});
                            isFirstPush = false;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};