class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;

        for (auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        int ans = (n - mp.size()) * 2;

        for (auto &[row, seats] : mp) {
            bool left = true, middle = true, right = true;

            for (int i = 2; i <= 5; i++)
                if (seats.count(i)) left = false;

            for (int i = 4; i <= 7; i++)
                if (seats.count(i)) middle = false;

            for (int i = 6; i <= 9; i++)
                if (seats.count(i)) right = false;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};