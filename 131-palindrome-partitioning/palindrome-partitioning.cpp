class Solution {
public:
    void solve(vector<vector<string>> & res,int ind,string word,vector<string>&temp){
        if(ind>=word.size()){
            res.push_back(temp);
            return;
        }
        for(int i=ind;i<word.size();i++){
            if(isPal(ind,i,word)){
                temp.push_back(word.substr(ind,i-ind+1));
                solve(res,i+1,word,temp);
                temp.pop_back();
            }
        }
    }
    bool isPal(int low,int high,string word){
        while(low<=high){
            if(word[low]!=word[high])return false;
            low++;
            high--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        solve(res,0,s,temp);
        return res;
    }
};