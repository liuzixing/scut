import java.util.Scanner;


public class Ural1014_ProductofDigits {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int[] b = new int[10];
		if (n == 0){
			System.out.printf("10\n");
			return;
		}
		if (n == 1)
		{
			System.out.printf("1\n");
			return;
		}
		while (n % 2 == 0)
		{
			n /= 2;
			b[2]++;
		}
		while (n % 3 == 0)
		{
			n /= 3;
			b[3]++;
		}
		while (n % 5 == 0)
		{
			n /= 5;
			b[5]++;
		}
		while (n % 7 == 0)
		{
			n /= 7;
			b[7]++;
		}
		if (n > 1)
			System.out.printf("-1\n");
		else{
			
			b[9] += b[3] / 2;
			b[3] %= 2;
			if (b[3] > 0 && b[2] > 0){
				b[3]--;b[2]--;b[6]++;
			}
			b[8] = b[2] / 3;
			b[2] %= 3;
			b[4] += b[2] / 2;
			b[2] %= 2;
			for (int i = 2;i <= 9;i++)
			{
				while (b[i] > 0){
					System.out.printf("%d", i);
					b[i]--;
				}
			}
			System.out.printf("\n");
		}
	}

}
