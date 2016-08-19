import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		try {
			for (int i = 0; i < 3; i++) {
				int n = Integer.parseInt(reader.readLine());
				BigInteger sum = new BigInteger("0");
				for (int j = 0; j < n; j++) sum = sum.add(new BigInteger(reader.readLine()));
				if (sum.signum() < 0) System.out.println("-");
				else if (sum.signum() == 0) System.out.println("0");
				else System.out.println("+");
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}