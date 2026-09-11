class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //ans vector create kiya 
        vector<vector<int>> ans;
        //sorting given vectors
        sort(intervals.begin(), intervals.end());
        //pushing first vector 
        ans.push_back(intervals[0]);
        //iterate through intervals
        for(int i = 1; i < intervals.size(); i++) {
            //check if interval ka 0th pos is <= ans ka 1st pos
            if(intervals[i][0] <= ans.back()[1]) {
                //store the max one
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                //store the new one if the prev one do not overlap
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};