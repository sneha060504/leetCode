class Solution {
public:
    string minRemoveToMakeValid(string s) {
    int bal =0;
    stack<char> res ;
      for(char i : s){
        if(i =='(') {
            bal++;
        }
        else if(i == ')'){
            if(bal ==0) continue;
                bal--;
            
        }
        res.push(i);
      }  
      string temp = "";
      for(stack <char> i =res;!i.empty();i.pop())
        temp += i.top();
    string ans ="";
    for(int i =0;i<temp.size();i++){
        if(temp[i]=='(' && bal-- >0)continue;
        ans += temp[i];
    }
    reverse(ans.begin(),ans.end());
    return ans;
      
    }
};