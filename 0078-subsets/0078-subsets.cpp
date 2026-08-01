class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int index, vector<int>& subset) {
        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[index]);
        solve(nums, index + 1, subset);

        // Exclude current element
        subset.pop_back();
        solve(nums, index + 1, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        solve(nums, 0, subset);
        return ans;
    }
};