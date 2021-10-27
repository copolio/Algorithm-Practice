struct City {
	string name;
	int x, y;
	City() {
		x = 0;
		y = 0;
		name = "";
	}
	City(string _name, int _x, int _y) {
		x = _x;
		y = _y;
		name = _name;
	}
	bool operator < (const City &v) const {
		if (y == v.y)
			return x < v.x;
		else
			return y < v.y;
	}
};

double GetDistance(City c1, City c2) {
	double x1 = (double)c1.x;
	double x2 = (double)c2.x;
	double y1 = (double)c1.y;
	double y2 = (double)c2.y;
	return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

pair<City, double> FindClosestCity(City &city, set<City> &cities) {
	double closestDistance = 0;
	auto lowerBound = cities.lower_bound(city);
	auto upperBound = cities.upper_bound(city);
	if (lowerBound != cities.begin()) --(lowerBound);
	if (upperBound != cities.end()) ++(upperBound);

	auto nearCity = cities.begin();

	for (auto it = lowerBound; it != upperBound; ++it) {
		double d = GetDistance(city, *it);
		if (it->name == city.name) continue;
		if (d < closestDistance || closestDistance == 0) {
			closestDistance = d;
			nearCity = it;
		}
		else if (d == closestDistance) {
			nearCity = nearCity->name.compare(it->name) < 0 ? it : nearCity;
		}
	}
	return make_pair(*nearCity, closestDistance);
}
City FindClosestCity(pair<City, double> &nearcity1, pair<City, double> &nearcity2) {
	if (nearcity1.second < nearcity2.second)
		return nearcity1.first;
	else if (nearcity1.second > nearcity2.second)
		return nearcity2.first;
	else
		return (nearcity1.first.name.compare(nearcity2.first.name) > 0 ? nearcity2.first : nearcity1.first);
}
vector<string> closestStraightCity(vector<string> c, vector<int> x, vector<int> y, vector<string> q) {
	vector<string> result;
	vector<string> answer;
	int nCities = c.size();
	int nQuestions = q.size();
	unordered_map<int, set<City>> citiesInX;
	unordered_map<int, set<City>> citiesInY;
	unordered_map<string, City> cityMap;

	for (int i = 0; i < nCities; i++) {
		cityMap[c[i]] = City(c[i], x[i], y[i]);
		citiesInX[x[i]].insert(City(c[i], x[i], y[i]));
		citiesInY[y[i]].insert(City(c[i], x[i], y[i]));
	}

	for (int i = 0; i < nQuestions; i++) {
		City city = cityMap[q[i]];
		string cityName = city.name;

		if (citiesInX[city.x].size() == 1 && citiesInY[city.y].size() == 1) {
			result.push_back("NONE");
			continue;
		}
		else if (citiesInX[city.x].size() > 1 && citiesInY[city.y].size() > 1) {
			pair<City, double> nearCityInX = FindClosestCity(city, citiesInX[city.x]);
			pair<City, double> nearCityInY = FindClosestCity(city, citiesInY[city.y]);
			City closestCity = FindClosestCity(nearCityInX, nearCityInY);
			result.push_back(closestCity.name);
		}
		else if (citiesInX[city.x].size() > 1) {
			City closestCity = FindClosestCity(city, citiesInX[city.x]).first;
			result.push_back(closestCity.name);
		}
		else {
			City closestCity = FindClosestCity(city, citiesInY[city.y]).first;
			result.push_back(closestCity.name);
		}
	}

	return result;
}