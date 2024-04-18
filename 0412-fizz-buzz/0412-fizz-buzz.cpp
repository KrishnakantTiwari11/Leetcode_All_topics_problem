class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        string a="FizzBuzz";
        string b="Fizz";
        string c="Buzz";
        
        
       for(int i=1;i<=n;i++)
       {
        if(i%3==0 && i%5==0)
        {
            answer.push_back(a);
        }
        else if(i%3==0)
        {
            answer.push_back(b);
        }
        else if(i%5==0)
        {
            answer.push_back(c);
        }
        else
        {
            answer.push_back(to_string(i));
        }
       }
        return answer;
        
    }
};