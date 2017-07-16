//Sasha Morgan


//#ifndef _REGION_GROWER_H_
//#define _REGION_GROWER_H_

#include "linked_stack.h"
#include  "EasyBMP.h"
#include  <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;


class RegionGrower //: public LinkedStack<T>
{
	public:
		//set the input BMP image to use
	    void SetImage(string ip); 

		//set the seed pixel indices
		void SetSeed(int xcoord, int ycoord); 

		//set the pixel color(RGB) to set the region to
		void SetReplacement(double a, double b, double c); 

		//replace the color in a region defined by seed with new color
		void Update(); 

		//get the new BMP image
		void GetOutput(string op); 

     private:
		 BMP Image;
		 int xx; //location
		 int yy; //location

		 double c1; //red
		 double c2; //blue
		 double c3; //green

		 RGBApixel NewColor;
		 RGBApixel BadColor;
		 RGBApixel Curr;

		 struct pix
		 {
			 int x, y;
		 };

};
//#include "region_grower.cpp"
//#endif // _REGION_GROWER_H_