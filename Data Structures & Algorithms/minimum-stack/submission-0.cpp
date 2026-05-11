class MinStack {
public:
    vector<int> v;
    int topp;
    MinStack() {    
        topp = -1;
    }
    
    void push(int val) {
        topp++;
        if(topp == v.size()){
            v.push_back(val);
        }else{
            v[topp] = val;
        }
    }
    
    void pop() {
        topp--;
    }
    
    int top() {
        return v[topp];
    }
    
    int getMin() {
        int m = *min_element(v.begin(), v.begin() + topp + 1);
        return m;
    }
};
