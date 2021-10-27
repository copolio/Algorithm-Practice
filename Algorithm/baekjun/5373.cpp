#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int nTestCases;
char cube[6][3][3];
vector<vector<string>> vCmds;

void InitCube() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[0][i][j] = 'w';
			cube[1][i][j] = 'y';
			cube[2][i][j] = 'r';
			cube[3][i][j] = 'o';
			cube[4][i][j] = 'g';
			cube[5][i][j] = 'b';
		}
	}
}

void GetInput() {
	cin >> nTestCases;
	for (int i = 0; i < nTestCases; i++) {
		int n;
		string cmd;
		vector<string> temp;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> cmd;
			temp.push_back(cmd);
		}
		vCmds.push_back(temp);
	}
}

void RotateU() {
	char temp1 = cube[2][0][0];
	char temp2 = cube[2][0][1];
	char temp3 = cube[2][0][2];
	cube[2][0][0] = cube[5][0][0];
	cube[2][0][1] = cube[5][0][1];
	cube[2][0][2] = cube[5][0][2];
	cube[5][0][0] = cube[3][2][0];
	cube[5][0][1] = cube[3][2][1];
	cube[5][0][2] = cube[3][2][2];
	cube[3][2][0] = cube[4][0][0];
	cube[3][2][1] = cube[4][0][1];
	cube[3][2][2] = cube[4][0][2];
	cube[4][0][0] = temp1;
	cube[4][0][1] = temp2;
	cube[4][0][2] = temp3;
}

void RotateD() {
	char temp1 = cube[2][2][0];
	char temp2 = cube[2][2][1];
	char temp3 = cube[2][2][2];
	cube[2][2][0] = cube[4][2][0];
	cube[2][2][1] = cube[4][2][1];
	cube[2][2][2] = cube[4][2][2];
	cube[4][2][0] = cube[3][0][0];
	cube[4][2][1] = cube[3][0][1];
	cube[4][2][2] = cube[3][0][2];
	cube[3][0][0] = cube[5][2][0];
	cube[3][0][1] = cube[5][2][1];
	cube[3][0][2] = cube[5][2][2];
	cube[5][2][0] = temp1;
	cube[5][2][1] = temp2;
	cube[5][2][2] = temp3;
}

void RotateF() {
	char temp1 = cube[0][2][0];
	char temp2 = cube[0][2][1];
	char temp3 = cube[0][2][2];
	cube[0][2][0] = cube[4][0][2];
	cube[0][2][1] = cube[4][1][2];
	cube[0][2][2] = cube[4][2][2];
	cube[4][0][2] = cube[1][0][0];
	cube[4][1][2] = cube[1][0][1];
	cube[4][2][2] = cube[1][0][2];
	cube[1][0][0] = cube[5][0][0];
	cube[1][0][1] = cube[5][1][0];
	cube[1][0][2] = cube[5][2][0];
	cube[5][0][0] = temp1;
	cube[5][1][0] = temp2;
	cube[5][2][0] = temp3;
}

void RotateB() {
	char temp1 = cube[0][0][0];
	char temp2 = cube[0][0][1];
	char temp3 = cube[0][0][2];
	cube[0][0][0] = cube[5][0][2];
	cube[0][0][1] = cube[5][1][2];
	cube[0][0][2] = cube[5][2][2];
	cube[5][0][2] = cube[1][2][0];
	cube[5][1][2] = cube[1][2][1];
	cube[5][2][2] = cube[1][2][2];
	cube[1][2][0] = cube[4][0][0];
	cube[1][2][1] = cube[4][1][0];
	cube[1][2][2] = cube[4][2][0];
	cube[4][0][0] = temp1;
	cube[4][1][0] = temp2;
	cube[4][2][0] = temp3;
}

void RotateL() {
	char temp1 = cube[0][0][0];
	char temp2 = cube[0][1][0];
	char temp3 = cube[0][2][0];
	cube[0][0][0] = cube[3][0][2];
	cube[0][1][0] = cube[3][1][2];
	cube[0][2][0] = cube[3][2][2];
	cube[3][0][2] = cube[1][0][0];
	cube[3][1][2] = cube[1][1][0];
	cube[3][2][2] = cube[1][2][0];
	cube[1][0][0] = cube[2][0][0];
	cube[1][1][0] = cube[2][1][0];
	cube[1][2][0] = cube[2][2][0];
	cube[2][0][0] = temp1;
	cube[2][1][0] = temp2;
	cube[2][2][0] = temp3;
}

void RotateR() {
	char temp1 = cube[0][0][2];
	char temp2 = cube[0][1][2];
	char temp3 = cube[0][2][2];
	cube[0][0][2] = cube[2][0][2];
	cube[0][1][2] = cube[2][1][2];
	cube[0][2][2] = cube[2][2][2];
	cube[2][0][2] = cube[1][0][2];
	cube[2][1][2] = cube[1][1][2];
	cube[2][2][2] = cube[1][2][2];
	cube[1][0][2] = cube[3][0][0];
	cube[1][1][2] = cube[3][1][0];
	cube[1][2][2] = cube[3][2][0];
	cube[3][0][0] = temp1;
	cube[3][1][0] = temp2;
	cube[3][2][0] = temp3;
}

void Rotate(char plane) {
	int nPlane;
	int temp[3][3];
	switch (plane) {
	case 'U':
		nPlane = 0;
		RotateU();
		break;
	case 'D':
		nPlane = 1;
		RotateD();
		break;
	case 'F':
		nPlane = 2;
		RotateF();
		break;
	case 'B':
		nPlane = 3;
		RotateB();
		break;
	case 'L':
		nPlane = 4;
		RotateL();
		break;
	case 'R':
		nPlane = 5;
		RotateR();
		break;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp[i][j] = cube[nPlane][i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[nPlane][i][j] = temp[2-j][i];
		}
	}

}

void PrintTop() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[0][i][j];
		}
		cout << endl;
	}
}

void Solution() {
	for (int i = 0; i < vCmds.size(); i++) {
		InitCube();
		for (int j = 0; j < vCmds[i].size(); j++) {
			if (vCmds[i][j][1] == '-') {
				for (int k = 0; k < 3; k++) {
					Rotate(vCmds[i][j][0]);
				}
			}
			else {
				Rotate(vCmds[i][j][0]);
			}
			//PrintTop();
			//cout << endl;
		}
		PrintTop();
	}
}

int main() {
	GetInput();
	Solution();
	return 0;
}