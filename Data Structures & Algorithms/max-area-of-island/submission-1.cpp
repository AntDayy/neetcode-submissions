class Solution {
private:
    // Hướng đi: Trái, Lên, Xuống, Phải
    const int d1[4] = {0, -1, 1, 0};
    const int d2[4] = {-1, 0, 0, 1};

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Nếu gặp đất liền, kích hoạt DFS để tính diện tích hòn đảo đó
                if (grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        // 1. Kiểm tra điều kiện biên và ô nước ngay tại đầu hàm
        if (i < 0 || j < 0 || i >= (int)grid.size() || j >= (int)grid[i].size() || grid[i][j] == 0) {
            return 0;
        }

        // 2. Đánh dấu ô hiện tại đã duyệt (biến thành nước để tránh duyệt lại)
        grid[i][j] = 0;
        int area = 1; // Bản thân ô hiện tại có diện tích là 1

        // 3. Loang ra 4 hướng xung quanh và cộng dồn diện tích vào
        for (int k = 0; k < 4; k++) {
            area += dfs(grid, i + d1[k], j + d2[k]);
        }

        return area;
    }
};