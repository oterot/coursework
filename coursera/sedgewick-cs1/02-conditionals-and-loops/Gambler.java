/* Monte Carlo simulation of Gambler's ruin
   https://en.wikipedia.org/wiki/Gambler%27s_ruin
 */

public class Gambler {
    public static void main(String[] args) {
        int stake = Integer.parseInt(args[0]);
        int goal = Integer.parseInt(args[1]);
        int trials = Integer.parseInt(args[2]);

        int wins = 0;
        for (int t = 0; t < trials; t++) {
            int cash = stake;
            while (cash > 0 && cash < goal) {
                if (Math.random() < 0.5) cash++;
                else cash--;
            }
            if (cash == goal) wins++;
        }
        double pct = wins / (double) trials * 100.0;
        pct = Math.round(pct * 100) / 100.0;
        System.out.println(wins + " wins of " + trials + " trials. "
                +  pct + "%");

    }
}
