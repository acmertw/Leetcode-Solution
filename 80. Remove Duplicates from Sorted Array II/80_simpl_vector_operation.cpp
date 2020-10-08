/*      Time Complexity : O(n)
                          n : nums元素個數
                          
        Description : 
              1. 將不重複超過兩次的元素都放在nums前面
                 透過count來計算不同元素出現過幾次
                 透過iterator swapIt來紀錄可以放存不同元素的位置
              2. 利用vector.resize()縮小nums大小

        Note that :
              1. 需要考慮幾個邊界測資 :
                 []
                 [0,0,1]
                 [0]
                 [0,0]
                 [0,1,2,3,4,5,6,6,6]
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int target = nums[0];
        int count = 1;
        vector<int>::iterator curIt = nums.begin()+1;
        vector<int>::iterator endIt = nums.end();
        vector<int>::iterator swapIt = nums.begin()+1;
        
        while(curIt != endIt) {
            if (*curIt == target && count<2) {
                *swapIt = *curIt;
                swapIt++;
                count++;
            } else if(*curIt != target) {
                *swapIt = *curIt;
                target = *curIt;
                swapIt++;
                count = 1;
            }
            
            curIt++;
        }
        
        nums.resize(swapIt - nums.begin());
        return nums.size();
    }
};
