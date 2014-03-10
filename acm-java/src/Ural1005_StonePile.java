
import java.util.*;
public class Ural1005_StonePile {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n,maxn = 1 << 20,sum = 0,ans = 100000000;
		int[] a = new int[21];
		n = cin.nextInt();
		for (int i = 0;i < n;i++)
		{
			a[i] = cin.nextInt();
			sum += a[i];
		}
		for (int i = 1;i < maxn;i++)
		{
			int tem = 0;
			for (int j = 0;j < n;j++)
				if ((i & (1 << j)) != 0)
					tem += a[j];
			if (Math.abs(sum - tem * 2) < ans)
				ans = Math.abs(sum - tem * 2);
		}
		System.out.println(ans);
	}
}
