// class Solution { // brute froce
// public:
//     bool isPalindrom(string s){
//         int n=s.size();
//         int i=0;
//         int j=n-1;
//         while(i<j){
//             if(s[i]!=s[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         vector<vector<int>> ans;
//         for(int i=0;i<words.size();i++)
//         {
//             for(int j=0;j<words.size();j++){
//                 if(i==j)
//                     continue;
                
//                 string word=words[i]+words[j];
//                 if(isPalindrom(word))
//                     ans.push_back({i,j});
//             }  
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
    
//       bool isPalindrome(string& s) {   
//           int l=0, r=s.size()-1;
//           while(l<r){if(s[l++]!=s[r--]) return false;}
//           return true; 
//     }


//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         vector<vector<int>> ans;
//         int n = words.size();
//         if(n<2) return ans;
//         unordered_map<string, int> m;
//         for(int i=0;i<n;++i){
            
//             auto s= words[i];
//             reverse(s.begin(),s.end());
//             m[s]=i;
//         }
        
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<=words[i].size(); ++j){
//                 string st1 = words[i].substr(0,j); // prefix
//                 string st2 = words[i].substr(j);    //sufix           
                 
//                  if(m.count(st1) && isPalindrome(st2) && m[st1] != i) {
//                      ans.push_back({i, m[st1]});    
//                  }

//                  if(!st1.empty() && m.count(st2) && isPalindrome(st1) && m[st2] != i) {
//                      ans.push_back({m[st2], i});
//                  }
//             }            
//         }
//         return ans;
//     }

    
// };


struct TrieNode
{
    TrieNode *child[26]={};
    int curIndex=-1;
    vector<int> wordIndex;
};
class Solution
{
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    TrieNode *root;
    void insert(string &s, int index)
    {
        TrieNode *cur = root;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int c = s[i] - 'a';
            if (cur->child[c] == nullptr)
                cur->child[c] = new TrieNode();
            if (isPalindrome(s, 0, i))
                cur->wordIndex.push_back(index);
            cur = cur->child[c];
        }
        cur->wordIndex.push_back(index);
        cur->curIndex = index;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
        {
            TrieNode *cur = root;
            string &s = words[i];
            for (int j = 0; j < s.size(); j++)
            {
                if (cur->curIndex != -1 && cur->curIndex != i && isPalindrome(s, j, s.size() - 1))
                    ans.push_back({i, cur->curIndex});
                cur = cur->child[s[j] - 'a'];
                if (cur == nullptr)
                    break;
            }
            if (cur == nullptr)
                continue;
            for (int j : cur->wordIndex)
            {
                if (i == j)
                    continue;
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};