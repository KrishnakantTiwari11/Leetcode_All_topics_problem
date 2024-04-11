#include <stack>
using namespace std;
class Solution {
public:
    
    bool isValid(string s) {
        stack<char> mystack;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                mystack.push(')');
            }
            else if(s[i]=='{')
            {
                mystack.push('}');
            }
            else if(s[i]=='[') 
            {
                mystack.push(']');
            }
            else if(mystack.empty())
            {
                 return false;
            }
            else
            {
                char top=mystack.top();
                if(s[i]==top)
                {
                     mystack.pop();
                }
               else{
                   return false;
               }
            
            }
            
            }
          return mystack.empty();
        
    }
};