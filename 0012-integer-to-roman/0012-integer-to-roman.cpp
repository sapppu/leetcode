class Solution {
public:
    string intToRoman(int num) {
        static const string thousands[] = {"", "M", "MM", "MMM"};
        static const string hundreds[]  = {"", "C", "CC", "CCC", "CD",
                                           "D", "DC", "DCC", "DCCC", "CM"};
        static const string tens[]      = {"", "X", "XX", "XXX", "XL",
                                           "L", "LX", "LXX", "LXXX", "XC"};
        static const string ones[]      = {"", "I", "II", "III", "IV",
                                           "V", "VI", "VII", "VIII", "IX"};

        return thousands[num / 1000] +
               hundreds[(num / 100) % 10] +
               tens[(num / 10) % 10] +
               ones[num % 10];
    }
};