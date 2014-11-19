import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
		BigInteger sum = new BigInteger("0");
		while(true){
			String s = in.next();
			if(s.equals("0"))
				break;
			BigInteger temp = new BigInteger(s);
			sum = sum.add(temp);
		}
		System.out.println(sum);
    }
}
