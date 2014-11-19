import java.util.*;
import java.math.BigInteger;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String sx = in.next();
        BigInteger ix = new BigInteger(sx);
        String sy = in.next();
        BigInteger iy = new BigInteger(sy);

        System.out.println(ix.multiply(iy));
    }
}
