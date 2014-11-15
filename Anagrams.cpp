class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        typedef unordered_map<string, int> Umap;
        Umap hashtable;
        vector<string> res;
        for(int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            Umap::iterator ite = hashtable.find(s);
            if(ite == hashtable.end())
                hashtable.insert(Umap::value_type(s, i));
            else
            {
                if(ite->second != -1)
                {
                    res.push_back(strs[ite->second]);
                    ite->second = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};