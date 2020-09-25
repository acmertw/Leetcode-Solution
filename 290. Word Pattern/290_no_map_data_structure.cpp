/*      Time Complexity : O(n * m * t)
                          n : pattern長度
                          m : 所有word裡最長的長度
                          t : string s裡word個數
        
        Description :
              1. 只需要滿足 :
                       a. 同一個pattern對應到同一個word
                       b. 不同pattern不能對應到同一個word
              2. pattern[i] :
                       a. 檢查mapped是否已經記錄下對應的word
                          - 檢查mapped出現過對應的word和現在由iss拿到的word是否相同
                       b. 如果mapped還沒有記錄對應的word
                          - 檢查mapped和現在由iss拿到的word是不是有重複
                            有重複則表示不同pattern卻有相同對應的word
                            沒有重複,則記錄該pattern和對應的word
        
         Note that :
             1. iss >> word  ==> 如果最後有成功則在做if判斷時,iss會變成true
             2. 幾個測資需要小心 :
                "abba"
                "dog dog dog dog"
                
                "a"
                "a b c"
                
                "abc"
                "a"
 */
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        string word;
        string mapped[26];  // 紀錄每個pattern所對應的word
        int i, j, k, patternLen = pattern.size();
        
        for (i = 0; i < patternLen; i++) {
            iss >> word;  
            
            if (!iss) { // iss已經讀取完整個string但是patten還沒結束, 因此word個數小於pattern個數
                return false;
            }
            
            j = pattern[i] - 'a';
            if (mapped[j].size() == 0) {
                // 如果該pattern還沒有對應的word, 則比較其他pattern對應的word,看看是否有重複出現
                for (k = 0; k < 26; k++) {
                    if (word.compare(mapped[k]) == 0)  // pattern不同,但是卻對應到相同的word
                        return false;
                }
                // 最後都沒有重複的word,則將該pattern和word的對應記錄下來
                mapped[j] = word;
            } else { // 該pattern之前有出現過且記錄下對應的word
                // 相同pattern,但是word不同
                if (word.compare(mapped[j]) != 0)
                    return false;
            }
        }
        
        /* 最後再做一次iss >> word, 是為了判斷後面是否還有可讀取的word
           在上一次iss >> word後,因為iss還有其他word,所以iss是true
           因此現在iss是上次的結果,所以要再做一次iss >> word
         */
        iss >> word;
        if (iss)
            return false;  // 最後,如果pattern結束了,但是還有更多word,則也表示false
        else
            return true;
    }
};
