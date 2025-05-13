class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size(), l = rows * cols;
        int m = 0, n = 0;
        int target = 0;
        int up = 0, down = 0, left = 0, right = 0;
        while (target <= l) {
            m = target / cols;
            n = target % cols;
            if (m == 0 && n == 0 && m != rows - 1 && n != cols - 1) {
                up = -1, down = m + 1, left = -1, right = n + 1;
                if (mat[m][n] > mat[down][n] && mat[m][n] > mat[m][right]) {
                    return {m, n};
                }
            } else if (m == 0 && n != 0 && m != rows - 1 && n != cols - 1) {
                up = -1, down = m + 1, left = n - 1, right = n + 1;
                if (mat[m][n] > mat[down][n] && mat[m][n] > mat[m][left] && mat[m][n] > mat[m][right]) {
                    return {m, n};
                }
            } else if (m == 0 && n != 0 && m != rows - 1 && n == cols - 1) {
                up = -1, down = m + 1, left = n - 1, right = -1;
                if (mat[m][n] > mat[down][n] && mat[m][n] > mat[m][left]) {
                    return {m, n};
                }
            } else if (m != 0 && n == 0 && m != rows - 1 && n != cols -1) {
                up = m  - 1, down = m + 1, left = -1, right = n + 1;
                if (mat[m][n] > mat[up][n] && mat[m][n] > mat[down][n] && mat[m][n] > mat[m][right]) {
                    return {m, n};
                }
            } else if (m != 0 && n != 0 && m != rows - 1 && n != cols - 1) {
                up = m  - 1, down = m + 1, left = n - 1, right = n + 1;
                if (mat[m][n] > mat[up][n] && mat[m][n] > mat[down][n] && mat[m][n] > mat[m][left] && mat[m][n] > mat[m][right]) {
                    return {m, n};
                }
            } else if (m != 0 && n != 0 && m != rows - 1 && n == cols - 1) {
                up = m  - 1, down = m + 1, left = n - 1, right = -1;
                if (mat[m][n] > mat[up][n] && mat[m][n] > mat[down][n] && mat[m][n] > mat[m][left]) {
                    return {m, n};
                }
            } else if (m != 0 && n != cols - 1 && m == rows - 1 && n == 0) {
                up = m  - 1, down = -1, left = -1, right = n + 1;
                if (mat[m][n] > mat[up][n] && mat[m][n] > mat[m][right]) {
                    return {m, n};
                }
            } else if (m != 0 && n != 0 && m == rows - 1 && n != cols - 1) {
                up = m  - 1, down = -1, left = n - 1, right = n + 1;
                if (mat[m][n] > mat[up][n] && mat[m][n] > mat[m][left] && mat[m][n] > mat[m][right]) {
                    return {m, n};
                }
            } else if (m != 0 && n != 0 && m == rows - 1 && n == cols - 1) {
                up = m - 1, down = -1, left = n - 1, right = -1;
                if (mat[m][n] > mat[up][n] && mat[m][n] > mat[m][left]) {
                    return {m, n};
                }
            }


            else if(m == 0 && n == 0 && m == rows - 1 && n != cols - 1){
               up = -1, down = -1, left = -1, right = n + 1;
                if (mat[m][n] > mat[m][right]) {
                    return {m, n};
                }
            }
            else if(m == 0 && n != 0 && m == rows - 1 && n != cols - 1){
               up = -1, down = -1, left = n - 1, right = n + 1;
                if (mat[m][n] > mat[m][left] && mat[m][n] > mat[m][right]) {
                    return {m, n};
                }
            }
            else if(m == 0 && n != 0 && m == rows - 1 && n == cols - 1){
               up = -1, down = -1, left = n - 1, right = -1;
                if (mat[m][n] > mat[m][left]) {
                    return {m, n};
                }
            }
            else if(m == 0 && n == 0 && m != rows - 1 && n == cols - 1){
               up = -1, down = m + 1, left = -1, right = -1;
                if (mat[m][n] > mat[down][n]) {
                    return {m, n};
                }
            }
            else if(m != 0 && n == 0 && m != rows - 1 && n == cols - 1){
               up = m - 1, down = m + 1, left = -1, right = -1;
                if (mat[m][n] > mat[up][n] && mat[m][n] > mat[down][n]) {
                    return {m, n};
                }
            }
            else if(m != 0 && n == 0 && m == rows - 1 && n == cols - 1){
               up = m - 1, down = -1, left = -1, right = -1;
                if (mat[m][n] > mat[up][n]) {
                    return {m, n};
                }
            }
            else{
                up = -1, down = -1, left = -1, right = -1;
                return {m, n};
            }
            target++;
        }
        return {m, n};
    }
};
