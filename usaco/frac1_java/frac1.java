/*
ID: jyjz2001
LANG: JAVA
TASK: frac1
*/
import java.io.*;
import java.util.*;

class frac1 {
    public static void main (String [] args) throws IOException {
        // Use BufferedReader rather than RandomAccessFile; it's much faster
        BufferedReader f = new BufferedReader(new FileReader("frac1.in"));
                                                      // input file name goes above
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("frac1.out")));
        // Use StringTokenizer vs. readLine/split -- lots faster
        StringTokenizer st = new StringTokenizer(f.readLine());
                              // Get line, break into tokens
        int N = Integer.parseInt(st.nextToken());    // first integer
        ArrayList<Integer> num = new ArrayList<Integer> ();
        ArrayList<Integer> den = new ArrayList<Integer> ();

        for(int d = 2;d <= N;d++){
            for(int n = 1;n < d;n++){
                int GCD = gcd(d, n);
                if(GCD == 1){
                    num.add(n);
                    den.add(d);
                }
            }
        }

        num.add(0);
        den.add(1);
        num.add(1);
        den.add(1);

        int[] numArray = new int[num.size()];
        int[] denArray = new int[den.size()];

        for(int pig = 0;pig < num.size();pig++){
            numArray[pig] = num.get(pig);
            denArray[pig] = den.get(pig);
        }

        // System.out.println(numArray.length);
        mergeSort(numArray, denArray, 0, numArray.length - 1);

        for(int i = 0;i < numArray.length;i++)
            out.println("" + numArray[i] + "/" + denArray[i]);

        out.close();                                  // close the output file
        System.exit(0);                               // don't omit this!
    }

    public static int gcd(int a, int b){
        if(a == 0)
            return b;
        else
            return gcd(b % a, a);
    }


    public static void mergeSort(int[] num, int[] den, int low, int high){
        // System.out.println("low is:" + low + ", high is:" + high);
        if(low == high)
            return;
        int mid = (low + high) / 2;

        mergeSort(num, den, low, mid);
        mergeSort(num, den, mid + 1, high);

        int[] tempNum1 = new int[mid - low + 1 + 1];
        int[] tempDen1 = new int[mid - low + 1 + 1];

        int[] tempNum2 = new int[high - (mid + 1) + 1 + 1];
        int[] tempDen2 = new int[high - (mid + 1) + 1 + 1];

        // part1
        for(int i = low;i <= mid;i++){
            tempNum1[i - low] = num[i];
            tempDen1[i - low] = den[i];
        }
        // add "infinity"
        tempNum1[mid + 1 - low] = 10000;
        tempDen1[mid + 1 - low] = 1;

        // part2
        for(int i = mid + 1;i <= high;i++){
            tempNum2[i - (mid + 1)] = num[i];
            tempDen2[i - (mid + 1)] = den[i];
        }
        // add "infinity"
        tempNum2[high - mid] = 10000;
        tempDen2[high - mid] = 1;

        int p1 = 0;
        int p2 = 0;
        for(int i = low;i <= high;i++){
            if(tempNum1[p1] * tempDen2[p2] <= tempNum2[p2] * tempDen1[p1] ){
                num[i] = tempNum1[p1];
                den[i] = tempDen1[p1];
                p1++;
            } else {
                num[i] = tempNum2[p2];
                den[i] = tempDen2[p2];
                p2++;
            }
        }
    }

}
