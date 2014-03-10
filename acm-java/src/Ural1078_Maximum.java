import java.util.Scanner;

public class Ural1078_Maximum {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n = 100000;
		int[] a = new int[n];
		a[0] = 0;
		a[1] = 1;
		a[2] = 1;
		for (int i = 1;;i++){
			if (i * 2 < n)
				a[i * 2] = a[i];
			else
				break;
			if (i * 2 + 1 < n)
				a[i * 2 + 1] = a[i] + a[i + 1];
		}
		for (int i = 1;i < n;i++)
			if (a[i] < a[i - 1])
				a[i] = a[i - 1];
		while (true){
			int k = cin.nextInt();
			if (k == 0)
				return;
			System.out.printf("%d\n",a[k]);
		}
	}

}
