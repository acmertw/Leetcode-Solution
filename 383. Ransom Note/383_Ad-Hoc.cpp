/*      Time Complexity : O(m+n)
                          m : ransomNote字串長度
                          n : magazine字串長度
                          
        Description :
              1. 利用一個陣列統計在magazine所有letter出現的次數
              2. 由ransomNote第一個字元開始, 出現過的letter則在對應的次數減1
                 如果找到對應的陣列次數為0,則表示magazine不可能組合出ransomNote
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int countLetter[26] = {0};
        int magazineLen = magazine.size();
        int ransomNoteLen = ransomNote.size();
        int i;
        
        for (i = 0; i < magazineLen; i++) {
            countLetter[magazine[i] - 'a']++;
        }
        
        for (i = 0; i < ransomNoteLen; i++) {
            if (countLetter[ransomNote[i] - 'a'] == 0)
                return false;
            else
                countLetter[ransomNote[i] - 'a']--;
        }
        
        return true;
    }
};



