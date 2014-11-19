import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int i = 0;i < n;i++){
            int l = in.nextInt();
            int[] a = new int[l];
            for(int j = 0;j < l;j++)
                a[j] = in.nextInt();
            System.out.println("Optimal train swapping takes " + f(a) + " swaps.");
        }
    }
	
    private static int f(int[] a){
        int cnt = 0;
		for(int i = 0;i < a.length;i++){
			for(int j = i + 1;j < a.length;j++){
				if(a[i] > a[j])
					cnt++;
			}
		}
        return cnt;
    }
}
