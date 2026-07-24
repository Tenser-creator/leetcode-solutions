class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int i = q.front();
                q.pop();

                if (i == n - 1)
                    return steps;

                // Left
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                // Right
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                // Same value
                for (int idx : mp[arr[i]]) {
                    if (!visited[idx]) {
                        visited[idx] = true;
                        q.push(idx);
                    }
                }

                // Prevent revisiting same-value indices
                mp[arr[i]].clear();
            }

            steps++;
        }

        return -1;
    }
};