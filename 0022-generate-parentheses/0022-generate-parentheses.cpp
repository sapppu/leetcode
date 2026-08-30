#include <vector>
#include <string>

class Solution {
public:
    void backtrack(std::vector<std::string>& res, std::string curr, int openP, int closeP, int maxP) {
        if (curr.length() == maxP * 2) {
            res.push_back(curr);
            return;
        }
        if (openP < maxP) backtrack(res, curr + "(", openP + 1, closeP, maxP);
        if (closeP < openP) backtrack(res, curr + ")", openP, closeP + 1, maxP);
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
};