import java.util.Scanner;


public class Ural1149_SinusDances {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		String s = "+-";
		for (int i = 1;i < n;i++)
			System.out.printf("(");
		int j = 0;
		for (int i = n;i > 1;i--){
			j++;
			for (int k = 1;k < j;k++)
				System.out.printf("sin(%d%c",k,s.charAt(k % 2));
			System.out.printf("sin(%d)",j);
			for (int k = 1;k < j;k++)
				System.out.printf(")");
			System.out.printf("+%d)",i);
		}
		for (int k = 1;k < n;k++)
			System.out.printf("sin(%d%c",k,s.charAt(k % 2));
		System.out.printf("sin(%d)",n);
		for (int k = 1;k < n;k++)
			System.out.printf(")");
		System.out.printf("+1\n");
	}

}
