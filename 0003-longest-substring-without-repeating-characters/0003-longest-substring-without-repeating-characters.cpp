class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[128] = {0};
        int maxsum = 0;
        int left = 0;

        for(int right = 0; right<s.size(); right++){
            freq[s[right]]++;
            

            while(freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
            }

            maxsum = max(maxsum, right-left+1);
        }
        return maxsum;



    }
};