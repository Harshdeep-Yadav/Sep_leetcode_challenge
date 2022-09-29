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


// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int n =arr.size(),left = 0,right = n-k-1;
//         while(left <=right){
//             int mid = left + (right - left)/2;
//             if(x - arr[mid] > arr[mid + k] - x) left = mid + 1;
//             else right = mid - 1;
//         }
//         return vector<int>(arr.begin() + left, arr.begin()+left+k);
//     }
// };