import java.util.Scanner;

public class Hdu2001_计算两点间的距离{
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextDouble()){
			double x1 = cin.nextDouble();
			double y1 = cin.nextDouble();
			double x2 = cin.nextDouble();
			double y2 = cin.nextDouble();
			System.out.printf("%.2f\n",Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
			System.out.printf("\n");
		}
	}

}
