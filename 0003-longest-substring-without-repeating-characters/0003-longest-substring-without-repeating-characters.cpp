class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128];
        memset(last, -1, sizeof(last));
        int maxLen = 0, left = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            if (last[s[right]] >= left)
                left = last[s[right]] + 1;

            last[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};