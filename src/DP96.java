/**
 * Created by yuanxu on 17/4/13.
 */
public class DP96 {

    public static int numTrees(int n) {
        int G[] = new int[n+1];
        G[0] = 1;
        G[1] = 1;

        for (int i=2; i<=n; i++) {
            // G[i] = F(1,i) + F(2,i) + ... + F(i,i)
            for (int j=1; j<=i; j++) {
                G[i] += G[j-1] * G[i-j]; // F(j,i) = G[j-1] * G[i-j]
            }
        }
        return G[n];
    }

    /**
     *
     * @test
     */
    public static void main(String args[]) {
        int n = 5;
        System.out.println(numTrees(n));
    }
}
