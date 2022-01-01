class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        for(int i=0; i<nums.size();i++)
        {
            int sum=target-nums[i];
            if(map.find(sum)!=map.end())
            {
                res.push_back(i);
                res.push_back(map[sum]);
                return res;
            }
            map[nums[i]]=i;
        }
                return res;
    }
};