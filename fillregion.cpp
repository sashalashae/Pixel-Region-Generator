//Sasha Morgan

#include <iostream>
using namespace std;
#include "region_grower.h"
#include <cstdlib>
#include "EasyBMP.h"

int main(int argc, char* argv[])
{
	if (argc != 8){
		cout << "Usage: fillregion "
			<< endl << argc << endl;
	}

	RegionGrower yoyo;
	string inf;
	inf = argv[1];
	BMP in;


	// declare and read the bitmap
	in.ReadFromFile(inf.c_str());
	yoyo.SetImage(inf);
	int x = atoi(argv[2]);
	int y = atoi(argv[3]);

	yoyo.SetSeed(x, y);
	double a = atoi(argv[4]);
	double b = atoi(argv[5]);
	double c = atoi(argv[6]);

	yoyo.SetReplacement(a, b, c);
	yoyo.Update();
	yoyo.GetOutput(argv[7]);

	// write the output file
	//in.WriteToFile(argv[2]);

	//return 0;
}