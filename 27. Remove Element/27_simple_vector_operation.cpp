/*      Time Comlexity : O(n)
                         n : nums元素個數
        
        Description :
              1. 將要保留元素都集中在num前面
                 將要移除元素都集中在nums後面
              2. 利用iterator front由nums前面開始尋找val
                 利用iterator rear由nums後面開始尋找不是val
              3. 每一個loop會看front是不是找到val,以及rear是不是找到不是val
                 這樣都找到後就會講元素交換位置,將val元素都集中在後面
              4. 最後面利用vector.resize()將nums減少size
              
        Note that :
              1. 需要考慮到邊界測資
                 []
                 0
                 
                 [0,0,0,0,0,0]
                 0
              2. while (front < rear)  --> 不能寫成 while (front != rear)
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 考量到nums為空
        if (nums.size() == 0)
            return 0;
        
        vector<int>::iterator front = nums.begin();
        vector<int>::iterator rear = nums.end()-1;
        
        // 需要注意到不能寫成front != rear, 不然有可能無窮迴圈
        while (front < rear) {
                if (*front == val && *rear != val) {
                    int t = *front;
                    *front = *rear;
                    *rear = t;
                    
                    front++;
                    rear--;
                } else {
                    if (*front != val) // 如果front還沒找到元素為val,則會向後找
                        front++;
                    if (*rear == val)  // 如果rear還沒找到元素不是val,則會向前找
                        rear--;
                }
        }
        
        /*      最後確定最中間那個元素到底是不是val
                如果是則不考慮進去,如果不是則考慮進去
         */
        if (*front == val) {
            nums.resize(front - nums.begin());
            return front - nums.begin();
        } else {
            nums.resize(front - nums.begin()+1);
            return front - nums.begin()+1;
        }
    }
};
