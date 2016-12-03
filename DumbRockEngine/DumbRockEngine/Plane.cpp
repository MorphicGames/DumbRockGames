#include "Plane.h"

namespace DRE
{
	Plane::Plane()
		: a(0.0f)
		, b(0.0f)
		, c(0.0f)
		, d(0.0f)
	{

	}

	Plane::Plane(F32 a, F32 b, F32 c, F32 d, glm::vec3& point)
	{
		this->point = point;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}

	Plane::Plane(glm::vec3& pointA, glm::vec3& pointB, glm::vec3& pointC)
	{
		glm::vec3 v1 = pointB - pointA;
		glm::vec3 v2 = pointC - pointA;

		glm::vec3 normal = glm::normalize(glm::cross(v1, v2));

		a = normal[0];
		b = normal[1];
		c = normal[2];
		d = -(a * pointA[0] + b * pointA[1] + c * pointA[2]);
		point = pointA;
	}

	glm::vec3 Plane::GetNormal() const
	{
		return glm::vec3(a, b, c);
	}

	F32 Plane::GetDistance() const
	{
		return d;
	}

	F32 Plane::SignedDistance(glm::vec3& point)
	{
		glm::vec3 normal = GetNormal();
		return glm::dot(normal, point) + d;
	}

	Plane& Plane::operator=(const Plane& other)
	{
		a = other.a;
		b = other.b;
		c = other.c;
		d = other.d;
		return *this;
	}

	bool operator==(const Plane& a, const Plane& b)
	{
		return (a.a == b.a) && (a.b == b.b) && (a.c == b.c) && (a.d == b.d);
	}

	bool operator!=(const Plane& a, const Plane& b)
	{
		return !((a.a == b.a) && (a.b == b.b) && (a.c == b.c) && (a.d == b.d));
	}

}