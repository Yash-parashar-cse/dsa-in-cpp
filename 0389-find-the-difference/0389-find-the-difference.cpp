class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for(char c:s){
            ans^=c;
        }
        for(char d:t){
            ans^=d;
        }
        return ans;
    }
};