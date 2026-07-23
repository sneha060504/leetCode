class Solution {
public:
    int minAddToMakeValid(string s) {
       int bal =0;
        int res =0;
        for(char i : s){
            if(i == '(') bal++;
            else{
                if(bal ==0) res++;
                else bal--;
            }
        }
        return bal+res;  
    }
};