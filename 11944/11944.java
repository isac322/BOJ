import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String[] arr = reader.readLine().split(" ");
		String n = arr[0];
		int m = Integer.parseInt(arr[1]);
		int t = Integer.parseInt(arr[0]);
		StringBuilder buffer = new StringBuilder();
		for (int i = 0; i < m && i < t * n.length(); i += n.length()) {
			buffer.append(n);
		}
		if (buffer.length() > m) System.out.println(buffer.subSequence(0, m));
		else System.out.println(buffer);
	}
}