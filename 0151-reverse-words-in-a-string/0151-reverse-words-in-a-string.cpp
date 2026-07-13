#include<stack>
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans;
        int n = s.size();
        int i = 0;
        while(i < n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(i==n) break;
            int start = i;
            while(i<n && s[i]!=' '){
                i++;
            }
            st.push(s.substr(start,i-start));
        }
        while(!st.empty()){
            ans = ans + st.top();
            ans.push_back(' ');
            st.pop();
        }
        ans.pop_back();
        return ans;

    }
};