class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (char c : s) { t += c; t += '#'; }

        int n = t.size();
        vector<int> p(n, 0);
        int c = 0, r = 0;
        int maxLen = 0, center = 0;

        for (int i = 0; i < n; i++) {
            if (i < r)
                p[i] = min(r - i, p[2 * c - i]);   // mirror trick

            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
                   t[i + p[i] + 1] == t[i - p[i] - 1])
                p[i]++;

            if (i + p[i] > r) { c = i; r = i + p[i]; }
            if (p[i] > maxLen) { maxLen = p[i]; center = i; }
        }

        return s.substr((center - maxLen) / 2, maxLen);
    }
};