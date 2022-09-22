class Solution {
public:
    string reverseWords(string s) { // two pointer approach
        int l=0;
        int r=0;
        while(l<s.size())
        {
            while(r<s.size()&&s[r]!=' ')
            {
                r++;
            }
            // khali space milte hi ververse kar dega
            reverse(s.begin()+l,s.begin()+r);
            l=r+1; // next word pe chala jayega
            r=l;    // both l,r on same word with same index 
        }
        return s;
    }
};