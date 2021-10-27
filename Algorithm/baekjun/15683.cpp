#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int N, M, minDeadzoneArea = INF;
//vector<vector<int>> office;
int office[8][8];
vector<pair<int, int>> cameras;
int dirX[4] = { 0, 0, 1, -1 };
int dirY[4] = { 1, -1, 0, 0 };

void GetDeadZone(int office_copy[8][8]) {
	int area = 0;
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << office_copy[i][j] << " ";
			if (office_copy[i][j] == 0) area++;
		}
		cout << endl;
	}
	minDeadzoneArea = area < minDeadzoneArea ? area : minDeadzoneArea;
}

bool EqualArray(int arr1[8][8], int arr2[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr1[i][j] != arr2[i][j]) return false;
		}
	}
	return true;
}

void DFS(int office_copy[8][8], int idx) {
	//cout << idx << endl;
	if (cameras.empty()) {
		GetDeadZone(office_copy);
		return;
	}
	if (idx >= cameras.size()) {
		GetDeadZone(office_copy);
		return;
	}
	if (office[cameras[idx].first][cameras[idx].second] == 1) {
		for (int i = 0; i < 4; i++) {
			int temp[8][8] = { 0, };
			memcpy(temp, office_copy, sizeof(int)*8*8);
			int row = cameras[idx].first;
			int col = cameras[idx].second;
			while (true) {
				row += dirY[i];
				col += dirX[i];
				if (row < 0 || row > N - 1 || col < 0 || col > M - 1) break;
				if (temp[row][col] == 6) break;
				if (temp[row][col] == 0) temp[row][col] = 7;
			}
			DFS(temp, idx + 1);
		}
	}
	else if (office[cameras[idx].first][cameras[idx].second] == 2) {
		for (int i = 0; i < 2; i++) {
			int temp[8][8] = { 0, };
			memcpy(temp, office_copy, sizeof(int) * 8 * 8);
			bool visited[8][8] = { false, };
			queue<pair<int, int>> q;
			q.push(cameras[idx]);
			while (!q.empty()) {
				int row = q.front().first;
				int col = q.front().second;
				q.pop();
				visited[row][col] = true;
				if (temp[row][col] == 0) temp[row][col] = 7;
				if (row + dirY[i * 2] >= 0 && 
					row + dirY[i * 2] < N && 
					col + dirX[i * 2] >= 0 && 
					col + dirX[i * 2] < M && 
					!visited[row + dirY[i * 2]][col + dirX[i * 2]] &&
					temp[row + dirY[i * 2]][col + dirX[i * 2]] != 6)
					q.push(make_pair(row + dirY[i * 2], col + dirX[i * 2]));
				if (row + dirY[i * 2 + 1] >= 0 && 
					row + dirY[i * 2 + 1] < N && 
					col + dirX[i * 2 + 1] >= 0 && 
					col + dirX[i * 2 + 1] < M && 
					!visited[row + dirY[i * 2 + 1]][col + dirX[i * 2 + 1]] &&
					temp[row + dirY[i * 2 + 1]][col + dirX[i * 2 + 1]] != 6)
					q.push(make_pair(row + dirY[i * 2 + 1], col + dirX[i * 2 + 1]));
			}
			DFS(temp, idx + 1);
		}
	}
	else if (office[cameras[idx].first][cameras[idx].second] == 3) {
		
		for (int i = 0; i < 4; i++) {
			int temp[8][8] = { 0, };
			memcpy(temp, office_copy, sizeof(int) * 8 * 8);
			for (int j = i-1; j <= i; j++) {
				int row = cameras[idx].first;
				int col = cameras[idx].second;
				while (true) {
					row += dirY[j];
					col += dirX[j];
					if (row < 0 || row > N - 1 || col < 0 || col > M - 1) break;
					if (temp[row][col] == 6) break;
					if (temp[row][col] == 0) temp[row][col] = 7;
				}
			}
			DFS(temp, idx + 1);
		}
	}
	else if (office[cameras[idx].first][cameras[idx].second] == 4) {
		for (int i = 0; i < 4; i++) {
			int temp[8][8] = { 0, };
			memcpy(temp, office_copy, sizeof(int) * 8 * 8);
			for (int j = 0; j < 4; j++) {
				if (j == i) continue;
				int row = cameras[idx].first;
				int col = cameras[idx].second;
				while (true) {
					row += dirY[j];
					col += dirX[j];
					if (row < 0 || row > N - 1 || col < 0 || col > M - 1) break;
					if (temp[row][col] == 6) break;
					if (temp[row][col] == 0) temp[row][col] = 7;
				}
			}
			DFS(temp, idx + 1);
		}
	}
	else if (office[cameras[idx].first][cameras[idx].second] == 5) {
		int temp[8][8] = { 0, };
		memcpy(temp, office_copy, sizeof(int) * 8 * 8);
		for (int i = 0; i < 4; i++) {
			int row = cameras[idx].first;
			int col = cameras[idx].second;
			while (true) {
				row += dirY[i];
				col += dirX[i];
				if (row < 0 || row > N - 1 || col < 0 || col > M - 1) break;
				if (temp[row][col] == 6) break;
				if (temp[row][col] == 0) temp[row][col] = 7;
			}
		}
		DFS(temp, idx + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < M; j++) {
			int room;
			cin >> room;
			if (room > 0 && room < 6) {
				cameras.push_back(make_pair(i, j));
			}
			office[i][j] = room;
		}
	}
	DFS(office, 0);
	cout << minDeadzoneArea;

	return 0;
}

////////// �̻� �ð��ʰ� �ڵ� //////////////
////////// ���� ���� �ڵ� //////////////

#include <iostream>
#define endl '\n'
using namespace std;

struct CCTV
{
	int type, r, c;
};
int N, M, ans = 1e9, map[8][8];
int cctv_size;
CCTV cctv[8];
const int rotation[] = { NULL, 4, 2, 4, 4, 1 };

void map_cpy(int desc[8][8], int src[8][8])
{
	for (int r = 0; r < N; ++r)
		for (int c = 0; c < M; ++c)
			desc[r][c] = src[r][c];
}
// update �Լ��� �� �������θ� ���ø� �� �ִ� �Լ�.
void update(int dir, CCTV cctv)
{
	// cctv�� �������� dir ���⿡ ���� üũ�� �Ѵ�.
	// dir = 0 : ��, 1 : ��, 2 : ��, 3 : ��
	dir %= 4;    // dir���� 4���� ū ���� ���� �� �����Ƿ�
	if (dir == 0)            // ����
	{
		for (int c = cctv.c + 1; c < M; ++c)
		{
			if (map[cctv.r][c] == 6) break;
			map[cctv.r][c] = -1;
		}
	}
	else if (dir == 1)    // ����
	{
		for (int r = cctv.r - 1; r >= 0; --r)
		{
			if (map[r][cctv.c] == 6) break;
			map[r][cctv.c] = -1;
		}
	}
	else if (dir == 2)    // ����
	{
		for (int c = cctv.c - 1; c >= 0; --c)
		{
			if (map[cctv.r][c] == 6) break;
			map[cctv.r][c] = -1;
		}
	}
	else if (dir == 3)    // ����
	{
		for (int r = cctv.r + 1; r < N; ++r)
		{
			if (map[r][cctv.c] == 6) break;
			map[r][cctv.c] = -1;
		}
	}
}
void DFS(int cctv_idx)
{
	if (cctv_idx == cctv_size)
	{
		int cnt = 0;
		// 0�� ���� count
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				if (map[r][c] == 0)
					++cnt;
			}
		}
		if (ans > cnt)
			ans = cnt;
		return;
	}
	int backup[8][8];
	int type = cctv[cctv_idx].type;

	for (int dir = 0; dir < rotation[type]; ++dir)
	{
		// map ���
		map_cpy(backup, map);

		// map ������Ʈ
		// update �Լ��� �� ���⸸ �����ϴ� �Լ�.
		// ���� �� �Լ��� �ʿ信 �°� ȣ���� �ָ� ��.
		if (type == 1)            // 1�� ī�޶�� �� ���� �����̴� �ϳ��� �ҷ���.
		{
			update(dir, cctv[cctv_idx]);
		}
		else if (type == 2)        // 2�� ī�޶�� �⺻����� �� 180�� �ݴ������ ������.
		{
			update(dir, cctv[cctv_idx]);
			update(dir + 2, cctv[cctv_idx]);
		}
		else if (type == 3)        // 3�� ī�޶�� �⺻����� 90�� ������ ������.
		{
			update(dir, cctv[cctv_idx]);
			update(dir + 1, cctv[cctv_idx]);
		}
		else if (type == 4)        // 4�� ī�޶�� �⺻����� 90��, 180�� ������ ������
		{
			update(dir, cctv[cctv_idx]);
			update(dir + 1, cctv[cctv_idx]);
			update(dir + 2, cctv[cctv_idx]);
		}
		else if (type == 5)        // 5�� ī�޶�� �� ���� ��� ������
		{
			update(dir, cctv[cctv_idx]);
			update(dir + 1, cctv[cctv_idx]);
			update(dir + 2, cctv[cctv_idx]);
			update(dir + 3, cctv[cctv_idx]);
		}

		DFS(cctv_idx + 1);

		// map ���� - ��Ʈ��ŷ
		map_cpy(map, backup);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			cin >> map[r][c];
			if (map[r][c] != 0 && map[r][c] != 6)
			{
				cctv[cctv_size].r = r;
				cctv[cctv_size].c = c;
				cctv[cctv_size].type = map[r][c];
				++cctv_size;
			}
		}
	}
	DFS(0);
	cout << ans << endl;
	return 0;
}