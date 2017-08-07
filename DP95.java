import java.util.ArrayList;
import java.util.List;

/**
 * Created by yuanxu on 17/4/13.
 */
public class DP95 {

    public static List<TreeNode> generateTrees(int n) {
        if (n <= 0) return new ArrayList<>();
        return generateSubtrees(1, n);
    }

    private static List<TreeNode> generateSubtrees(int s, int e) {
        List<TreeNode> res = new ArrayList<TreeNode>();
        if (s > e) { res.add(null); }

        for (int i=s; i<=e; ++i) {
            List<TreeNode> leftTrees = generateSubtrees(s, i-1);
            List<TreeNode> rightTrees = generateSubtrees(i+1, e);

            for (TreeNode left : leftTrees) {
                for (TreeNode right : rightTrees) {
                    TreeNode root = new TreeNode(i);
                    root.left = left;
                    root.right = right;
                    res.add(root);
                }
            }
        }
        return res;
    }

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    /**
     * @test
     */
    public static void main(String args[]) {
        int n = 0;
        System.out.println(generateTrees(n).get(0).val);
    }

}

