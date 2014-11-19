import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
		
		while(in.hasNext()){
			String s1 = in.next();
			String s2 = in.next();
			
			BigInteger i1 = new BigInteger(s1);
			BigInteger i2 = new BigInteger(s2);
			
			System.out.println(i1.multiply(i2));
		}		
    }
}
