/*
ID: jyjz2001
LANG: JAVA
TASK: nocows
*/
import java.io.*;
import java.util.*;

class nocows {
    public static void main (String [] args) throws IOException {
        // Use BufferedReader rather than RandomAccessFile; it's much faster
        BufferedReader f = new BufferedReader(new FileReader("nocows.in"));
                                                      // input file name goes above
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("nocows.out")));
        // Use StringTokenizer vs. readLine/split -- lots faster
        StringTokenizer st = new StringTokenizer(f.readLine());
                              // Get line, break into tokens
        int n = Integer.parseInt(st.nextToken());    // first integer
        int k = Integer.parseInt(st.nextToken());

        // System.out.println(n + " " + k);
        out.println(f(n, k - 1, 9901));
        // System.out.println("n: " + n);
        // System.out.println("h: " + heightLowerLimit(n));
        out.close();                                  // close the output file
        System.exit(0);                               // don't omit this!
    }

    private static int heightLowerLimit(int n){
        int curHeight = 0;
        int nodesUpperLimit = 1;
        while(nodesUpperLimit < n){
            nodesUpperLimit = nodesUpperLimit * 2 + 1;
            curHeight++;
        }

        return curHeight;
    }

    private static int specialPlus(int a, int b, int m){
        int s = a + b;
        return (s < m)?s:(s % m);
    }

    private static int f(int n, int k, int m){
        int[][] with = new int[n + 1][k + 1];
        int[][] le = new int[n + 1][k + 1];

        with[1][0] = 1;
        le[1][0] = 1;
        // System.out.println("row: " + 1 + ". " + Arrays.toString(with[1]));
        for(int h = 1;h <= k;h++)
            le[1][h] = le[1][h - 1];
        for(int row = 2;row <= n;row++){
            for(int h = heightLowerLimit(row);h <= Math.min(row - 1, k);h++){
                int sum = row - 1;
                // left child is empty
                // with[row][h] = specialPlus(with[row][h], with[row - 1][h - 1], m);
                // right child is empty
                // with[row][h] = specialPlus(with[row][h], with[row - 1][h - 1], m);
                for(int left = 1;left < sum;left++){
                    int right = sum - left;
                    with[row][h] = specialPlus(with[row][h], with[left][h - 1] * le[right][h - 1], m);
                    with[row][h] = specialPlus(with[row][h], ((h >= 2)?(le[left][h - 2]):0) * with[right][h - 1], m);
                }

                le[row][h] = specialPlus(le[row][h - 1], with[row][h], m);
            }
            for(int h = Math.min(row - 1, k) + 1;h <= k;h++)
                le[row][h] = le[row][h - 1];
            // System.out.println("row: " + row + ". " + Arrays.toString(with[row]));
        }

        // System.out.println();
        // System.out.println();
        // System.out.println();
        /*
        for(int row = 1;row <= n;row++)
            System.out.println("row: " + row + ". " + Arrays.toString(le[row]));
        */
        return with[n][k];
    }
}
