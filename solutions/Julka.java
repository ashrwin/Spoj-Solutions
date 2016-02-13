import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 * Created by Ashwin on 11-02-2015.
 */
public class Main {
	public static void main(String []args)
	{
		BufferedReader br=new BufferedReader(new InputStreamReader((System.in)));
		String x,y;
		try {
			while(  (x=br.readLine() )!=null && ( y=br.readLine() ) !=null )
			{
				BigInteger a=new BigInteger(x);
				BigInteger b=new BigInteger(y);
				BigInteger n= a.subtract((b)).divide(BigInteger.valueOf(2));
				BigInteger k= n.add(b);
				System.out.println(k);
				System.out.println(n);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
