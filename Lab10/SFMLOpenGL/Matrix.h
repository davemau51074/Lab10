#pragma once

#include "Vector.h"
#include <iostream>

	class Matrix3
	{// The class has nine variables, 3 rows and 3 columns
	public:
		 double A11 = 0;
		 double A12 = 0;
		 double A13 = 0;
		 double A21 = 0;
		 double A22 = 0;
		 double A23 = 0;
		 double A31 = 0;
		 double A32 = 0;
		 double A33 = 0;

		// Constructor 1 create a zero matrix
		 Matrix3()
		{
			A11 = 0.0;
			A12 = 0.0;
			A13 = 0.0;
			A21 = 0.0;
			A22 = 0.0;
			A23 = 0.0;
			A31 = 0.0;
			A32 = 0.0;
			A33 = 0.0;
		}
		
		// Constructor 2
		 Matrix3(MyVector3 Row1, MyVector3 Row2, MyVector3 Row3)
		{  // To allow 3 rows of vectors to be declared as a matrix
			A11 = Row1.x;
			A12 = Row1.y;
			A13 = Row1.z;
			A21 = Row2.x;
			A22 = Row2.y;
			A23 = Row2.z;
			A31 = Row3.x;
			A32 = Row3.y;
			A33 = Row3.z;
		}

		// Constructor 3
		 Matrix3(double _A11, double _A12, double _A13,
			double _A21, double _A22, double _A23,
			double _A31, double _A32, double _A33)
		{// to allow nine double values
			A11 = _A11;
			A12 = _A12;
			A13 = _A13;
			A21 = _A21;
			A22 = _A22;
			A23 = _A23;
			A31 = _A31;
			A32 = _A32;
			A33 = _A33;
		}

		 //MyVector3 operator *(Matrix3 M1, MyVector3 V1);
	     Matrix3 Transpose ();
		 Matrix3 operator +(Matrix3 M2);
		 Matrix3 operator -(Matrix3 M2);
		 Matrix3 operator *(double x);
		 Matrix3 operator *(Matrix3 M2);
		 MyVector3 Row(int i);
		 MyVector3 Column(int i);
		 MyVector3 operator *(MyVector3 V1);
		 Matrix3 Inverse(Matrix3 M1);
		 Matrix3 RotationY(int _angle);
		 Matrix3 RotationX(int _angle);
		 Matrix3 RotationZ(int _angle);


	};