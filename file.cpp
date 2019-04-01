// ���������� file.h, fstream, std
#include <iostream>
#include <fstream>
#include "file.h"
#include "geometry.h"
using namespace std;

int countPoints(const char *fileName)
{
	ifstream in(fileName);
	if (!in.is_open())
		return -1;
	double x, y;
	int i;
	for (i = 0; ; i++)
	{
		in >> x >> y;
		if (in.fail()) break;
	}
	return i;
}

bool readPoints(const char *fileName, Point *pointArray, int maxPointNum)
{
	ifstream in(fileName);
	// ���� �� ������
	if (!in.is_open())
		return 0;
	for (int i = 0; i < maxPointNum; i++)
	{
		in >> pointArray[i].x >> pointArray[i].y;
		if (in.fail())
			return false;
	}
	return true;
}
bool writeTriangles(const char* fileName, const Triangle* trArray, int trNum)
{
	ofstream out(fileName);
	if (!out.is_open())
		return false;
	for (int i = 0; i < trNum; i++) {
		out << "#" << i + 1 << ": " << trArray[i].area << endl;

		out << "(" << trArray[i].vertexes[0].x << ";" << trArray[i].vertexes[0].y << ") ";
		out << "(" << trArray[i].vertexes[1].x << ";" << trArray[i].vertexes[1].y << ") ";
		out << "(" << trArray[i].vertexes[2].x << ";" << trArray[i].vertexes[2].y << ")" << endl;
	}
	return true;
}