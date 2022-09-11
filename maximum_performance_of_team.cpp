class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>v; // for converting speed and efficiency in single array
        priority_queue<int,vector<int>,greater<int>> pq;   //min heap
        
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i],speed[i]}); // push on the basis of efficiency
        }
        
       sort(v.begin(),v.end()); // sorting 
       long sum=0,ans=0;
        for(int i=n-1;i>=0;i--) // traversing from last beacause we want max speed
        {
            sum+=v[i].second;
            pq.push(v[i].second);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,sum*v[i].first
        }
        return ans%1000000007;
    }
};

