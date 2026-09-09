class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int el1 = 0;
        int el2 = 1;

        int cnt1 = 0;
        int cnt2 = 0;

        // Phase 1: Find potential candidates

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == el1){
                cnt1++;
            }

            else if(nums[i] == el2){
                cnt2++;
            }

            else if(cnt1 == 0){
                el1 = nums[i];
                cnt1 = 1;
            }

            else if(cnt2 == 0){
                el2 = nums[i];
                cnt2 = 1;
            }

            else{
                cnt1--;
                cnt2--;
            }
        }

        // Phase 2: Count actual frequency

        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == el1)
                count1++;

            else if(nums[i] == el2)
                count2++;
        }

        // Phase 3: Verify

        vector<int> ans;

        if(count1 > nums.size() / 3)
            ans.push_back(el1);

        if(count2 > nums.size() / 3)
            ans.push_back(el2);

        return ans;
    }
};