/*      Time Complexity : O(n) + O(n) = O(n)
                          n : 字串s長度
                          
        Description :
              1. removeRedundantSpace()
                 消除字串s裡面多餘的space,只保留兩個word之間的一個space
              2. swapWords()
                 消除多餘space後,剩下的字串只會是空字串或是不含多餘space的字串
                 利用另一個string來記錄交換word後的字串
                 
        Note that :
              1. 需要考慮邊界測資
                 ""
                 " "
 */
class Solution {
public:
    /* Remove dedundant empty space */
    void removeRedundantSpace(string& s) {
        int indexOfS;
        int indexOfRemovedS = -1;
        bool validSpace = false;
        
        for (indexOfS = 0; s[indexOfS] != '\0'; indexOfS++) {
            if (s[indexOfS] == ' ' || s[indexOfS] == '\t') {
                if (validSpace == true) {
                    s[++indexOfRemovedS] = ' ';
                    validSpace = false;
                }
            } else {
                s[++indexOfRemovedS] = s[indexOfS];
                validSpace = true;
            }
        }
        
        if (indexOfRemovedS >= 0) {
            if (s[indexOfRemovedS] == ' ')
                s.erase(indexOfRemovedS);
            else
                s.erase(indexOfRemovedS+1);
        } else {
            s = "";
        }
    }
    
    /* 利用另一個string來記錄交換word後的字串 */
    string swapWords(string s) {
        string swappedS;
        int start = -1, end = s.size();
        int indexOfS = s.size()-1;
        
        while (indexOfS >= 0) {
            if (s[indexOfS] == ' ') { // 找到space表示到了word的結尾
                start = indexOfS+1;
                swappedS += s.substr(start, (end-start)); // 將word [s.substr(start, end-start)] 加入到swappedS
                swappedS += " ";  // 加上兩個word之間的space
                end = indexOfS;
            }
            
            indexOfS--;
        }
        
        swappedS += s.substr(0, end);  // 最後一個word後面就是'\0',所以最後再加上去
        
        return swappedS;
    }
    
    string reverseWords(string s) {
        string swappedString;
        
        removeRedundantSpace(s);
        
        swappedString = swapWords(s);
        
        return swappedString;
    }
};
