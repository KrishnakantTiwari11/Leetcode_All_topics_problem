class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>t_freq;
        unordered_map<char,int>window_freq;
        for(auto ch:t)
        {
            t_freq[ch]++;
        }
        int min_len=INT_MAX;
        int formed=0,required=t_freq.size();
        int left=0,right=0,min_left=0;
        while(right<s.size())
        {
            char c=s[right];
            window_freq[c]++;
            if(t_freq.find(c)!=t_freq.end() && window_freq[c]==t_freq[c])
            {
                formed++;
            }
            while(formed==required && left<=right)
            {
                char c=s[left];
                if(right-left+1<min_len)
                {
                    min_left=left;
                    min_len=right-left+1;
                }
                window_freq[c]--;
                if(t_freq.find(c)!=t_freq.end() && window_freq[c]<t_freq[c])
                {
                    formed--;
                }
                left++;
            }
            right++;
        }
        if(min_len==INT_MAX)
        {
            return "";
        }
        return s.substr(min_left,min_len);
    }
};