class Solution {
public:
    bool ism(char x, char c){
        return (x == '(' && c == ')') || (x == '{' && c == '}') || 
               (x == '[' && c == ']');
    }

    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }else{
                if(!st.empty()){
                    char x = st.top();
                    st.pop();

                    if(!ism(x, c)){
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};
