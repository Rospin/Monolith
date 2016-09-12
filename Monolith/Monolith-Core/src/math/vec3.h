#pragma once
#include <iostream>

namespace monolith { namespace math {

	struct vec3 
	{
		float x, y, z;

		vec3();
		vec3(const float& a, const float& b, const float& c);

		//Methods
			vec3 add(const vec3& other);
			vec3 subtract(const vec3& other);
			vec3 multiply(const vec3& other);
			vec3 divide(const vec3& other);

		//Claculation operators
			vec3 operator + (const vec3& other);
			vec3 operator - (const vec3& other);
			vec3 operator * (const vec3& other);
			vec3 operator / (const vec3& other);

			vec3& operator += (const vec3& other);
			vec3& operator -= (const vec3& other);
			vec3& operator *= (const vec3& other);
			vec3& operator /= (const vec3& other);

		//Comparison operators
			bool operator == (const vec3& other);
			bool operator != (const vec3& other);
		
		//Output stream operator
			friend std::ostream& operator << (std::ostream& stream, const vec3& vector);
	};

} }