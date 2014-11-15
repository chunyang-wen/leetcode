class Solution {
public:

    int candy(vector<int> &ratings) {
        
        if (ratings.empty())
            return 0;
        if (ratings.size() == 1)
            return 1;
        
        int sum = 0;
        int cnt = 1;
        
        int i = 0;
        int j = 1;
        int len = ratings.size();
        
        bool isVisited = true;
        
        while(j < len) {
            if (ratings[i] < ratings[j]) {
                
                
                if (!isVisited)
                    cnt = 2;
                sum += cnt;
                isVisited = true;
                // sum += cnt;
                ++cnt;
            }
            else if (ratings[i] > ratings[j]){
                
                if (isVisited)
                    cnt = 1;
                sum += cnt;
                isVisited = false;
                // sum += cnt;
                ++cnt;
            }
            else {
                sum += cnt;
            }
            ++i;
            ++j;
        }
        
        // add last member of i
        if (ratings[i] > ratings[i-1] || ratings[i] == 1) {
            sum += cnt;
        }
        else
            sum += 1;
        return sum;
        
    }
    
};