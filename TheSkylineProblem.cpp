class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        priority_queue<pair<int,int>>  pq; 
        
        vector<int> res; //storing starting index and ending index of a building
        
        for(auto b:buildings)
        {
            res.push_back(b[0]);
            res.push_back(b[1]); 
        }
        
        sort(res.begin(),res.end());
        
        int x=unique(res.begin(),res.end())-res.begin(); //
        
        int y=0;
        int prev_hgt=0;
        
        vector<vector<int>> ans;
        for(int i=0;i<x;i++)
        {


                while(y<buildings.size()&&buildings[y][0]<=res[i])
                 pq.push(make_pair(buildings[y][2],buildings[y][1])), y++;
                
                while(!pq.empty() && pq.top().second<=res[i]) 
                {
                    pq.pop();    
                }

                int nowh=pq.empty()?0:pq.top().first;

                if(nowh!=prev_hgt)
                {
                    ans.push_back({res[i],nowh});
                    prev_hgt=nowh;
                }
        }
        return ans; 
    }
};