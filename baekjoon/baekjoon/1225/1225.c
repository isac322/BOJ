int main() {
	char in;
	unsigned long long a_sum = 0,tot = 0;
	while ((in = getchar()) != 32)a_sum += in - '0';
	while ((in = getchar()) != '\n')tot += a_sum*(in - '0');
	printf("%llu", tot);
}
