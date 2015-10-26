#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
#include <fstream>
#define tr(V,it) for(auto it = V.begin();it!=V.end();it++)
#define sizeA(A) sizeof(A)/sizeof(A[0])
#define sz(V) int(V.size())
using namespace std;
typedef vector<int>vi;
typedef vector<vector<int> >vvi;

ofstream myfile;
class PointInPolygon{
public:
	void display(vvi V){
		tr(V, it){
			tr((*it), it2){
				cout << *it2<<" ";
			}
			cout << endl;
		}
	}
	bool isPointOnTheLine(vector<int> &linePoint1,vector<int> &linePoint2,double testPointX,double testPointY){							
		if (sz(linePoint1) == 2 && sz(linePoint2) == 2){
			bool res1 = (min(linePoint1[0], linePoint2[0]) <= testPointX &&  testPointX <= max(linePoint1[0], linePoint2[0]));
			bool res2 = (min(linePoint1[1], linePoint2[1]) <= testPointY &&  testPointY <= max(linePoint1[1], linePoint2[1]));
			return res1 && res2;
		}
		return false;
	}
	
	bool doesLineInterSectSegment(vvi &V,int i1,int i2, int &testPointX, int &testPointY){		
		int i3 = (i2+1)%sz(V);
		int stdX = 3000;
		int stdY = 3000;
		myfile << "i1: " << "(" << V[i1][0] << " , " << V[i1][1] << ")" << endl;
		myfile << "i2: " << "(" << V[i2][0] << " , " << V[i2][1] << ")" << endl;
		myfile << "i3: " << "(" << V[i3][0] << " , " << V[i3][1] << ")" << endl;

		double A1 = V[i2][1] - V[i1][1];
		double B1 = V[i1][0] - V[i2][0];
		double C1 = (A1*V[i1][0]) + (B1*V[i1][1]);
		A1 = A1 / 1000;
		B1 = B1 / 1000;
		C1 = C1 / 1000;
		double AP = stdY - testPointY;
		double BP = testPointX - stdX;
		double CP= (AP*testPointX) + (BP*testPointY);
		AP = AP / 1000;
		BP = BP / 1000;
		CP = CP / 1000;
		double resX1 = round(((C1*BP) - (CP*B1)) / ((A1*BP) - (AP*B1)));
		double resY1 = round(((C1*AP) - (CP*A1)) / ((B1*AP) - (BP*A1)));
		myfile << "ResPoint1: (" << resX1 << " , " << resY1 << ")" << endl;
		double A2 =(V[i3][1] - V[i2][1]);
		double B2 = (V[i2][0] - V[i3][0]);
		double C2 = ((A2*V[i2][0]) + (B2*V[i2][1]));
		A2 = A2 / 1000;
		B2 = B2 / 1000;
		C2 = C2 / 1000;
		double resX2 = round(((CP*B2) - (C2*BP)) / ((AP*B2) - (A2*BP)));				
		double resY2 = round(((CP*A2) - (C2*AP)) / ((BP*A2) - (B2*AP)));
		myfile << "ResPoint2: (" << resX2 << " , " << resY2 << ")" << endl;
		
		
		bool res1=isPointOnTheLine(V[i1], V[i2], resX1, resY1);	
		vi linePoint1;
		vi linePoint2;
		linePoint1.push_back(testPointX);
		linePoint1.push_back(testPointY);
		linePoint2.push_back(stdX);
		linePoint2.push_back(stdY);
		bool res2 = isPointOnTheLine(linePoint1, linePoint2, resX1, resY1);
		myfile << "Res1: " << res1 << endl;
		myfile << "Res2: " << res2 << endl;
		if ( res1 && res2 && resX2 == resX1  && resY2 == resY1){
			myfile << "Res1 equals Res2 returning false" << endl;
			double x1 = stdX - resX1;
			double y1 = stdY - resY1;
			double x2 = V[i1][0] - resX1;
			double y2 = V[i1][1] - resY1;
			double x3 = V[i3][0] - resX1;
			double y3 = V[i3][1] - resY1;

			double cross1 = (x1*y2) - (x2*y1);
			double cross2 = (x1*y3) - (x3*y1);
			if ((cross1 < 0 && cross2 < 0) || (cross1 >0 && cross2>0))
				return true;
			return false;
		}
		return res1&&res2;
	}

	string testPoint(vector <string> vertices, int testPointX, int testPointY){
		vvi V;		
		V.reserve(vertices.size());
		vi tempVec(2);
		tr(vertices, it){
			istringstream iss((*it));
			iss >> tempVec[0];
			iss >> tempVec[1];
			V.push_back(tempVec);
		}
		int count = 0;
		for (int i = 0; i < sz(V); i++){
			myfile << "i: "<<i << "\n\n";

			if (isPointOnTheLine(V[i], V[(i + 1)%sz(V)], testPointX, testPointY))
				return "BOUNDARY";			
			if (doesLineInterSectSegment(V, i, (i + 1) % sz(V), testPointX, testPointY)){
				count++;				
			}			
			myfile << "count: " << count << endl;
			myfile << "-----------------------------\n" << endl;
		}		
		return (count % 2 != 0) ? "INTERIOR" : "EXTERIOR";
	}
	
};


int main(){
	PointInPolygon P;	
	string str[] = { "0 0", "10 0", "10 -10", "20 -10", "20 10", "-10 10", "-10 -30", "40 -30", "40 30", "-30 30", "-30 -50", "60 -50", "60 50", "-50 50", "-50 -70", "80 -70", "80 70", "-70 70", "-70 -90", "100 -90", "100 90", "-90 90", "-90 -110", "120 -110", "120 110", "-120 110", "-120 120", "130 120", "130 -120", "-100 -120", "-100 100", "110 100", "110 -100", "-80 -100", "-80 80", "90 80", "90 -80", "-60 -80", "-60 60", "70 60", "70 -60", "-40 -60", "-40 40", "50 40", "50 -40", "-20 -40", "-20 20", "30 20", "30 -20", "0 -20" };
	vector<string>V(str, str + sizeA(str));
	myfile.open("C:\\Users\\srihars\\Desktop\\output.txt");
	myfile << P.testPoint(V, 1, 1) << endl;
	myfile.close();
	return 0;
}