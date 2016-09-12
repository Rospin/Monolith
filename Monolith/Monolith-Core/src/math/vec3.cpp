#include "vec3.h"

namespace monolith { namespace math {

	//Constructors 
		vec3::vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float& a, const float& b, const float& c)
		{
			x = a;
			y = b;
			z = c;
		}

	//Calculation methods
		vec3 vec3::add(const vec3& other) 
		{
			vec3 temp;
			temp.x = x + other.x;
			temp.y = y + other.y;
			temp.z = z + other.z;
			return temp;
		}

		vec3 vec3::subtract(const vec3& other)
		{
			vec3 temp;
			temp.x = x - other.x;
			temp.y = y - other.y;
			temp.z = z - other.z;
			return temp;
		}

		vec3 vec3::multiply(const vec3& other)
		{
			vec3 temp;
			temp.x = x * other.x;
			temp.y = y * other.y;
			temp.z = z * other.z;
			return temp;
		}

		vec3 vec3::divide(const vec3& other)
		{
			vec3 temp;
			temp.x = x / other.x;
			temp.y = y / other.y;
			temp.z = z / other.z;
			return temp;
		}

	//Calculation operators
		vec3 vec3::operator + (const vec3& other)
			{
				return add(other);
			}

		vec3 vec3::operator - (const vec3& other)
		{
			return subtract(other);
		}
		
		vec3 vec3::operator * (const vec3& other)
		{
			return multiply(other);
		}

		vec3 vec3::operator / (const vec3& other)
		{
			return divide(other);
		}
		
		vec3& vec3::operator += (const vec3& other)
		{
			*this = *this + other;
			return *this;
		}

		vec3& vec3::operator -= (const vec3& other)
		{
			*this = *this - other;
			return *this;
		}

		vec3& vec3::operator *= (const vec3& other)
		{
			*this = *this * other;
			return *this;
		}

		vec3& vec3::operator /= (const vec3& other)
		{
			*this = *this / other;
			return *this;
		}

	//Comparison operators
		bool vec3::operator == (const vec3& other) 
		{
			return x == other.x && y == other.y && z == other.z;
		}

		bool vec3::operator != (const vec3& other)
		{
			return x != other.x || y != other.y || z != other.z;
		}

	//Output stream operators
		std::ostream& operator << (std::ostream& stream, const vec3& vector)
		{
			stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		}

} }