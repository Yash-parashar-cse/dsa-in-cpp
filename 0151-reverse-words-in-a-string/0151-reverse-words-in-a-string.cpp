#include<algorithm>
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());
        int i = 0;
        int j = 0;

        while(i < n){
            // skip the extra  whitespaces..
            while(i < n && s[i]==' '){
                i++;
            }
            if(i==n) break;
            // To include a single space between adjacent words of the string..
            if(j>0){
                s[j] = ' ';
                j++;
            }
            // copy the original reversed word to the front of the string..
            int start = j;
            while(i<n && s[i]!=' '){
                s[j] = s[i];
                i++;
                j++;
            }
            // Now, reverse the word to get the correct order..
            reverse(s.begin() + start, s.begin()+j);
        }
        // resize the string size to ignore the leftover spaces at the end if there any..
        s.resize(j);
        return s;

    }
};
