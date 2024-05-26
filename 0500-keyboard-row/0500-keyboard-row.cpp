class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
    unordered_set<char> row1 {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    unordered_set<char> row2 {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    unordered_set<char> row3 {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    for(int i=0;i<words.size();i++)
    {
        int value=-1;
        bool push=true;
        for(int j=0;j<words[i].size();j++)
        {
            char lowerch=tolower(words[i][j]);
            if(row1.count(lowerch))
            {
                if(value==-1)
                {
                    value=1;
                }
                else if(value!=1)
                {
                    push=false;
                    break;
                }
            }
            if(row2.count(lowerch))
            {
                if(value==-1)
                {
                    value=2;
                }
                else if(value!=2)
                {
                    push=false;
                    break;
                }
            }
            if(row3.count(lowerch))
            {
                if(value==-1)
                {
                    value=3;
                }
                else if(value!=3)
                {
                    push=false;
                    break;
                }
            }
           
        }
        if(push)
        {
            result.push_back(words[i]);
        }

    }

    return result;
    }
};