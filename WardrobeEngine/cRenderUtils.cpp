#include "cRenderUtils.h"
#include "sfwdraw.h"

void drawMatrix(const mat3 & matrix)
{
	vec2 pos	= matrix[2].xy;
	vec2 up		= matrix[1].xy;
	vec2 right	= matrix[0].xy;

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x,    up.y,    GREEN);
}

void drawVector(const mat3 & matrix, const vec2 & vector, unsigned TINT)
{
}

void drawPLane(const Plane & plane, unsigned TINT = BLUE)
{
	sfw::drawLine(plane.pos.x, plane.pos.y, (plane.pos.x + plane.normal.x) * 10, (plane.pos.y + plane.normal.y) * 10, TINT);
	sfw::drawLine(plane.pos.x - (plane.normal.perp().x * 10), plane.pos.y - (plane.normal.perp().y * 10), plane.pos.x, plane.pos.y, TINT);
}

void drawAABB(const AABB & aabb, unsigned TINT = BLUE)
{
	sfw::drawLine(aabb.min().x, aabb.min().y, aabb.max().x, aabb.min().y, TINT);
	sfw::drawLine(aabb.min().x, aabb.max().y, aabb.max().x, aabb.max().y, TINT);
	sfw::drawLine(aabb.max().x, aabb.min().y, aabb.max().x, aabb.max().y, TINT);
	sfw::drawLine(aabb.min().x, aabb.min().y, aabb.min().x, aabb.max().y, TINT);
}

void drawCircle(const Circle & circle, unsigned TINT = BLUE)
{
	sfw::drawCircle(circle.pos.x, circle.pos.y, 5, TINT = BLUE);
}

void drawRay(const Ray & ray, unsigned TINT = BLUE)
{
	sfw::drawLine(ray.pos.x, ray.pos.y, ray.dir.x * ray.len, ray.dir.y * ray.len, TINT);
}

void drawTransform(const Transform & trans)
{
	vec2 temp = { 30, 30 };
	drawMatrix(trans.getGlobalTransform() * andMath::scale(temp));
}

void drawRigidBody(const Transform & trans, const Rigidbody & rb)
{
	vec2 pos = trans.getPosition();
	vec2 acc = pos + rb.acc;
	vec2 vel = pos + rb.vel;

	sfw::drawLine(pos.x, pos.y, acc.x, acc.y, CYAN);
	sfw::drawLine(pos.x, pos.y, vel.x, vel.y, YELLOW);
}

void drawCollider(const Transform & trans, const Collider & co)
{
	drawCircle(trans.getGlobalTransform() * co.circle, BLUE);
}
