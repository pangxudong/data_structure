import java.util.Scanner;

/**
 * Created by yuanxu on 17/4/13.
 */
public class DP62 {

    public static int uniquePaths(int m, int n) {
        int res[][] = new int[m+1][n+1];
        if (m<1 || n<1) {
            return 0;
        }

        // init res
        for (int i=1; i<=m; i++) {
            res[i][1] = 1;
        }
        for (int j=1; j<=n; j++) {
            res[1][j] = 1;
        }

        // dp
        for (int i=2; i<=m; i++) {
            for (int j=2; j<=n; j++) {
                res[i][j] += res[i-1][j] + res[i][j-1];
//                System.out.println("i="+i+"j="+j+"res="+res[i][j]);
            }
        }

        return  res[m][n];
    }


    public  static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        System.out.println(uniquePaths(m, n));
    }
}
