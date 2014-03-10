package µ⁄2÷‹À„∑®;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Nim {
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner cin = new Scanner(System.in);
		int[] b = new  int[32];
		while (cin.hasNext()){
			int n = cin.nextInt();
			int a;
			for (int i = 0;i < 32;i++)
				b[i] = 0;
			while (n>0){
				n--;
				a = cin.nextInt();
				for (int i = 0;i < 32;i++){
					if ((a & (1 << i)) > 0)
						b[i]++;
				}
				
			}
			boolean f = false;
			for (int i = 0;i < 32;i++)
				if (b[i] % 2 == 1){
					f = true;
					break;
				}
			
			if (f == false)
				System.out.println("qian");
			else
				System.out.println("xing");
				
		}
	}

}
