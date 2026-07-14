class Solution {
public:
    // global variables..
    int start = 0;
    int max = 0;
    void expand(string& s, int left, int right) {

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        int length = right - left - 1;
        if (length > max) {
            max = length;
            start = left + 1;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // check for odd length..
            expand(s, i, i);

            // check for even length..
            expand(s, i, i + 1);
        }
        return s.substr(start, max);
    }
};