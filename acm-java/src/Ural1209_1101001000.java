import java.util.Scanner;


public class Ural1209_1101001000 {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int total = 0;
		int[] a = new int[n];
		while (n > 0){
			if (n == 0) return;
			n--;
			long k = cin.nextLong();
			long tem = (k - 1) * 2;
			long tem2 = (long)Math.sqrt((double)tem);
			if (tem2 * (tem2 + 1) == tem)
				a[total] = 1;
			else
				a[total] = 0;
			total++;
		}
		System.out.printf("%d",a[0]);
		for (int i = 1;i < total;i++)
			System.out.printf(" %d",a[i]);
		System.out.printf("\n");
	}
}
