class Solution {
private:
string solve;
    void findkth(int& n, int& k, string& curr){
        if(curr.length() == n){
            k--;
            if(!k){
                solve = curr;
            }
            return;
        }
        if(curr.length() == 0){
        curr += 'a';
        findkth(n, k, curr);
        if(solve != "") return;
        curr.erase(curr.length()-1);
        curr += 'b';
        findkth(n, k, curr);
        if(solve != "") return;
        curr.erase(curr.length()-1);
        curr += 'c';
        findkth(n, k, curr);
        if(solve != "") return;
        curr.erase(curr.length()-1);
        }else{
            if(curr.back() != 'a'){
                curr += 'a';
                findkth(n, k, curr);
                if(solve != "") return;
                curr.erase(curr.length()-1);
            }
            if(curr.back() != 'b'){
                curr += 'b';
                findkth(n, k, curr);
                if(solve != "") return;
                curr.erase(curr.length()-1);
            }
            if(curr.back() != 'c'){
                curr += 'c';
                findkth(n, k, curr);
                if(solve != "") return;
                curr.erase(curr.length()-1);
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        string curr = "";
        findkth(n, k, curr);
        return solve;
    }
};