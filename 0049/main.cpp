class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> record;

        for( int i = 0 ; i < strs.size() ; i++ ) {
            // 对每个单词排序后、如果每个单词包含字母相同、就可以整理为成一样的字符串了
            string ss = strs[i];
            sort(ss.begin(), ss.end());

            record[ss].push_back( i );
        }

        vector<vector<string>> res;
        int i = 0;
        for( unordered_map<string, vector<int>>::iterator iter = record.begin() ; iter != record.end() ; iter++ ) {
            res.push_back(vector<string>());
            string k = iter->first;
            vector<int> vec = iter->second;

            for( int j = 0 ; j < vec.size() ; j++ ) {
                // 对每一个分组进行遍历
                // 根据记录下来的索引把原始的字符串填充进去
                res[i].push_back( strs[vec[j]] );
            }
            i++;
        }

        return res;
    }
};
