/*
ID: jyjz2001
LANG: JAVA
TASK: zerosum
*/
import java.io.*;
import java.util.*;

class zerosum {
    public static void main (String [] args) throws IOException {
        // Use BufferedReader rather than RandomAccessFile; it's much faster
        BufferedReader f = new BufferedReader(new FileReader("zerosum.in"));
                                                      // input file name goes above
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("zerosum.out")));
        // Use StringTokenizer vs. readLine/split -- lots faster
        StringTokenizer st = new StringTokenizer(f.readLine());
                              // Get line, break into tokens
        int n = Integer.parseInt(st.nextToken());    // first integer
        char[] str = new char[n + n - 1];
        for(int i = 0, num = 1;i < str.length;i += 2, num++)
            str[i] = (char)('0' + num);

        f(n, 1, 0, '+', 1, out, str);

        out.close();                                  // close the output file
        System.exit(0);                               // don't omit this!
    }

    private static void f(int total, int pos, int pre, char op, int cur, PrintWriter out, char[] str){
        if(pos == total){
            if(getValue(pre, op, cur) == 0)
               out.println(String.valueOf(str));
            return;
        }

        int value = pos + 1;
        str[2 * pos - 1] = ' ';
        f(total, pos + 1,pre, op, 10 * cur + value, out, str);

        str[2 * pos - 1] = '+';
        f(total, pos + 1, getValue(pre, op, cur), '+', value, out, str);

        str[2 * pos - 1] = '-';
        f(total, pos + 1, getValue(pre, op, cur), '-', value, out, str);
    }

    private static int getValue(int pre, char op, int cur){
        if(op == '+')
            return pre + cur;
        if(op == '-')
            return pre - cur;
        return -1;// in fact, it is impossible for the program to reach this line
    }
}
