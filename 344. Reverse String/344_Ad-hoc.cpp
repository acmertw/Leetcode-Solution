/*      Time Complexity : O(n)
                          n : 字元陣列s長度
                          
        Description :
              1. 第一個char和最後一個char交換位置
                 第二個char和最後第二個char交換位置
                 ... ...
              2. 長度為奇數 : 中間那一個char不會交換位置
              
        Note that :
              題目雖然說"ou may assume all the characters consist of printable ascii characters."
              但是測資其中一個是"[]",所以還是要考慮這這個邊界條件
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>::iterator first;
        vector<char>::iterator second;
        char tmp;
        
        if (s.size() == 0)
            return;
        
        first = s.begin();
        second = s.end()-1;
       
        while (first < second) {
            tmp = *first;
            *first = *second;
            *second = tmp;
            
            first++;
            second--;
        }

}
};
