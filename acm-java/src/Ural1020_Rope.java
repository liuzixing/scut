import java.util.Scanner;


public class Ural1020_Rope {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int N = cin.nextInt();
		double r = cin.nextDouble();
		double[] x = new double[105];
		double[] y = new double[105];
		double ans;
		ans= r * 2 * Math.PI;
		for (int i = 0;i < N;i++){
			x[i] = cin.nextDouble();
			y[i] = cin.nextDouble();
			if (i > 0)
				ans += Math.sqrt(Math.pow(x[i] - x[i - 1],2.0) + Math.pow(y[i] - y[i - 1],2.0));
		}
		ans += Math.sqrt(Math.pow(x[0] - x[N - 1],2.0) + Math.pow(y[0] - y[N - 1],2.0));
		System.out.printf("%.2f\n", ans);
	}

}
