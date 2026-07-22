class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char i : s){
            if(i == '(' || i=='[' || i=='{'){
                st.push(i);
            }else{
                if(st.empty())return false;
                char tp = st.top();
                if(tp =='[' && i==']')st.pop();
                else if(tp == '{' && i=='}')st.pop();
                else if(tp == '(' && i==')')st.pop();
                else return false;
            }
        }
        return st.size() == 0;
    }
};