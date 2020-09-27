/*      Time Complexity : O(n+m)
                          n : string s長度
                          m : string t長度
                          
        Description :
              1. 透過兩個陣列來統計string s和string t出現過的letter次數
              2. 比較這兩個陣列看看是不是所有letter個數都相同
              
        Note that :
              1. 其他資料說anagram可以不用使用到另一個字串的所有letter
                 但是這個題目卻是只考慮要用到全部letter
              2. 特殊測資 :
                 "ab"
                 "a"
                 "a"
                 "b"

 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        int letterS[26] = {0};
        int letterT[26] = {0};
        int sLen = s.size();
        int tLen = t.size();
        int i, j;
        
        if (s.size() != t.size())
            return false;
        
        // 計算哪些letter在string s出現過的次數
        for (i = 0; i < sLen; i++) {
            j = (int) (s[i] - 'a');
            letterS[j]++;
        }
        
        // 計算哪些letter在string t出現過的次數
        for (i = 0; i < tLen; i++) {
            j = (int) (t[i] - 'a');
            letterT[j]++;
        }
        
        for (i = 0; i < 26; i++) {
            if (letterS[i] != letterT[i])
                return false;
        }
        
        return true;
    }
};
