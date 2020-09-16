/*      Time Complexity : O(n)
                          n : 字串s長度
                          
        Description :
              1. 由字串後面向前開始找最後一個word
              2. 尋找第一個不是' '的位置,也就是最後一個word的最後一個字元位置
              3. 尋找第一個word的第一個字元位置
              4. 需要注意邊界條件 :
                 "a "
                 " "
                 ""

 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;
        int indexLastPosOfLastWord;
        
        // 尋找第一個不是' '的位置, 也就是最後一個word的最後一個字元位置
        while (index >= 0 && s[index] == ' ')
            index--;
        
        // 如果全部找完都是' ', 則return 0
        if (index < 0)
            return 0;
        
        // 紀錄最後一個word的最後一個字元位置
        indexLastPosOfLastWord = index;
        
        // 尋找第一個word的第一個字元位置
        while (index >= 0 && s[index] != ' ')
            index--;
        
        return indexLastPosOfLastWord - index;
    }
};
