class MyCalendarTwo {
private:
    map<int, int> m;
public:
    
   
    bool canAdd(int n){
        int count = 0;
        for (auto entry: m){
            count+=entry.second;
            if(count>n) return false;
        }
        return true;
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        if(canAdd(2)) return true;
        else{
            m[start]--;
            m[end]++;
            return false;
        }
    }
};