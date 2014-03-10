import java.util.Scanner;


public class Ural1044_LuckyTicketsEasy {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt(),ans = 0,m;
		m = n / 2 * 9;
		int[] a = new int[m + 1];
		double tem = n / 2;
		n = (int)Math.pow(10,tem);
		for (int i = 0;i < n;i++){
			tem = i;
			int sum = 0;
			while (tem > 0){
				sum +=tem % 10;
				tem /= 10;
			}
			a[sum]++;
		}
		for (int i = 0;i <= m;i++)
			if (a[i] > 0)
				ans += a[i] * a[i];
		System.out.printf("%d\n", ans);
	}

}
