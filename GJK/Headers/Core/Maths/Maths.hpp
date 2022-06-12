#pragma once

#include <cmath>

#define PI_NUM 3.141592653589793238462643383279f
#define DEG2RAD PI_NUM/180

namespace Maths
{
	namespace sVector
	{
		class Vector2
		{
		public:
			//VARIABLES
			float x, y;

			//CONSTRUCTORS
			inline Vector2(void) : x(0), y(0) {}
			inline Vector2(float x, float y) : x(x), y(y) {}
			inline Vector2(const Vector2& v) : x(v.x), y(v.y) {}

			//DECONSTRUCTOR
			inline ~Vector2(void) {}

			//EQUALITY OPERATOR
			inline bool operator == (const Vector2& v);
			inline bool operator != (const Vector2& v);

			//ASSINGMENT OPERATOR
			inline Vector2 operator = (const Vector2& v);
			inline Vector2 operator = (const float& f);

			//NEGATE OPERATOR
			inline Vector2 operator - (void);

			//VECTOR2 WITH VECTOR2 OPERATOR
			inline Vector2 operator + (const Vector2& v);
			inline Vector2 operator - (const Vector2& v);
			inline Vector2 operator * (const Vector2& v);
			inline Vector2 operator / (const Vector2& v);

			//SELF WITH VECTOR2 OPERATOR
			inline Vector2 operator += (const Vector2& v);
			inline Vector2 operator -= (const Vector2& v);
			inline Vector2 operator *= (const Vector2& v);
			inline Vector2 operator /= (const Vector2& v);

			//VECTOR2 WITH SCALER OPERATOR
			inline Vector2 operator + (const float& f);
			inline Vector2 operator - (const float& f);
			inline Vector2 operator * (const float& f);
			inline Vector2 operator / (const float& f);

			//SELF WITH SCALER OPERATOR
			inline Vector2 operator += (const float& f);
			inline Vector2 operator -= (const float& f);
			inline Vector2 operator *= (const float& f);
			inline Vector2 operator /= (const float& f);
		};

		class Vector3
		{
		public:
			//VARIABLES
			float x, y, z;

			//CONSTRUCTORS
			inline Vector3(void) : x(0), y(0), z(0) {}
			inline Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
			inline Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
			inline Vector3(const Vector2& v) : x(v.x), y(v.y), z(0) {}
			inline Vector3(const Vector2& v, float z) : x(v.x), y(v.y), z(z) {}

			//DECONSTRUCTOR
			inline ~Vector3(void) {}

			//UTILS
			inline float* ToFloat3();
			inline void Normalise();
			inline float GetMagnitude();
			inline Vector3 crossProduct(const Vector3& v, const Vector3& f);
			inline float dotProduct(const Vector3& v);

			//EQUALITY OPERATOR
			inline bool operator == (const Vector3& v);
			inline bool operator != (const Vector3& v);

			//ASSINGMENT OPERATOR
			inline Vector3 operator = (const Vector3& v);
			inline Vector3 operator = (const float& f);

			//NEGATE OPERATOR
			inline Vector3 operator - (void);

			//VECTOR3 WITH VECTOR3 OPERATOR
			inline Vector3 operator + (const Vector3& v);
			inline Vector3 operator - (const Vector3& v);
			inline Vector3 operator * (const Vector3& v);
			inline Vector3 operator / (const Vector3& v);

			//SELF WITH VECTOR3 OPERATOR
			inline Vector3 operator += (const Vector3& v);
			inline Vector3 operator -= (const Vector3& v);
			inline Vector3 operator *= (const Vector3& v);
			inline Vector3 operator /= (const Vector3& v);

			//VECTOR2 WITH SCALER OPERATOR
			inline Vector3 operator + (const float& f);
			inline Vector3 operator - (const float& f);
			inline Vector3 operator * (const float& f);
			inline Vector3 operator / (const float& f);

			//SELF WITH SCALER OPERATOR
			inline Vector3 operator += (const float& f);
			inline Vector3 operator -= (const float& f);
			inline Vector3 operator *= (const float& f);
			inline Vector3 operator /= (const float& f);
		};

		class Vector4
		{
		public:
			//VARIABLES
			float x, y, z, w;

			//CONSTRUCTORS
			inline Vector4(void) : x(0), y(0), z(0), w(0) {}
			inline Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
			inline Vector4(const Vector4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
			inline Vector4(const Vector3& v) : x(v.x), y(v.y), z(v.z), w(0) {}
			inline Vector4(const Vector3& v, float w) : x(v.x), y(v.y), z(v.z), w(w) {}
			inline Vector4(const Vector2& v) : x(v.x), y(v.y), z(0), w(0) {}
			inline Vector4(const Vector2& v, float z, float w) : x(v.x), y(v.y), z(z), w(w) {}

			//DECONSTRUCTOR
			inline ~Vector4(void) {}

			//UTILS
			inline float* ToFloat4();
			inline void Normalise();
			inline Vector4 Homogenize();
			inline float GetMagnitude();
			inline float dotProduct(const Vector4& v);

			//EQUALITY OPERATOR
			inline bool operator == (const Vector4& v);
			inline bool operator != (const Vector4& v);

			//ASSINGMENT OPERATOR
			inline Vector4 operator = (const Vector4& v);
			inline Vector4 operator = (const float& f);

			//NEGATE OPERATOR
			inline Vector4 operator - (void);

			//VECTOR4 WITH VECTOR4 OPERATOR
			inline Vector4 operator + (const Vector4& v);
			inline Vector4 operator - (const Vector4& v);
			inline Vector4 operator * (const Vector4& v);
			inline Vector4 operator / (const Vector4& v);

			//SELF WITH VECTOR4 OPERATOR
			inline Vector4 operator += (const Vector4& v);
			inline Vector4 operator -= (const Vector4& v);
			inline Vector4 operator *= (const Vector4& v);
			inline Vector4 operator /= (const Vector4& v);

			//VECTOR2 WITH SCALER OPERATOR
			inline Vector4 operator + (const float& f);
			inline Vector4 operator - (const float& f);
			inline Vector4 operator * (const float& f);
			inline Vector4 operator / (const float& f);

			//SELF WITH SCALER OPERATOR
			inline Vector4 operator += (const float& f);
			inline Vector4 operator -= (const float& f);
			inline Vector4 operator *= (const float& f);
			inline Vector4 operator /= (const float& f);
		};
	}
}

#include "Maths.inl"