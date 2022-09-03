class Solution {
public:
    vector<int>ans;
    
    //for count the number of digits which equals to n or not
    int findCount(int n){
        int count=0;
        while(n>0){
            count++;
            n=n/10;
        }
        return count;
    }
    
    //for find the number which we are going to store in vector
    void findNumber(int num,int n,int k){
        // num=n
        if(findCount(num)==n)
        {
            ans.push_back(num);
            return;
        }
       
        for(int i=0;i<=9;i++){
            int ld=num%10; // last-digit
            if(abs(ld-i)==k){
             int res=num*10+i;
                findNumber(res,n,k);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
      
        for(int i=1;i<=9;i++) // loop for starting digits
        {
            findNumber(i,n,k);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        deque<int> q{1,2,3,4,5,6,7,8,9};
        
        while(--n>0){
            int siz=q.size();
            for(int i=0;i<siz;i++){
                int p=q.front();
                q.pop_front();
            
            for(int j=0;j<10;j++){
                  if (abs((p% 10) - j) == k) 
                {
                    q.push_back(p*10+j);
                }
            }
            }
        }
        return vector<int>{q.begin(),q.end()};
    }
};





