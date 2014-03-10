import java.util.Scanner;
public class Ural1319_Hotel {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt(),s = 2;
		int[][] a = new int[n + 1][n + 1];
		int x = 1,y = n;
		a[1][n] = 1;
		while (s <= n * n){
			if (y == n && x != n){
				y = n - x;
				x = 1;
			}
			if (x == n){
				x = n - y + 2;
				y = 1;
			}
			while (true){
				a[x][y] = s;
				s++;
				if (y == n || x == n) break;
				x++;
				y++;
			}
			
		}
		for (int i = 1;i <= n;i++){
			System.out.printf("%d",a[i][1]);
			for (int j = 2;j <= n;j++)
				System.out.printf(" %d",a[i][j]);
			System.out.printf("\n");
		}
	}

}
