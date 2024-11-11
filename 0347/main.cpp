class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 优先队列

        // 1. 统计频率
        // num & freq
        unordered_map<int, int> record;

        for( int i = 0 ; i < nums.size() ; i++ ) {
            record[nums[i]] ++;
        }

        // 2. 按照频率维护一个最多包含 k 个元素的最小堆 
        // 只要当前的元素能够超过目前找到的前 k 个元素中排在末尾的元素 那么就更新 pq
        // pair ==> freq, num
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for( unordered_map<int, int>::iterator iter = record.begin() ; iter != record.end() ; iter++ ) {
            int num = iter->first;
            int freq = iter->second;

            if( pq.size() >= k ) {
                if( freq > pq.top().first ) {
                    pq.pop();
                    pq.push(make_pair(freq, num));
                }
            } else {
                pq.push(make_pair(freq, num));
            }
        }

        vector<int> res;

        while( !pq.empty() ) {
            int num = pq.top().second;
            res.push_back( num );
            pq.pop();
        }

        return res;
    }
};
