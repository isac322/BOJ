import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

class Main {
	public static BigInteger karatsuba(BigInteger x, BigInteger y) {
		int N = Math.max(x.bitLength(), y.bitLength());
		if (N <= 2000) return x.multiply(y);

		N = (N / 2) + (N % 2);

		BigInteger b = x.shiftRight(N);
		BigInteger a = x.subtract(b.shiftLeft(N));
		BigInteger d = y.shiftRight(N);
		BigInteger c = y.subtract(d.shiftLeft(N));

		BigInteger ac = karatsuba(a, c);
		BigInteger bd = karatsuba(b, d);
		BigInteger abcd = karatsuba(a.add(b), c.add(d));

		return ac.add(abcd.subtract(ac).subtract(bd).shiftLeft(N)).add(bd.shiftLeft(2 * N));
	}

	public static void main(String[] args) {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		try {
			BigInteger a = new BigInteger(reader.readLine());
			BigInteger b = new BigInteger(reader.readLine());

			System.out.println(a.add(b));
			System.out.println(a.subtract(b));
			System.out.println(karatsuba(a, b));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}