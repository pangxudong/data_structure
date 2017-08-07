/**
 * Created by yuanxu on 17/4/13.
 */
public class DP91 {

    public static int numDecodings(String s) {
        int len = s.length();
        if (len == 0) return 0;
        if (s.charAt(0) == '0')  return 0;

        // for both s.char(i) and res[i], make i begins with 1
        s = '0' + s;
        int res[] = new int[len+1];

        res[0] = 1; // for convince
        res[1] = 1;

        for (int i=2; i<=len; i++) {
            if (s.charAt(i) == '0') {
                if (s.charAt(i-1) =='1' || s.charAt(i-1) =='2') {
                    res[i] = res[i-2];
                } else {
                    return 0;
                }
            } else {
                res[i] = res[i-1];
                if (s.charAt(i-1) == '1'|| (s.charAt(i-1)=='2' && s.charAt(i) < '7')) {
                    res[i] += res[i-2];
                }
            }
        }
        return res[len];
    }

    /**
     *
     * @test
     */
    public  static void main(String[] args) {
//        String s = "12312";
//        String s = "0";
//        String s = "01";
//        String s = "10";
        String s = "110";
        System.out.println(numDecodings(s));
    }
}
