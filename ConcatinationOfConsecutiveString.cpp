class Solution {
public:
    int mod =1e9+7;
   
    int concatenatedBinary(int n) {
        long long ans=0;
        int i=1;
        while(i<=n)
        {
            ans=((ans<<(1+int(log2(i))))%mod+i)%mod;
            
            i++;
        }
        return ans;
    }
};