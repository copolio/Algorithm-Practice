#include <string>
#include <vector>
#include <set>

using namespace std;

int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int solution(vector<string> holidays, int k) {
	int answer = -1;
	int consecutiveDays = 0;
	bool isholiday[365] = { false, };
	set<int> freedays;
	int weekday = 4; // 0 = ¿ù¿äÀÏ, ...
	for (int i = 0; i < 365; i++) {
		if (weekday > 4) isholiday[i] = true;
		weekday++;
		if (weekday > 6) weekday = 0;
	}
	for (int i = 0; i < holidays.size(); i++) {
		int month = stoi(holidays[i].substr(0, 2)) - 1;
		int day = stoi(holidays[i].substr(3, 2)) - 1;
		for (int j = 0; j < month; j++) {
			day += days[j];
		}
		isholiday[day] = true;
	}

	for (int i = 0; i < 365; i++) {
		if (isholiday[i]) {
			consecutiveDays++;
		}
		else {
			if (consecutiveDays == 0) continue;
			freedays.insert(consecutiveDays);
			consecutiveDays = 0;
		}
	}
	vector<int> vFreedays(freedays.begin(), freedays.end());
	answer = vFreedays[vFreedays.size() - k];
	return answer;
}