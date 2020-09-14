class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);
        if (found > 0) {
            return found;
        } else if (found < 0) {
            return found;
        } else {
            return 0;
        }
    }
};
