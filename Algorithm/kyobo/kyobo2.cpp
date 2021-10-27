#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vNumBetween;
	//�Է¿� ���
	int r1 = 1000;
	int r2 = 10000;
	int n = 0;
	int order = 250; 

	//�Է¹����� �ּ�����
	//cin >> r1 >> r2 >> n >> order;

	//������ ���� r1���� r2���� ��� ���ڸ� Ȯ��
	for (int i = r1; i <= r2; i++) {
		int num = i;
		//i��° ���ڸ� 10���� ���� �������� �ڸ����� �ȴ�. 
		//���ڸ� 10���� ���� ���� 0�� �ɶ�����(=��� �ڸ����� Ȯ���� ������) �ݺ��Ѵ�.
		//�ڸ����� n�� ������ n�� ���Ե� ���� �����ϴ� vNumBetween �迭�� �����Ѵ�.
		while (num != 0) {
			int digit = num % 10;
			num /= 10;
			if (digit == n) {
				vNumBetween.push_back(i);
				continue;
			}
		}
	}
	cout << "Count : " << vNumBetween.size() << endl;
	cout << order << "��° " << n << "�� ������ ���� : ";
	//order�� vNumBetween�迭�� ũ�⺸�� ũ�ٸ� order��° n���� �������� -1�� ����ϰ�, �׷��� ���� ��� ���� ����Ѵ�.
	if (vNumBetween.size() < order) {
		cout << -1 << endl;
	}
	else {
		cout << vNumBetween[order - 1] << endl;
	}

	return 0;
}