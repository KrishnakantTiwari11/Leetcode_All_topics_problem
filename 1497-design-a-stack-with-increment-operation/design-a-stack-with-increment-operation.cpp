class CustomStack {
    private:
    vector<int>array;
    int maxsize;
public:
    CustomStack(int maxSize) {
        maxsize=maxSize;
    }
    
    void push(int x) {
        if(array.size()!=maxsize)
        {
            array.push_back(x);
        }
    }
    
    int pop() {
        if(array.size()==0)
        {
            return -1;
        }
        else
        {
            int val= array.back();
            array.pop_back();
            return val;
        }
    }
    
    void increment(int k, int val) {
        if(k>array.size())
        {
            for(int i=0;i<array.size();i++)
            {
                array[i]+=val;
            }
        }
        else
        {
             for(int i=0;i<k;i++)
            {
                array[i]+=val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */