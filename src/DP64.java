/**
 * Created by yuanxu on 17/4/13.
 */
public class DP64 {

    public static int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int res[][] = new int[m][n];

        // boundary conditions
        res[0][0] = grid[0][0];
        for (int i=1; i<m; i++) {
            res[i][0] = grid[i][0] + res[i-1][0];
        }
        for (int j=1; j<n; j++) {
            res[0][j] = grid[0][j] + res[0][j-1];
        }

        // dp
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                res[i][j] = grid[i][j] + (res[i-1][j] < res[i][j-1] ? res[i-1][j] : res[i][j-1]);
            }
        }

        return res[m-1][n-1];
    }

    public  static void main(String[] args) {
        int grid[][] = {{1,2},{1,1}};
        System.out.println(minPathSum(grid));
    }
}
