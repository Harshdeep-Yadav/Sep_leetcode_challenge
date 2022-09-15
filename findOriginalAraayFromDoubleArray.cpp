class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        map<int,int>mp; // for freq
        int n=changed.size();
        if(n%2) // if this is true than we can do age 
        { 
            return res;    
        }
        for(auto it:changed)
        {
            mp[it]++;
        }
        sort(changed.begin(),changed.end()); // sort kar rhe warna ni hoga kisi ki double value kahi aur hogi kisi ki kahi aur {2,1} isme 2 ka double milega hi ni isiliye {1,2 } karenge sort karke
        
        for(auto it:changed)
        {
            if(mp[it]==0){ // agar freq 0 hai single ki 
                continue;
            }
            if(mp[2*it]==0){ //aur doble ki bhi  khali array return ke do fir
                return {};
            }
            if(mp[it]&&mp[2*it]){ // jab dono present ho doble bhi aur single bhi to us index ke element ko res array me store kar lenge baki freq dec kar denge
                mp[2*it]--;
                res.push_back(it);
                mp[it]--;
            }
        }
        return res;
    }
};