#include "vec4.h"

namespace monolith { namespace math {

	//Constructors 
		vec4::vec4()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}

		vec4::vec4(const float& a, const float& b, const float& c, const float& d)
		{
			x = a;
			y = b;
			z = c;
			w = d;
		}

	//Calculation methods
		vec4 vec4::add(const vec4& other) 
		{
			vec4 temp;
			temp.x = x + other.x;
			temp.y = y + other.y;
			temp.z = z + other.z;
			temp.w = w + other.w;
			return temp;
		}

		vec4 vec4::subtract(const vec4& other)
		{
			vec4 temp;
			temp.x = x - other.x;
			temp.y = y - other.y;
			temp.z = z - other.z;
			temp.w = w - other.w;
			return temp;
		}

		vec4 vec4::multiply(const vec4& other)
		{
			vec4 temp;
			temp.x = x * other.x;
			temp.y = y * other.y;
			temp.z = z * other.z;
			temp.w = w * other.w;
			return temp;
		}

		vec4 vec4::divide(const vec4& other)
		{
			vec4 temp;
			temp.x = x / other.x;
			temp.y = y / other.y;
			temp.z = z / other.z;
			temp.w = w / other.w;
			return temp;
		}

	//Calculation operators
		vec4 vec4::operator + (const vec4& other)
			{
				return add(other);
			}

		vec4 vec4::operator - (const vec4& other)
		{
			return subtract(other);
		}
		
		vec4 vec4::operator * (const vec4& other)
		{
			return multiply(other);
		}

		vec4 vec4::operator / (const vec4& other)
		{
			return divide(other);
		}
		
		vec4& vec4::operator += (const vec4& other)
		{
			*this = *this + other;
			return *this;
		}

		vec4& vec4::operator -= (const vec4& other)
		{
			*this = *this - other;
			return *this;
		}

		vec4& vec4::operator *= (const vec4& other)
		{
			*this = *this * other;
			return *this;
		}

		vec4& vec4::operator /= (const vec4& other)
		{
			*this = *this / other;
			return *this;
		}

	//Comparison operators
		bool vec4::operator == (const vec4& other) 
		{
			return x == other.x && y == other.y && z == other.z;
		}

		bool vec4::operator != (const vec4& other)
		{
			return x != other.x || y != other.y || z != other.z;
		}

	//Output stream operators
		std::ostream& operator << (std::ostream& stream, const vec4& vector)
		{
			stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
			return stream;
		}

} }