#include <string>
#include <vector>

using namespace std;

bool CanBuild(int y, int x, vector<int> buildingSize, vector<vector<int>> land, int height, int width) {

	for (int i = 0; i < buildingSize[0]; i++) {
		for (int j = 0; j < buildingSize[1]; j++) {
			if (y + i < 0 || y + i >= height || x + j < 0 || x + j >= width) return false;
			if (land[y + i][x + j] == 1) return false;
		}
	}
	return true;
}

int solution(vector<int> buildingSize, vector<vector<int>> land) {
	int answer = 0;
	vector<vector<bool>> visited(land.size(), vector<bool>(land.size(), false));
	int width = land[0].size();
	int height = land.size();
	vector<int> rBuildingSize = buildingSize;
	rBuildingSize[0] = buildingSize[1];
	rBuildingSize[1] = buildingSize[0];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (CanBuild(i, j, buildingSize, land, height, width)) answer++;
			if (buildingSize[0] != buildingSize[1]) {
				if (CanBuild(i, j, rBuildingSize, land, height, width)) answer++;
			}
		}
	}

	return answer;
}