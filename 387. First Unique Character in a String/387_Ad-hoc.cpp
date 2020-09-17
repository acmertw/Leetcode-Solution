/*      Time Complexity : O(n)
                          n : string s長度
                          
        Description :
              1. 利用兩個陣列紀錄26個小寫字母出現次數和最後出現的index
              2. 由字串第一個字元到字串最後一個字元, 紀錄出現次數和index
              3. 在出現次數只有一次的所有字元裡比較minIndex和字元index
                 如果minIndex == stringLen, 表示沒有只出現一次的字元
                 
 */

class Solution {
public:
    int firstUniqChar(string s) {
        int countRepeat[26] = {0};
        int letterIndex[26];
        int stringLen = s.size();
        int i, minIndex;
        
        for (i = 0; i < 26; i++)
            letterIndex[i] = -1;
        
        for (i = 0; i < stringLen; i++) {
            countRepeat[s[i] - 'a']++;
            letterIndex[s[i] - 'a'] = i;
        }
        
        minIndex = stringLen;
        for (i = 0; i < 26; i++) {
            if (countRepeat[i] == 1 && letterIndex[i]<minIndex)
                minIndex = letterIndex[i];
        }
        
        if (minIndex == stringLen)
            return -1;
        else
            return minIndex;
    }
};
