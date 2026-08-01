class Solution {
public:
    vector<string> ans;

    void solve(string &digits, int index, string &path, vector<string> &mp) {
        if (index == digits.size()) {
            ans.push_back(path);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            path.push_back(ch);
            solve(digits, index + 1, path, mp);
            path.pop_back(); // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string path = "";
        solve(digits, 0, path, mp);

        return ans;
    }
};