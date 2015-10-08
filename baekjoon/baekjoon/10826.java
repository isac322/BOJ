import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		try {
			int n = Integer.parseInt(reader.readLine());

			BigInteger p = new BigInteger("1");
			BigInteger pp = new BigInteger("0");
			BigInteger ppp;

			for (int i = 2; i <= n; i++) {
				ppp = p.add(pp);
				pp = p;
				p = ppp;
			}

			if (n == 0) System.out.println("0");
			else System.out.println(p);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}