#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
class PointInPolygon{
public:
	string testPoint(vector <string> vertices, int testPointX, int testPointY){

		// boundary check 
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		for (int i = 0; i < int(vertices.size()); i++){
			istringstream ss1(vertices[i]);
			istringstream ss2(vertices[(i + 1) % vertices.size()]);
			ss1 >> x1;
			ss1 >> y1;
			ss2 >> x2;
			ss2 >> y2;
			if (min(x1, x2) <= testPointX && testPointX <= max(x1, x2) && min(y1, y2) <= testPointY && testPointY <= max(y1, y2))
				return "BOUNDARY";
		}
		testPointX = testPointX * 2 + 1;
		testPointY = testPointY * 2 + 1;
		int cnt = 0;
		for (int i = 0; i < int(vertices.size()); i++){
			istringstream ss1(vertices[i]);
			istringstream ss2(vertices[(i + 1) % vertices.size()]);
			ss1 >> x1;
			ss1 >> y1;
			ss2 >> x2;
			ss2 >> y2;
			x1 = 2 * x1;
			y1 = 2 * y1;
			x2 = 2 * x2;
			y2 = 2 * y2;
			if (testPointX < x1 && x1 == x2 && testPointY <= max(y1, y2) && testPointY >= min(y1, y2))
				cnt++;
		}
		if (cnt % 2 != 0)
			return "INTERIOR";
		return "EXTERIOR";
	}
};