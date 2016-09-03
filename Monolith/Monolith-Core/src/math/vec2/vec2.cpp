#include "vec2.h"

namespace monolith { namespace math {

	//Constructors 
		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}

		vec2::vec2(float a, float b)
		{
			x = a;
			y = b;
		}

	//Calculation methods
		vec2& vec2::add(const vec2& other) 
		{
			x += other.x;
			y += other.y;
	
			return *this;
		}

		vec2& vec2::subtract(const vec2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		vec2& vec2::multiply(const vec2& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		vec2& vec2::divide(const vec2& other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

	//Calculation operators
		vec2 vec2::operator + (const vec2& other)
			{
				return add(other);
			}

		vec2 vec2::operator - (const vec2& other)
		{
			return subtract(other);
		}
		
		vec2 vec2::operator * (const vec2& other)
		{
			return multiply(other);
		}

		vec2 vec2::operator / (const vec2& other)
		{
			return divide(other);
		}
		
		vec2& vec2::operator += (const vec2& other)
		{
			*this = *this + other;
			return *this;
		}

		vec2& vec2::operator -= (const vec2& other)
		{
			*this = *this - other;
			return *this;
		}

		vec2& vec2::operator *= (const vec2& other)
		{
			*this = *this * other;
			return *this;
		}

		vec2& vec2::operator /= (const vec2& other)
		{
			*this = *this / other;
			return *this;
		}

	//Comparison operators
		bool vec2::operator == (const vec2& other) 
		{
			return x == other.x && y == other.y;
		}

		bool vec2::operator != (const vec2& other)
		{
			return x != other.x || y != other.y;
		}

	//Output stream operators
		std::ostream& operator << (std::ostream& stream, const vec2& vector)
		{
			stream << "vec2: (" << vector.x << ", " << vector.y << ")";
			return stream;
		}

} }