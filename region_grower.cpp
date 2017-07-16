//Sasha Morgan

#include "region_grower.h"
//#include <cstdlib>
using namespace std;


//This function sets the image to the inputed file
void RegionGrower::SetImage(string ip)
{
	Image.ReadFromFile(ip.c_str()); //reads the input file
}



//This function sets the location
void RegionGrower::SetSeed(int xcoord, int ycoord)
{
	xx = xcoord; //sets the input variable
	yy = ycoord; //sets the input variable
}

//This fuction sets the pixel color(RGB) to set the region to
void RegionGrower::SetReplacement(double a, double b, double c)
{
	c1 = a; //red
	c2 = b; //blue
	c3 = c; //green
}

//This function replaces the color in a region defined by seed with new color
void RegionGrower::Update()
{
	
	   //get & remove top item   set item to zombie
	//if item below not a zombie or a cat then
	//add item to stack   if item above not a zombie or a cat then
	//add item to stack   if item left not a zombie or a cat then
	//add item to stack
	
	//while stack not empty
	LinkedStack<pix> change;
	pix ar;
	ar.x = xx;
	ar.y = yy;
	change.push(ar);

	while (!change.isempty())
	{

		change.top();//peek at the area around us

		Curr = Image.GetPixel(xx, yy);
		change.pop();//take the first item off the stack


		//if pixel below not the desired color and same color as the item 


		//if ()
		//{

		//}


		//add the pixel to the stack

		//Then set the desired color at the bottom
		//set item to correct pixel
		pix now = change.top();  //creates a new pointer
		int m = now.x; //takes the postision
		int n = now.y; //takes the position
		Image(m, n)->Red = (ebmpBYTE)c1; //changes the color
		Image(m, n)->Blue = (ebmpBYTE)c2; //changes the color
		Image(m, n)->Green = (ebmpBYTE)c3; //changes the color
		//change.pop();


		//Only put things that you know you can operate on in the stack
		//Bottom Position
		if (Image(xx, yy - 1)->Red != Image(xx, yy - 1)->Red || Image(xx, yy - 1)->Blue != Image(xx, yy - 1)->Blue
			|| Image(xx, yy - 1)->Green != Image(xx, yy - 1)->Green)//Checks the bottom postion
		{
			pix addThose; //creates a new node
			addThose.x = xx; //sets the x location
			addThose.y = yy - 1; //sets the y location
			change.push(addThose); //adds it to the stack
		}

		//Top Positon
		if (Image(xx, yy + 1)->Red != Image(xx, yy + 1)->Red || Image(xx, yy + 1)->Blue != Image(xx, yy + 1)->Blue
			|| Image(xx, yy + 1)->Green != Image(xx, yy + 1)->Green)//Checks the top position
		{
			pix addThat; //creates a new node
			addThat.x = xx; //sets the x location
			addThat.y = yy + 1; //sets the y location
			change.push(addThat); //adds it to the stack
		}
		//Left Position
		if (Image(xx - 1, yy)->Red != Image(xx - 1, yy)->Red || Image(xx - 1, yy)->Blue != Image(xx - 1, yy)->Blue
			|| Image(xx - 1, yy)->Green != Image(xx - 1, yy)->Green)//Checks the left postion
		{
			pix addThis; //creates a new node
			addThis.x = xx - 1; //sets the x location
			addThis.y = yy; //sets the y location
			change.push(addThis); //adds it to the stack
		}

		//Right Position
		if (Image(xx + 1, yy)->Red != Image(xx, yy)->Red || Image(xx + 1, yy)->Blue != Image(xx + 1, yy)->Blue 
			|| Image(xx + 1, yy)->Green != Image(xx + 1, yy)->Green)//Checks the right position
		{
			pix toAdd; //creates a new node
			toAdd.x = xx + 1; //sets the location
			toAdd.y = yy; //sets the location
			change.push(toAdd); //pushes it to the stack
		}


	}
	
}
//This function sets the image to a designated output file
void RegionGrower::GetOutput(string op)
{
	Image.WriteToFile(op.c_str());//writes the output file
}