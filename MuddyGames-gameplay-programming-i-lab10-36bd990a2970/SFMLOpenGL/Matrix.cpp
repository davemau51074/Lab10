#include "Matrix.h"
#include <iostream>
MyVector3 Matrix3::operator *( MyVector3 V1)
{// An overloaded operator * to return the  product of the matrix by a vector
	return MyVector3(A11 * V1.x + A12 * V1.y + A13 * V1.z,
				   A21 * V1.x + A22 * V1.y + A23 * V1.z,
				   A31 * V1.x + A32 * V1.y + A33 * V1.z);
}

 Matrix3 Matrix3::Transpose()
 {// a method to transpose a given matrix
	 return Matrix3(A11, A21, A31,
				    A12, A22, A32,
			        A13, A23, A33);

 }
 
 Matrix3 Matrix3::operator +(Matrix3 M2)
{// An overloaded operator + to return the  sum of two matrix 
	return Matrix3(A11 + A11, A12 + A12, A13 + A13,
				   A21 + A21, A22 + A22, A23 + A23,
				   A31 + A31, A32 + A32, A33 + A33);
}
 Matrix3 Matrix3::operator -( Matrix3 M2)
{// An overloaded operator * to return the  difference of two matrix
	return Matrix3(A11 - A11, A12 - A12, A13 - A13,
				   A21 - A21, A22 - A22, A23 - A23,
				   A31 - A31, A32 - A32, A33 - A33);
}

 Matrix3 Matrix3::operator*(double x)
{// An overloaded operator * to return the  product of the matrix by a scalar
	Matrix3 answer = Matrix3();
	A11 = A11 * x;
	A12 = A12 * x;
	A13 = A13 * x;

	A21 = A21 * x;
	A22 = A22 * x;
	A23 = A23 * x;

	A31 = A31 * x;
	A32 = A32 * x;
	A33 = A33 * x; ;

	return answer;
}

Matrix3 Matrix3::operator *(Matrix3 M2)
{// An overloaded operator * to return the  product of two matrix
	Matrix3 answer = Matrix3();
	A11 = Row(0) * Column(0);
	A12 = Row(0) * Column(1);
	A13 = Row(0) * Column(2);

	A21 = Row(1) * Column(0);
	A22 = Row(1) * Column(1);
	A23 = Row(1) * Column(2);

	A31 = Row(2) * Column(0);
	A32 = Row(2) * Column(1);
	A33 = Row(2) * Column(2);


	return answer;
}


 double Determinant(Matrix3 M1)
{// method to return the determinant of a 3x3 matrix
 //                     aei      -     ahf                  + dhc                     - gec                      +    gbh                    -     dbi   
	return M1.A11 * M1.A22 * M1.A33 - M1.A11 * M1.A32 * M1.A23 + M1.A21 * M1.A32 * M1.A13 - M1.A31 * M1.A22 * M1.A13 + M1.A31 * M1.A12 * M1.A23 - M1.A21 * M1.A12 * M1.A33;
}

 MyVector3 Matrix3::Row(int i)
{
	// a method to return as Row as MyVector3 0 == first row, default == last row
	switch (i)
	{
	case 0:
		return MyVector3(A11, A12, A13);
	case 1:
		return MyVector3(A21, A22, A23);
	default:
		return MyVector3(A31, A32, A33);
	}
	
}

 MyVector3 Matrix3::Column(int i)
{// a method to return as column as MyVector3 0 == first column, default == last column
	switch (i)
	{
	case 0:
		return MyVector3(A11, A21, A31);
	case 1:
		return MyVector3(A12, A22, A32);
	case 2:
	default:
		return MyVector3(A13, A23, A33);
	}
}


 Matrix3 Matrix3::Inverse(Matrix3 M1)
{
	// method to return the inverse of a matrix if exists else zero vector
	double det = Determinant(M1);
	if (det == 0)
		return Matrix3();
	else
	{
		double scale = 1 / det;
		Matrix3 answer = Matrix3();
		answer.A11 = scale * (M1.A22 * M1.A33 - M1.A23 * M1.A32); // ei-fh
		answer.A12 = scale * (M1.A13 * M1.A32 - M1.A12 * M1.A33); // ch-bi
		answer.A13 = scale * (M1.A12 * M1.A23 - M1.A13 * M1.A22); // ch-bi

		answer.A21 = scale * (M1.A23 * M1.A31 - M1.A21 * M1.A33); // fg-di
		answer.A22 = scale * (M1.A11 * M1.A33 - M1.A13 * M1.A31); // ai-cg
		answer.A23 = scale * (M1.A13 * M1.A21 - M1.A11 * M1.A23); // cd-af


		answer.A31 = scale * (M1.A21 * M1.A32 - M1.A22 * M1.A31); // dh-eg
		answer.A32 = scale * (M1.A12 * M1.A31 - M1.A11 * M1.A32); // bg-ah
		answer.A33 = scale * (M1.A11 * M1.A22 - M1.A12 * M1.A21); // ae-bd

		return answer;
	}

}


 Matrix3 Rotation(int _angle)
{
	double radians = std::acos(-1) / 180 * _angle;
	Matrix3 answer = Matrix3();
	answer.A11 = acos(radians);
	answer.A12 = asin(radians);
	answer.A13 = 0;
	answer.A21 = -asin(radians);
	answer.A22 = acos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}


 Matrix3 Translate(int dx, int dy)
{
	Matrix3 answer = Matrix3();
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = dx;
	answer.A32 = dy;
	answer.A33 = 1;

	return answer;
}

 Matrix3 Scale(int dx, int dy)
{
	Matrix3 answer =  Matrix3();
	answer.A11 = (double)dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)dy / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

 Matrix3 operator -(Matrix3 M1)
{
	return Matrix3(-M1.A11, -M1.A12, -M1.A13, -M1.A21, -M1.A22, -M1.A23, -M1.A31, -M1.A32, -M1.A33);
}

 Matrix3 Matrix3::RotationX(int _angle)
{
	double radians = std::acos(-1) / 180 * _angle;
	Matrix3 answer =  Matrix3();
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = acos(radians);
	answer.A23 = -asin(radians);
	answer.A31 = 0;
	answer.A32 = asin(radians);
	answer.A33 = -acos(radians);

	return answer;
}
 Matrix3 Matrix3::RotationY(int _angle)
{
	double radians = std::acos(-1) / 180 * _angle;
	Matrix3 answer = Matrix3();
	answer.A11 = acos(radians);
	answer.A12 = 0;
	answer.A13 = asin(radians);
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = -asin(radians);
	answer.A32 = 0;
	answer.A33 = acos(radians);

	return answer;
}


 Matrix3 Matrix3::RotationZ(int _angle)
{
	double radians = std::acos(-1) / 180 * _angle;
	Matrix3 answer = Matrix3();
	answer.A11 = acos(radians);
	answer.A12 = -asin(radians);
	answer.A13 = 0;
	answer.A21 = asin(radians);
	answer.A22 = acos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

 Matrix3 Scale3D(int dx)
{
	Matrix3 answer = Matrix3();
	answer.A11 = (double)dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)dx / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = (double)dx / 100;

	return answer;
}