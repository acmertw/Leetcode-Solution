/*      Time Complexity : 
              O(m*n)  
              m : longest string length
              n : number of string vector
                          
        Description :
              1. 以strs[0]為基準和其他strs比較每個字元
              2. 如果比較過程中有發現不一樣的字元則return前面的prefix部分
              3. 比完所有strs後,檢查strs[0]是否到達'\0', 則return 字串strs[0]
                 表示所有strs都相同, 或者strs[0]為其他所有strs的相同prefix
        
        Note that :
              需要考慮到邊界條件
              ["flower","","flight"]
              ["","abc","flight"]
              []
              
 */
 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int indexChar = 0, indexStrs = 0;
        
        // 考慮邊界條件 : 完全沒有string
        if (strs.size() == 0)
            return "";
        
        while (1) {
            for (indexStrs = 1; indexStrs < strs.size(); indexStrs++) {
                if (strs[indexStrs][indexChar] != strs[0][indexChar])
                    return strs[0].substr(0, indexChar);
            }
            
            if (strs[0][indexChar] == '\0')
                return strs[0];
            
            indexChar++;
        }
    }
};
