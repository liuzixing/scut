package µÚ2ÖÜËã·¨;

import java.math.BigInteger;
import java.util.Scanner;

public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		while (t > 0){
			t--;
			BigInteger a = new BigInteger("1");
			int x = cin.nextInt();
			int y = cin.nextInt();
			int tem;
			if (x < y){
				tem = x;
				x = y;
				y = tem;
			}
			for (Integer i = 2;i <=x + y - 1;i++){
				BigInteger b = new BigInteger(i.toString());
				a = a.multiply(b);
			}
			Integer k = x -y;
			BigInteger c = new BigInteger(k.toString());
			a = a.multiply(c);
			for (Integer i = 2;i <=x;i++){
				BigInteger b = new BigInteger(i.toString());
				a = a.divide(b);
			}
			for (Integer i = 2;i <=y;i++){
				BigInteger b = new BigInteger(i.toString());
				a = a.divide(b);
			}
			 System.out.println(a.toString());
		}
	}

}
