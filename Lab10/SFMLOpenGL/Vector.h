#pragma once
//#include "Vector.h"



//This is lab five before being applied to a practical 

class MyVector3
{


public: 
	// The class has three variables x, y and z 
	double x;
	double y;
	double z;

	

	 //Constructor 1
	MyVector3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	 //Constructor 2
	 MyVector3(double x1, double y1, double z1)
	{ // To allow other values for X, Y and Z to be declared
		x = x1;
		y = y1;
		z = z1;
	 }
	// Constructor 3
	// MyVector3(MyVector3 V)
	//{  // To allow other values for X, Y and Z to be declared
	//	x = V.x;
	//	y = V.y;
	//	z = V.z;
	//}



	 //the code used to calculate the perpindicular Component 
	 MyVector3 operator +(MyVector3 V2);
	 MyVector3 operator -(MyVector3 V2);
	 double operator *(MyVector3 V2);
	 MyVector3 operator  *(double k);
	 MyVector3 operator  *(float k);
	 MyVector3 operator *(int k);
	 MyVector3 operator ^(MyVector3 V2);
	 MyVector3  Normalise(MyVector3 V2);
	 double LengthSquared();
	 MyVector3  Normalise();
	 double Length();
	 double const GetXf();
	 double const GetYf();
	 double const GetZf();

//	 MyVector3  +(MyVector3 V1, MyVector3 V2);


};