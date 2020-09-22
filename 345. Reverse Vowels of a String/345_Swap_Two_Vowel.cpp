/*      Time Complexity : O(n)
                          n : 字串s長度
                          
        Description :
              1. 由起點和後端兩側找母音(a,e,i,o,u)
              2. 找到後就互相交換
              
        Note that :
              1. 考慮邊界測資
                 ""
                 " "
              2. 要考慮大小寫不同   
 */
class Solution {
public:
    string reverseVowels(string s) {
        int front = 0;
        int tail = s.size()-1;
        char tmp;
        
        while (front < tail) {
            // find vowel from tail of string s
            while (front < tail) {
                if (s[tail] == 'a' || s[tail] == 'A' ||
                    s[tail] == 'e' || s[tail] == 'E' ||
                    s[tail] == 'i' || s[tail] == 'I' ||
                    s[tail] == 'o' || s[tail] == 'O' ||
                    s[tail] == 'u' || s[tail] == 'U') {
                    break;
                }
                tail--;
            }
            
            // find vowel from front of string s
            while (front < tail) {
                if (s[front] == 'a' || s[front] == 'A' ||
                    s[front] == 'e' || s[front] == 'E' ||
                    s[front] == 'i' || s[front] == 'I' ||
                    s[front] == 'o' || s[front] == 'O' ||
                    s[front] == 'u' || s[front] == 'U') {
                    break;
                }
                front++;
            }
            
            tmp = s[front];
            s[front] = s[tail];
            s[tail] = tmp;
            
            front++;
            tail--;
        }
        
        return s;
    }
};
