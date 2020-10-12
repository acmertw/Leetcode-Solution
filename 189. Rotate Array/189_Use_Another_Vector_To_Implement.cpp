/*      Time Complexity : O(n)
                          n : nums元素個數
                          
        Description : 
              1. 只考慮做k的餘數情況,當k == 0,則表示都不移動位置,因此直接return
              2. 使用另一個vector存放rotate後的元素
              3. 做完後再將結果給nums,因為nums用參考(&)
              
        Note that : 
              1. vector在宣告時如果沒有指定capacity大小,則capacity為0
                 這樣就不能將元素放進去
                 因此透過
                     vector<int> rotatedNums(elementNum, 0);
                 將rotatedNums宣告成capacity為elementNums,且所有元素都為0
              2. 透過vector2.assign(vector1.begin(), vector1.end())
                 將vector1複製到vector2
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if (k == 0)
            return;
        
        int elementNum = nums.size();
        vector<int> rotatedNums(elementNum, 0);
        int i, j;
        
        for (i = 0; i< elementNum; i++) {
            j = (i+k)%elementNum;
            rotatedNums[j] = nums[i];
        }
        
        nums.assign(rotatedNums.begin(), rotatedNums.end());
    }
};
