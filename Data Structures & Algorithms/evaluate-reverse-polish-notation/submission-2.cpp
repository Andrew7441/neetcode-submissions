class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;

        for(string s : tokens){
            if(s == "+" || s == "*" || s == "/" || s == "-"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                switch(s[0]){
                    case '+':
                        ans = num2 + num1;
                        break;

                    case '-':
                        ans = num2 - num1;
                        break;
                    
                    case '/':
                        ans = num2 / num1;
                        break;
            
                    case '*':
                        ans = num2 * num1;
                        break;
                }
                st.push(ans);
            }else{
                int x = stoi(s);
                st.push(x);
            }
        }
        ans = st.top();
        return ans;
    }
};
