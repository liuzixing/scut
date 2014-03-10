import java.util.Scanner;


public class Ural1068_Sum {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int sum = 0;
		if (n > 0)
		{
			sum = n * (n + 1) / 2;
		}
		else
		{
			n = -n;
			sum = -(n + 1) * n / 2;
			sum++;
		}
		System.out.printf("%d\n",sum);
	}

}
