#include "Transform.h"

Transform::Transform()
	: e_parent(nullptr),
	scale ({1, 1}),
	pos({0 ,0}),
	angle(0) {}

Transform::~Transform(){
	auto t = e_children;
	for each(Transform *child in t)
		child->setParent(e_parent);
	setParent(nullptr);
}

mat3 Transform::getGlobalTransform() const{
	return
		(e_parent ? e_parent->getGlobalTransform() : mat3::identity())

		* andMath::translate(pos)
		* andMath::scale(scale)
		* andMath::rotate(angle);
	}

void Transform::setParent(Transform *a_parent){
	if (e_parent)
		e_parent->e_children.remove(this);

	if (e_parent)
		a_parent->e_children.push_front(this);

	e_parent = a_parent
}

void Transform::setPosition(const vec2 &a_pos){
	pos = a_pos;
}

void Transform::setScale(const vec2 &a_scale){
	scale = a_scale;
}

void Transform::setAngle(float a_angle){
	angle = a_angle;
}

vec2 Transform::getPosition() const{
	return pos;
}

vec2 Transform::getScale() const{
	return scale;
}

float Transform::getAngle() const{
	return angle;
}

vec2 Transform::getRight() const{
	return vec2::fromAngle(angle);
}

vec2 Transform::getUp() const{
	return andMath::perp(vec2::fromAngle(angle));
}
