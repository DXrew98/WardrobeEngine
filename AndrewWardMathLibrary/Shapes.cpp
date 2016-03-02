#include "vmmath.h"

ConvexHull operator*(const mat3 & matrix, const ConvexHull & shape)	{ return matrix * shape; }

Ray operator*(const mat3 & matrix, const Ray & shape)				{ return matrix * shape; }

Plane operator*(const mat3 & matrix, const Plane & shape)			{ return matrix * shape; }

Circle operator*(const mat3 & matrix, const Circle & shape)			{ return matrix * shape; }

AABB operator*(const mat3 & matrix, const AABB & shape)				{ return matrix * shape; }
