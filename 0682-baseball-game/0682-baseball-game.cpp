class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string i : operations){
            if(i == "C"){
                st.pop();
            }
            else if(i == "D"){
                st.push(st.top()*2);
            }else if(i == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }else{
                st.push(stoi(i));

            }
        }
        int res =0;
        while(!st.empty()){
            res = res + st.top();
            st.pop();
        }
        return res;
    }
};