/*      Time Complexity : O(n)
                          n : nums元素個數
                          
        Description :
              1. 將不重複的元素都放在nums前面
                 透過iterator swapIt來紀錄可以放存不同元素的位置
              2. 利用vector.resize()縮小nums大小
              
        Note that :
              1. 需要考慮幾個邊界測資 :
                 []
                 [0,0]
                 [0]
                 [0,1,2,3,4,5,6]
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int target = nums[0];
        vector<int>::iterator curIt = nums.begin()+1;
        vector<int>::iterator endIt = nums.end();
        vector<int>::iterator swapIt = nums.begin()+1;
        
        while (curIt != endIt) {
            if (*curIt != target) {
                *swapIt = *curIt;
                target = *curIt;
                swapIt++;
            }
        
            curIt++;
        }
        
        nums.resize(swapIt - nums.begin());
        return nums.size();
    }
};
