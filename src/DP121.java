import java.util.Scanner;

/**
 * Created by yuanxu on 17/4/12.
 */
public class DP121 {

    public static int maxProfit(int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        int max = 0;
        int curMin = prices[0];
        for (int i=1; i<prices.length; i++) {
            if (prices[i] > curMin) {
                max = (prices[i] - curMin) > max ? (prices[i] - curMin) : max;
            } else {
                curMin = prices[i];
            }
        }
        return max;
    }


    public  static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        String inputString = scanner.nextLine();
        String stringArray[] = inputString.substring(1,inputString.length()-1).split(", ");
        int prices[] = new int[stringArray.length];
        for(int i=0; i<stringArray.length; i++) {
            prices[i] = Integer.parseInt(stringArray[i]);
        }
        System.out.println(maxProfit(prices));
    }



}
