class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m < 3 || n < 3) return 0;

        priority_queue<pair<int, pair<int,int>>,
                       vector<pair<int, pair<int,int>>>,
                       greater<pair<int, pair<int,int>>>> pq;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            vis[i][0] = vis[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m - 1][j], {m - 1, j}});
            vis[0][j] = vis[m - 1][j] = true;
        }

        int ans = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int h = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny])
                    continue;

                vis[nx][ny] = true;

                ans += max(0, h - heightMap[nx][ny]);

                pq.push({max(h, heightMap[nx][ny]), {nx, ny}});
            }
        }

        return ans;
    }
};