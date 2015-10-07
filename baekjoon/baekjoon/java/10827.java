import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.StringTokenizer;

class Main {
	public static void main(String[] args) {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		try {
			StringTokenizer tok = new StringTokenizer(reader.readLine(), " ");

			BigDecimal a = new BigDecimal(tok.nextToken());
			System.out.println(a.pow(Integer.parseInt(tok.nextToken())).toPlainString());

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}