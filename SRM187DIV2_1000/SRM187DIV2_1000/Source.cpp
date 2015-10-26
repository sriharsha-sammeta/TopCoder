#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#define sz(V) int(V.size())
using namespace std;
class PointInPolygon{
public:
	bool checkifThePointIsOnTheLine(pair<int, int>linePoint1, pair<int, int>linePoint2, int &x, int &y){
		bool res1 = min(linePoint1.first, linePoint2.first) <= x && x <= max(linePoint1.first, linePoint2.first);
		bool res2 = min(linePoint1.second, linePoint2.second) <= y && y <= max(linePoint1.second, linePoint2.second);
		return res1 && res2;
	}

	bool checkWhetherLinesIntersect(pair<int, int>linePoint1, pair<int, int>linePoint2, int &x, int &y){
		int stdX = x + 5000;
		int stdY = y;
		int A1 = linePoint2.second - linePoint1.second;
		int B1 = linePoint1.first - linePoint2.first;
		int C1 = (A1*linePoint1.first) + (B1*linePoint1.second);

		int A2 = stdY - y;
		int B2 = x - stdX;
		int C2 = (A2*x) + (B2*y);
		int denomX = (A1*B2) - (A2*B1);
		int denomY = (B1*A2) - (B2*A1);
		double resX = x;
		double resY = y;
		if (denomX == 0 && denomY == 0)
			return false;		
		if (denomX != 0)
			resX = ((C1*B2) - (C2*B1)) / denomX;
		if (denomY != 0)
			resY = ((C1*A2) - (C2*A1)) / denomY;
		if (resX != floor(resX) || resY != floor(resY))
			return false;
		int tempResX = (int)resX;
		int tempResY = (int)resY;
		bool res1 = checkifThePointIsOnTheLine(linePoint1, linePoint2, tempResX, tempResY);
		bool res2 = checkifThePointIsOnTheLine(pair<int, int>(x, y), pair<int, int>(stdX, stdY), tempResX, tempResY);
		return res1 && res2;
		
	}

	string testPoint(vector<pair<int, int> >&V, int &x, int &y){
		int count = 0;
		for (int i = 0; i < sz(V); i++){
			if (checkifThePointIsOnTheLine(V[i], V[(i + 1)%sz(V)], x, y))
				return "BOUNDARY";
			if (checkWhetherLinesIntersect(V[i], V[(i + 1) % sz(V)], x, y)){
				count++;
			}
		}
		if (count % 2 != 0)
			return "INTERIOR";
		return "EXTERIOR";
	}

	string testPoint(vector <string> vertices, int testPointX, int testPointY){
		vector<pair<int, int> > V;
		V.reserve(vertices.size());
		int tempX;
		int tempY;

		for (auto it = vertices.begin(); it != vertices.end(); it++){
			stringstream ss(*it);
			ss >> tempX;
			ss >> tempY;
			V.push_back(pair<int, int>(tempX, tempY));
		}
		return testPoint(V, testPointX, testPointY);
	}
};

int main(){
	vector<string>v;
	/*{"0 0",
		"0 10",
		"10 10",
		"10 0"}
		{{"0 0", "10 0", "10 -10", "20 -10", "20 10", "-10 10", "-10 -30", "40 -30", "40 30", "-30 30", "-30 -50", "60 -50", "60 50", "-50 50", "-50 -70", "80 -70", "80 70", "-70 70", "-70 -90", "100 -90", "100 90", "-90 90", "-90 -110", "120 -110", "120 110", "-120 110", "-120 120", "130 120", "130 -120", "-100 -120", "-100 100", "110 100", "110 -100", "-80 -100", "-80 80", "90 80", "90 -80", "-60 -80", "-60 60", "70 60", "70 -60", "-40 -60", "-40 40", "50 40", "50 -40", "-20 -40", "-20 20", "30 20", "30 -20", "0 -20"}, 5, -10}

	*/
	string str[] = { "500 0", "500 100", "400 100", "400 200", "300 200", "300 300", "200 300", "200 400", "100 400", "100 500", "0 500", "0 400", "-100 400", "-100 300", "-200 300", "-200 200", "-300 200", "-300 100", "-400 100", "-400 0", "-500 0", "-500 -100", "-400 -100", "-400 -200", "-300 -200", "-300 -300", "-200 -300", "-200 -400", "-100 -400", "-100 -500", "0 -500", "0 -400", "100 -400", "100 -300", "200 -300", "200 -200", "300 -200", "300 -100", "400 -100", "400 0" };

	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++){
		v.push_back(str[i]);
	}
	PointInPolygon obj;
	cout << obj.testPoint(v, 200, 200) << endl;
	return 0;
}
