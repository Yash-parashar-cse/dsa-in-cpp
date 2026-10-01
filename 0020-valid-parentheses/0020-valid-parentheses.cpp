class Solution {
public:
    bool isValid(string s) {
        
        int n = s.length();
        stack<int> st;

        for(int i=0; i<n; i++){

            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }

            else{

                if(st.empty()) return false;

                int temp = st.top();
                st.pop();

                if((s[i] == '}' && temp == '{') || (s[i] == ')' && temp == '(') || (s[i] == ']' && temp == '[')  ){
                    continue;
                }
                else{
                    return false;
                }
            }

        }
        return st.empty();
    }
};