/*
ID: jyjz2001
LANG: JAVA
TASK: preface
*/
import java.io.*;
import java.util.*;

class preface {
    public static void main (String [] args) throws IOException {
        // Use BufferedReader rather than RandomAccessFile; it's much faster
        BufferedReader f = new BufferedReader(new FileReader("preface.in"));
                                                      // input file name goes above
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("preface.out")));
        // Use StringTokenizer vs. readLine/split -- lots faster
        StringTokenizer st = new StringTokenizer(f.readLine());
                              // Get line, break into tokens
        int n = Integer.parseInt(st.nextToken());    // first integer

        int[] cnt = new int[7];
        char[] roman = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};


        for(int i = 1;i <= n;i++)
            process(cnt, i);


        for(int i = 0;i < roman.length;i++){
            if(cnt[i] != 0)
                out.println(roman[i] + " " + cnt[i]);
        }

        out.close();                                  // close the output file
        System.exit(0);                               // don't omit this!
    }

    private static void process(int[] cnt, int value){
        int delta = 0;
        while(value != 0){
            int temp = value % 10;
            calc(cnt, delta, temp);

            delta += 2;
            value /= 10;
        }
    }

    private static void calc(int[] cnt, int delta, int value){
        if(value == 0)
            return;
        if(value <= 3){
            cnt[delta] += value;
        } else if(value == 4){
            cnt[delta]++;
            cnt[delta + 1]++;
        } else if(value == 5){
            cnt[delta + 1]++;
        } else if(value <= 8){
            cnt[delta + 1]++;
            calc(cnt, delta, value - 5);
        } else { /* value == 9 */
            cnt[delta]++;
            cnt[delta + 2]++;
        }
    }
}
