class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int sum=0;
        for(auto it :nums)
        {
           if(it%2==0) {
                sum+=it;
            }
        }
        for(auto i:queries){
            int ind=i[1];
            int val=i[0];
            
            if(nums[ind]%2==0)
            {
                sum-=nums[ind];    
            }
            nums[ind]+=val;
            if(nums[ind]%2==0)
            {
                sum+=nums[ind];
            }
            res.push_back(sum);
        }
        return res;
    }
};