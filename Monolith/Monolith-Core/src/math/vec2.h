#pragma once
#include <iostream>

namespace monolith { namespace math {

	struct vec2 
	{
		float x, y;

		vec2();
		vec2(float a, float b);

		//Methods
			vec2 add(const vec2& other);
			vec2 subtract(const vec2& other);
			vec2 multiply(const vec2& other);
			vec2 divide(const vec2& other);

		//Claculation operators
			vec2 operator + (const vec2& other);
			vec2 operator - (const vec2& other);
			vec2 operator * (const vec2& other);
			vec2 operator / (const vec2& other);

			vec2& operator += (const vec2& other);
			vec2& operator -= (const vec2& other);
			vec2& operator *= (const vec2& other);
			vec2& operator /= (const vec2& other);

		//Comparison operators
			bool operator == (const vec2& other);
			bool operator != (const vec2& other);
		
		//Output stream operator
			friend std::ostream& operator << (std::ostream& stream, const vec2& vector);
	};

} }