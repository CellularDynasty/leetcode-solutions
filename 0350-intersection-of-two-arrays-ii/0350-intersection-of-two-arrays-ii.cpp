class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;

        for (int x : nums1) {
            mp[x]++;
        }

        vector<int> result;

        for (int x : nums2) {

            if (mp[x] > 0) {
                result.push_back(x);
                mp[x]--;
            }
        }

        return result;
    }
};