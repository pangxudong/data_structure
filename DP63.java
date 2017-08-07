import java.util.Scanner;

/**
 * Created by yuanxu on 17/4/13.
 */
public class DP63 {

    public static int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int res[][] = new int[m][n];// 数据从0开始

        // boundary condition
        res[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i=1; i<m; i++) {
            if (res[i-1][0] == 0) {
                res[i][0] = 0;
            } else if (obstacleGrid[i][0] == 1) {
                res[i][0] = 0;
            } else {
                res[i][0] = 1;
            }
        }
        for (int j=1; j<n; j++) {
            if (res[0][j-1] == 0) {
                res[0][j-1] = 0;
            } else if (obstacleGrid[0][j] == 1) {
                res[0][j] = 0;
            } else {
                res[0][j] = 1;
            }
        }

        // DP
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    res[i][j] = 0;
                } else {
                    res[i][j] = res[i-1][j] + res[i][j-1];
                }
            }
        }

        return  res[m-1][n-1];
    }


    public  static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
//        int obstacleGrid[][] = {{0,0,0},{0,1,0},{0,0,0}};
//        int obstacleGrid[][] = {{1}};
        int obstacleGrid[][] = {{0,0},{0,1}};
        System.out.println(uniquePathsWithObstacles(obstacleGrid));
    }
}
