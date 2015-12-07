import java.util.Scanner;


class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int t = s.nextInt();
		for (int i = 0; i < t; i++) {
			battle((i + 1));
		}
	}

	static void battle(int n) {
		long scoregood = 0;
		long scorebad = 0;
		for (int i = 0; i < 6; i++) {
			switch (i) {
				case 0:
					scoregood += s.nextLong();
					break;
				case 1:
					scoregood += s.nextLong() * 2;
					break;
				case 2:
				case 3:
					scoregood += s.nextLong() * 3;
					break;
				case 4:
					scoregood += s.nextLong() * 4;
					break;
				case 5:
					scoregood += s.nextLong() * 10;
					break;
			}
		}
		for (int i = 0; i < 7; i++) {
			switch (i) {
				case 0:
					scorebad += s.nextLong();
					break;
				case 1:
				case 2:
				case 3:
					scorebad += s.nextLong() * 2;
					break;
				case 4:
					scorebad += s.nextLong() * 3;
					break;
				case 5:
					scorebad += s.nextLong() * 5;
					break;
				case 6:
					scorebad += s.nextLong() * 10;
					break;
			}
		}
		System.out.print("Battle " + n + ": ");
		if (scoregood > scorebad) System.out.println("Good triumphs over Evil");
		else if (scoregood < scorebad) System.out.println("Evil eradicates all trace of Good");
		else System.out.println("No victor on this battle field");
	}
}