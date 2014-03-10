import java.util.Scanner;
import java.util.Arrays;

public class Ural1025_DemocracyInDanger {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt(),ans = 0;
		int[] a = new int[n];
		for (int i = 0;i < n;i++){
			a[i] = cin.nextInt();
			a[i] = a[i] / 2 + 1;
		}
		Arrays.sort(a);
		for (int i = 0;i <= n / 2;i++){
			ans += a[i];
		}
		System.out.printf("%d\n",ans);
	}

}
