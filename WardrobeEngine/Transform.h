#pragma once
#include "MathDependancies.h"

class Transform : public GCData<Transform> {

	Transform *e_parent;
	std::list <Transform*> e_children;
	vec2 pos, scale;
	float angle;

public:

	Transform();
	~Transform();

	mat3 getGlobalTransform() const;

	void setParent	(Transform *a_parent);
	void setPosition(const vec2 &a_pos);
	void setScale	(const vec2 &a_scale);
	void setAngle	(float a_angle);

	vec2  getPosition()		const;
	vec2  getScale	 ()		const;
	float getAngle	 ()		const;

	vec2 getRight	 ()		const;
	vec2 getUp		 ()		const;
};