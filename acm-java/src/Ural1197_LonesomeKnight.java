import java.util.Scanner;


public class Ural1197_LonesomeKnight {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int dx[] = {-2,-2,-1,1,2,2,1,-1};
		int dy[] = {-1,1,2,2,1,-1,-2,-2};;
		int ans;
		while (n > 0){
			if(n == 0) return;
			n--;
			ans = 0;
			String s = cin.next();
			for (int k = 0;k < 8;k++){
				if (s.charAt(0) + dx[k] <= 'h' && s.charAt(1) + dy[k] <= '8' && s.charAt(0) + dx[k] >= 'a' && s.charAt(1) + dy[k] >= '1')
					ans++;
			}
			System.out.println(ans);
		}
		
	}

}
