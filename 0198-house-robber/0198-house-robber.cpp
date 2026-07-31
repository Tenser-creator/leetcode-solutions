class Solution {
public:
    //Method-1 : Top-Down Approach(Recursion + Memoization)

    //Time Complexity = O(n)
    //Space Complexity = O(n)
    
    int dp[101] ; //memoization dp array

    int solve(vector<int>& nums, int i, int n){
        //1.) Handle base case
        if(i >= n) return 0 ;

        //2.) check memoization array
        if(dp[i] != -1){
            return dp[i] ;
        }

        //3.) we have two choices
        int rob = nums[i] + solve(nums, i+2, n) ;

        int dont = solve(nums, i+1, n) ;

        //return the max. ans
        return dp[i] = max({rob , dont}) ;
    }
    int rob(vector<int>& nums) {

        int n = nums.size() ;

        memset(dp, -1, sizeof(dp)) ;//fill memoization array with -1

        return solve(nums, 0, n) ;
    }
};