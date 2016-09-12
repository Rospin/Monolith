#pragma once
#include <iostream>

namespace monolith { namespace math {

	struct vec4 
	{
		float x, y, z, w;

		vec4();
		vec4(const float& a, const float& b, const float& c, const float& d);

		//Methods
			vec4 add(const vec4& other);
			vec4 subtract(const vec4& other);
			vec4 multiply(const vec4& other);
			vec4 divide(const vec4& other);

		//Claculation operators
			vec4 operator + (const vec4& other);
			vec4 operator - (const vec4& other);
			vec4 operator * (const vec4& other);
			vec4 operator / (const vec4& other);

			vec4& operator += (const vec4& other);
			vec4& operator -= (const vec4& other);
			vec4& operator *= (const vec4& other);
			vec4& operator /= (const vec4& other);

		//Comparison operators
			bool operator == (const vec4& other);
			bool operator != (const vec4& other);
		
		//Output stream operator
			friend std::ostream& operator << (std::ostream& stream, const vec4& vector);
	};

} }