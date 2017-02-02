#include "Vector.h"









//MyVector3()
//{}





//MyVector3()
//{
//
//
//
//
//}







  MyVector3 MyVector3::operator +(MyVector3 V2)
{  // An overloaded operator + to return the sum of 2 vectors
	return MyVector3(x + V2.x, y + V2.y, z + V2.z);
}

 MyVector3 MyVector3::operator -( MyVector3 V2)
{ // An overloaded operator - to return the difference of 2 vectors
	return MyVector3(x - V2.x, y- V2.y, z - V2.z);
}

 double MyVector3::operator *( MyVector3 V2)
{// An overloaded operator * to return the scalar product of 2 vectors
	return double(x * V2.x + y * V2.y + z * V2.z);
}

 MyVector3 operator *(double k, MyVector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return MyVector3(V1.x * (float)k, V1.y * (float)k, V1.z * (float)k);
}

 MyVector3 operator *(float k, MyVector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return MyVector3(V1.x * k, V1.y * k, V1.z * k);
}

 MyVector3 operator *(int k, MyVector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return MyVector3(V1.x * k, V1.y * k, V1.z * k);
}

 MyVector3 operator ^(MyVector3 V1, MyVector3 V2)
{// An overloaded operator ^ to return the vector product of 2 vectors
	return MyVector3(V1.y * V2.z - V1.z * V2.y, V1.z * V2.x - V1.x * V2.z, V1.x * V2.y - V1.y * V2.x);
}

 double MyVector3::LengthSquared()
 {
 
 
 
	 return double(x * x +  y * y + z * z);
 
 
 }


 double MyVector3::Length()
 {
	 return double(x * x + y * y + z * z);
 }




 MyVector3 MyVector3::Normalise(MyVector3 V1)
 {
	 if (Length() > 0.0)
	 {  // Check for divide by zero
		 double magnit = Length();
		 x /= magnit;
		 y /= magnit;
		 z /= magnit;
	 }
	 return MyVector3(x, y, z);
 }

//string ToString()
//{
//	return "(" + x.ToString("g3") + "," + y.ToString("g3") + "," + z.ToString("g3") + ")";
//}

 double const MyVector3::GetXf()
 {
 
	 return	x;
 
 }


 double const MyVector3::GetYf()
 {

	 return	y;

 }


 double const MyVector3::GetZf()
 {
 
	 return	z;
 
 }