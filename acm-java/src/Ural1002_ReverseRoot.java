
import java.util.Scanner;
public class Ural1002_ReverseRoot {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n;
		long []a = new long[1000005];
		for (n = 0;cin.hasNextLong();n++)
			a[n] = cin.nextLong();
		for (int i = n - 1;i >= 0;i--)
			System.out.printf("%.4f\n",Math.sqrt((double)a[i]));
	}
}
