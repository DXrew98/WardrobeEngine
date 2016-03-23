#include "Time.h"
#include "sfwdraw.h"

float Time::getTotalTime()
{
	INIT_ASSERT(Time);
	return sfw::getTime();
}

float Time::getDeltaTime()
{
	INIT_ASSERT(Time);

	float dT = sfw::getDeltaTime();

#ifdef DEBUG
	// cap delta time to 1 second
	if (dT > 1.0f)
	{
		dT = 1.0f;
	}
#endif

	return sfw::getDeltaTime();
}
