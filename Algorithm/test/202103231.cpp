void reciprocal(int N) {
	map<int, int> log;
	string result = "0.";
	int remainder = 1 % N * 10;
	int lenDecimalCycle = 0, decimalPos = 0;

	while (remainder != 0) {
		log[remainder] = decimalPos++;
		result += to_string(remainder / N);
		remainder = remainder % N * 10;

		if (log.find(remainder) != log.end()) {
			lenDecimalCycle = decimalPos - log[remainder];
			break;
		}
	}
	if (lenDecimalCycle == 0)
		cout << result << remainder / N << " " << remainder / N;
	else
		cout << result << " " << result.substr(result.size() - lenDecimalCycle, lenDecimalCycle);
}