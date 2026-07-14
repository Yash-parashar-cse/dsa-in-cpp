class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        int result = 0;
        int sign = 1;

        while(i < n && s[i]==' '){
            i++;
        }
        if(i<n && s[i] == '+'){
            sign = 1;
            i++;
        }else if(i<n && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        while(i<n && isdigit(s[i])){
            int digit = s[i]-'0';
            if(result > (INT_MAX/10)){
                if(sign == -1){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
            if(result == (INT_MAX/10) && digit>7){
                if(sign == -1){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
            result = result *10 + digit;
            i++;
        }
        
        return result*sign;
    }
};