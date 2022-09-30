class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int>ans;
        priority_queue<pair<int,int>> maxheap;
        for(int i=0;i<n;i++){
            int temp=abs(arr[i]-x);
            maxheap.push({temp,arr[i]});
            if(maxheap.size()>k){
                maxheap.pop();    
            }
        }
        while(maxheap.size()>0){
            ans.push_back(maxheap.top().second);
            maxheap.pop();
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


// 
// };