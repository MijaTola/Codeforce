import java.util.Scanner;
import java.math.BigInteger;

public class P1033B {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        for (int k = 0; k < t; ++k) {
            long a,b;
            a = in.nextLong();
            b = in.nextLong();
            
            long area = (a * a) - (b * b);
            String area2 = a + "";
            BigInteger da = new BigInteger(area2);
            area2 = b + "";
            BigInteger db = new BigInteger(area2);
            da = da.multiply(da);
            db = db.multiply(db);

            da = da.subtract(db);

            Boolean x = da.isProbablePrime(100);
            if(x)System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
