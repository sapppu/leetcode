class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.size()) return s;

        int n = s.size(), cycle = 2 * (numRows - 1);
        string result;
        result.reserve(n);

        for (int row = 0; row < numRows; row++) {
            for (int j = row; j < n; j += cycle) {
                result += s[j];
                int between = j + cycle - 2 * row;
                if (row != 0 && row != numRows - 1 && between < n)
                    result += s[between];
            }
        }

        return result;
    }
};