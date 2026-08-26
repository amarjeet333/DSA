class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left=0,right=0;
        string ans="";
        int ones=0,i;

        while( right<s.size()){
            if(s[right]=='1')
            ones++;

            while(ones>k){
                if(s[left++]=='1')
                ones--;
            }

            if(ones==k){
                while(left<=right && s[left]=='0')
                    left++;

                string cur=s.substr(left,right-left+1);

                if( ans.empty() || 
                    ans.size() > cur.size() ||
                    (ans.size() == cur.size() && cur < ans)
                )
                ans=cur;        
            }
            right++;
        }
        
        return ans;
        
    }
};