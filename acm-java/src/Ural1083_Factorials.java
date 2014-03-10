import java.util.Scanner;

public class Ural1083_Factorials {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt(),k = 0,ans = 1;
		String s = cin.next();
		k = s.length();
		for (int i = n;i > 0;i -= k)
			ans *= i;
		System.out.println(ans);
	}
}
