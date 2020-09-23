/*      Time Complexity : O(n)
                          n : 字串s長度
                          
        Description :
              1. 用istringstream將string當作stream來用
              2. 只有遇到word才會開始存取,一直到遇到space
                 
        Note that :
              1. 需要考慮邊界測資
                 ""
                 " "
 */
class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string tmp;
        string reversedS = "";
        
        while (iss >> tmp) {
            tmp += " ";
            tmp += reversedS;
            reversedS = tmp;
        }
        
        return reversedS.substr(0, reversedS.size()-1);
    }
};
