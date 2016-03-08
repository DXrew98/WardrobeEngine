#include "VMMath.h"

float pointPlaneDistance(const Circle &circle, const Plane & plane)
{
	return (dot(plane.normal, (circle.pos - plane.pos)));
}
float rayPlaneDistance(const Ray & ray, const Plane & plane)
{
	return (dot(plane.normal, (ray.pos - plane.pos)) / -dot(plane.normal, ray.dir));
}

CollisionData iTest(const AABB & rectA, const AABB & rectB)
{
	CollisionData cd = { false, INFINITY };
	if (rectA.max.x >= rectB.min.x && rectB.max.x >= rectA.min.x &&
		rectA.max.y >= rectB.min.y && rectB.max.y >= rectA.min.x) {
		return cd = { true }; }
	return cd;
}
CollisionData iTest(const AABB & rect, const Circle & circle)
{
	CollisionData cd = { false };
	vec2 cP = clamp(circle.pos, rect.min, rect.max);
	if ((circle.pos - cP).mag() - circle.radius > 0) {cd = { true }; }
	return cd;
}
CollisionData iTest(const AABB & rect, const Ray & ray)
{
	CollisionData cd = { false };
	

	// Min/Max along the X-Axis
	Plane s1p1  = Plane{ rect.max(), RIGHT	};
	Plane s1p2  = Plane{ rect.min(), LEFT	};
	float t11   = rayPlaneDistance(ray, s1p1); // Right
	float t12   = rayPlaneDistance(ray, s1p2); // Left
	float t1min = std::fminf(t11, t12);
	float t1max = std::fmaxf(t11, t12);
	vec2  n1    = (t11 < t12) ? vec2 RIGHT : vec2 LEFT;

	// Min/Max along the Y-Axis
	Plane s2p1  = Plane{ rect.max(), UP		};
	Plane s2p2  = Plane{ rect.min(), DOWN	};
	float t21   = rayPlaneDistance(ray, s2p1);
	float t22   = rayPlaneDistance(ray, s2p2);
	float t2min = std::fminf(t21, t22);
	float t2max = std::fmaxf(t21, t22);
	vec2  n2 = (t21 < t22) ? vec2 UP : vec2 DOWN;
	
	float tmin  = std::fmaxf(t2min, t1min);
	float tmax  = std::fminf(t2max, t1max);
	
	cd.collsionNormal   = (t1min > t2min) ? n1 : n2;
	cd.penetrationDepth = ray.len - tmin; 
	cd.inOverlap		= cd.penetrationDepth >= 0 && tmin <= tmax && tmin > 0;

	return cd;
}
CollisionData iTest(const AABB & rect, const Plane & plane)
{
	CollisionData cd = { false };

	vec2 localDis = rect.pos - plane.pos;
	float rectPlaneTest = rect.halfPoint.x * dot(plane.normal, UP) + rect.halfPoint.y * dot(plane.normal, UP);

	if (dot(plane.normal, localDis) <= rectPlaneTest) { cd = { true }; }

	return cd;
}

CollisionData iTest(const Circle & circleA, const Circle & circleB)
{
	CollisionData cd = { false };
	float dist = pow(circleA.pos.x - circleB.pos.x, 2) + pow(circleA.pos.y - circleB.pos.y, 2);
	float radius = pow(circleA.radius + circleB.radius, 2);
	if (dist <= radius) { cd = { true }; }
	return cd;
}
CollisionData iTest(const Circle & circle, const Ray & ray)
{
	CollisionData cd = { false };
	float crDis = dot(circle.pos, ray.pos);

	float clampedPoint = clamp(crDis, 0, ray.len);
	vec2 closestPoint = ray.pos + ray.dir * clampedPoint;

	if (dot((circle.pos - closestPoint), (circle.pos - closestPoint)) <= circle.radius * circle.radius) { cd = { true }; }
	return cd;
}
CollisionData iTest(const Circle & circle, const Plane & plane)
{
	CollisionData cd = { false };
	float lhs = dot(plane.normal, (circle.pos - plane.pos));
	float rhs = circle.radius;

	if (lhs <= rhs) { cd = { true, lhs }; }
	return cd;
}

CollisionData iTest(const Ray & ray, const Plane & plane)
{
	CollisionData cd = { false };

	vec2 rayLength = ray.len * ray.dir;
	vec2 localDis = ray.pos - plane.pos;
	float rayPlaneTest = (dot(plane.normal, localDis) / dot(plane.normal, rayLength) * -1);

	if (dot(plane.normal, rayLength) * -1 > 0) { return cd; }
	else if (rayPlaneTest >= 0 && rayPlaneTest <= 12) { cd = { true }; }
	return cd;
}

CollisionData iTest(const ConvexHull & chullA, const ConvexHull & chullB)
{
	return CollisionData();
}
CollisionData iTest(const ConvexHull & chull, const Circle & circle)
{
	return CollisionData();
}
CollisionData iTest(const ConvexHull & chull, const Ray & ray)
{
	return CollisionData();
}
CollisionData iTest(const ConvexHull & chull, const Plane & plane)
{
	return CollisionData();
}
CollisionData iTest(const ConvexHull & chull, const AABB & rect)
{
	return CollisionData();
}
