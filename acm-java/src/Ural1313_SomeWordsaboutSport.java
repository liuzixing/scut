import java.util.Scanner;

public class Ural1313_SomeWordsaboutSport {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt(),s = 2;
		int[][] a = new int[n + 1][n + 1];
		int[] ans = new int[n * n + 1]; 
		int x = 1,y = 1;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				a[i][j] = cin.nextInt();
		ans[1] = a[1][1];
		while (s <= n * n){
			if (x == 1 && y != n){
				x = y + 1;
				y = 1;
			}
			if (y == n){
				y = x + 1;
				x = n;
			}
			while (true){
				ans[s] = a[x][y];
				s++;
				if (x == 1 || y == n) break;
				x--;
				y++;
			}
		}
		System.out.printf("%d",ans[1]);
		for (int i = 2;i < s;i++)
			System.out.printf(" %d",ans[i]);
		System.out.print("\n");
	}

}
