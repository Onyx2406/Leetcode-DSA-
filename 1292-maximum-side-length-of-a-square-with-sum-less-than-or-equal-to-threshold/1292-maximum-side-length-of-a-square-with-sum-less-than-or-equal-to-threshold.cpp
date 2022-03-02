class Solution {
public:
    bool isValid(vector<vector<int>> &sum, int k, int mid) {
        int r = sum.size(); int c = sum[0].size();


        // scanning through all the sqaures whose side is equal to mid
        for (int i = mid - 1; i < r; i++) {
            for (int j = mid - 1; j < c; j++) {

                int curSum = sum[i][j] - (i >= mid ? sum[i - mid][j] : 0) - (j >= mid ? sum[i][j - mid] : 0) +
                             (i >= mid && j >= mid ? sum[i - mid][j - mid] : 0);
                if (curSum <= k) return true;
            }

        }

        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int k) {
        if (mat.empty()) return 0;

        int r = mat.size();
        int c = mat[0].size();
        int ans = 0;

        /*
            sum[i][j] represents the sum of rectangle whose bottom right corner is at (i, j)

        */
        vector<vector<int>> sum(r, vector<int> (c, 0));
        sum = mat;
        for (int i = 1; i < r; i++) sum[i][0] = sum[i - 1][0] + mat[i][0];
        for (int j = 1; j < c; j++) sum[0][j] = sum[0][j - 1] + mat[0][j];

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
            }
        }

        // using binary search, we check if there exists a square, with side length mid, whose sum is less than or equal to k


        int low = 1, high = min(r, c);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(sum, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }

        return ans;

    }
};