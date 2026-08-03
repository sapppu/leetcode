class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        if (x < 10) return true;

        int mag = 1;
        while (x / mag >= 10) mag *= 10;

        while (x > 0) {
            if (x / mag != x % 10) return false;   // outermost pair
            x = (x % mag) / 10;                    // strip first & last digit
            mag /= 100;                             // two fewer digits
        }
        return true;
    }
};