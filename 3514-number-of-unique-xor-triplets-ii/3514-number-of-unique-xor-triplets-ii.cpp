class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> pairXor(MAXX, false);
        vector<bool> ans(MAXX, false);

        int n = nums.size();

        for (int j = 0; j < n; j++) {
            // Create all pair XORs ending at j
            for (int i = 0; i <= j; i++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }

            // Use every existing pair XOR with nums[j]
            for (int x = 0; x < MAXX; x++) {
                if (pairXor[x]) {
                    ans[x ^ nums[j]] = true;
                }
            }
        }

        int count = 0;
        for (bool x : ans)
            if (x) count++;

        return count;
    }
};
