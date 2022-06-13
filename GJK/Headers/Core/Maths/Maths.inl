#include "Maths.hpp"

/************************\
 *-------VECTOR_2-------*
\************************/
#pragma region Vector2
//EQUALITY OPERATOR
inline bool Maths::sVector::Vector2::operator==(const Vector2& v)
{
	return (x == v.x) && (y == v.y);
}
inline bool Maths::sVector::Vector2::operator != (const Vector2& v)
{
	return (x != v.x) || (y != v.y);
}
//ASSINGMENT OPERATOR
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator = (const Vector2& v)
{
	x = v.x;
	y = v.y;
	return *this;
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator = (const float& f)
{
	x = f;
	y = f;
	return *this;
}
//NEGATE OPERATOR
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator - (void)
{
	x = -x;
	y = -y;
	return *this;
}
//VECTOR2 WITH VECTOR2 OPERATOR
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator + (const Vector2& v) 
{
	return Vector2(x + v.x, y + v.y);
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator - (const Vector2& v)
{
	return Vector2(x - v.x, y - v.y);
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator * (const Vector2& v)
{
	return Vector2(x * v.x, y * v.y);
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator / (const Vector2& v)
{
	return Vector2(x / v.x, y / v.y);
}
//SELF WITH VECTOR2 OPERATOR
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator += (const Vector2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator -= (const Vector2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator *= (const Vector2& v)
{
	x *= v.x;
	y *= v.y;
	return *this;
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator /= (const Vector2& v)
{
	x /= v.x;
	y /= v.y;
	return *this;
}
//VECTOR2 WITH SCALER OPERATOR
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator + (const float& f)
{
	return Vector2(x + f, y + f);
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator - (const float& f)
{
	return Vector2(x - f, y - f);
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator * (const float& f)
{
	return Vector2(x * f, y * f);
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator / (const float& f)
{
	return Vector2(x / f, y / f);
}
//SELF WITH SCALER OPERATOR
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator += (const float& f)
{
	x += f;
	y += f;
	return *this;
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator -= (const float& f)
{
	x -= f;
	y -= f;
	return *this;
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator *= (const float& f)
{
	x *= f;
	y *= f;
	return *this;
}
inline Maths::sVector::Vector2 Maths::sVector::Vector2::operator /= (const float& f)
{
	x /= f;
	y /= f;
	return *this;
}
#pragma endregion Vector2
/************************\
 *-------VECTOR_3-------*
\************************/
#pragma region Vector3
//UTILS
inline float* Maths::sVector::Vector3::ToFloat3()
{
	return &x;
}
inline void Maths::sVector::Vector3::Normalize()
{
	x /= GetMagnitude();
	y /= GetMagnitude();
	z /= GetMagnitude();
}
inline float Maths::sVector::Vector3::GetMagnitude()
{
	return (float)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::crossProduct(const Vector3& v, const Vector3& f)
{
	return Vector3(v.y * f.z - v.z * f.y, v.z * f.x - v.x * f.z, v.x * f.y - v.y * f.x);
}
inline float Maths::sVector::Vector3::dotProduct(const Vector3& v)
{
	return x * v.x + y * v.y + z * v.z;
}
//EQUALITY OPERATOR
inline bool Maths::sVector::Vector3::operator == (const Vector3& v)
{
	return (x == v.x) && (y == v.y) && (z == v.z);
}
inline bool Maths::sVector::Vector3::operator != (const Vector3& v)
{
	return (x != v.x) || (y != v.y) || (z != v.z);
}
//ASSINGMENT OPERATOR
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator = (const Vector3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator = (const float& f)
{
	x = f;
	y = f;
	z = f;
	return *this;
}
//NEGATE OPERATOR
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator - (void)
{
	x = -x;
	y = -y;
	z = -z;
	return *this;
}
//VECTOR3 WITH VECTOR3 OPERATOR
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator + (const Vector3& v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator - (const Vector3& v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator * (const Vector3& v)
{
	return Vector3(x * v.x, y * v.y, z * v.z);
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator / (const Vector3& v)
{
	return Vector3(x / v.x, y / v.y, z / v.z);
}
//SELF WITH VECTOR3 OPERATOR
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator += (const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator -= (const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator *= (const Vector3& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator /= (const Vector3& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}
//VECTOR2 WITH SCALER OPERATOR
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator + (const float& f)
{
	return Vector3(x + f, y + f, z + f);
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator - (const float& f)
{
	return Vector3(x - f, y - f, z - f);
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator * (const float& f)
{
	return Vector3(x * f, y * f, z * f);
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator / (const float& f)
{
	return Vector3(x / f, y / f, z / f);
}
//SELF WITH SCALER OPERATOR
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator += (const float& f)
{
	x += f;
	y += f;
	z += f;
	return *this;
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator -= (const float& f)
{
	x -= f;
	y -= f;
	z -= f;
	return *this;
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator *= (const float& f)
{
	x *= f;
	y *= f;
	z *= f;
	return *this;
}
inline Maths::sVector::Vector3 Maths::sVector::Vector3::operator /= (const float& f)
{
	x /= f;
	y /= f;
	z /= f;
	return *this;
}
//-------------------------
inline Maths::sVector::Vector3  Maths::sVector::Vector3::Normalize(const Vector3& v)
{
	Vector3 temp(v);
	float valueOfMagnitude = temp.GetMagnitude();
	return Vector3(temp.x / valueOfMagnitude, temp.y / valueOfMagnitude, v.z / valueOfMagnitude);
}
//-------------------------
#pragma endregion Vector3
/************************\
 *-------VECTOR_4-------*
\************************/
#pragma region Vector4
//UTILS
float* Maths::sVector::Vector4::ToFloat4()
{
	return &x;
}
void Maths::sVector::Vector4::Normalise()
{
	x /= GetMagnitude();
	y /= GetMagnitude();
	z /= GetMagnitude();
	w /= GetMagnitude();
}
Maths::sVector::Vector4 Maths::sVector::Vector4::Homogenize()
{
	if (w == 0)
		return Vector4(x, y, z, w);
	return Vector4(x / w, y / w, z / w, 1);
}
float Maths::sVector::Vector4::GetMagnitude()
{
	return (float)sqrt(pow(x / w, 2) + pow(y / w, 2) + pow(z / w, 2));
}
float Maths::sVector::Vector4::dotProduct(const Vector4& v)
{
	return v.x * x + v.y * y + v.z * z + v.w * w;
}

//EQUALITY OPERATOR
inline bool Maths::sVector::Vector4::operator == (const Vector4& v)
{
	return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
}
inline bool Maths::sVector::Vector4::operator != (const Vector4& v)
{
	return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w);
}

//ASSINGMENT OPERATOR
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator = (const Vector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator = (const float& f)
{
	x = f;
	y = f;
	z = f;
	w = f;
	return *this;
}

//NEGATE OPERATOR
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator - (void)
{
	x = -x;
	y = -y;
	z = -z;
	w = -w;
	return *this;
}

//VECTOR4 WITH VECTOR4 OPERATOR
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator + (const Vector4& v)
{
	return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator - (const Vector4& v)
{
	return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator * (const Vector4& v)
{
	return Vector4(x * v.x, y * v.y, z * v.z, w * v.w);
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator / (const Vector4& v)
{
	return Vector4(x / v.x, y / v.y, z / v.z, w / v.w);
}

//SELF WITH VECTOR4 OPERATOR
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator += (const Vector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator -= (const Vector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator *= (const Vector4& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
	return *this;
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator /= (const Vector4& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;
	return *this;
}

//VECTOR2 WITH SCALER OPERATOR
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator + (const float& f)
{
	return Vector4(x + f, y + f, z + f, w + f);
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator - (const float& f)
{
	return Vector4(x - f, y - f, z - f, w - f);
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator * (const float& f)
{
	return Vector4(x * f, y * f, z * f, w * f);
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator / (const float& f)
{
	return Vector4(x / f, y / f, z / f, w / f);
}

//SELF WITH SCALER OPERATOR
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator += (const float& f)
{
	x += f;
	y += f;
	z += f;
	w += f;
	return *this;
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator -= (const float& f)
{
	x -= f;
	y -= f;
	z -= f;
	w -= f;
	return *this;
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator *= (const float& f)
{
	x *= f;
	y *= f;
	z *= f;
	w *= f;
	return *this;
}
inline Maths::sVector::Vector4 Maths::sVector::Vector4::operator /= (const float& f)
{
	x /= f;
	y /= f;
	z /= f;
	w /= f;
	return *this;
}
#pragma endregion Vector4