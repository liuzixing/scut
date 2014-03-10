import java.util.Scanner;


public class Ural1086_Cryptography {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		boolean[] a = new boolean[163842];
		int[] b = new int[15001];
		int n = 1;
		a[1] = true;
		a[2] = false;
		for (int i = 2;i < Math.sqrt(163842);i++)
			if (a[i] == false)
				for (int j = i + i;j < 163842;j += i)
					a[j] = true;
		for (int i = 2;i < 163842;i++)
			if (a[i] == false){
				b[n] = i;
				n++;
			}
		int k = cin.nextInt();
		while(k > 0){
			if (k == 0) break;
			k--;
			n = cin.nextInt();
			System.out.println(b[n]);
		}
	}
}
