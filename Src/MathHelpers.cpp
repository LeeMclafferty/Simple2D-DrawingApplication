#include "MathHelpers.h"
#include <cmath>

const float MathHelpers::PI = std::acos(-1);

float MathHelpers::getAngle(float x1, float y1, float x2, float y2)
{
	// Calculate the difference in coordinates
	double deltaX = x2 - x1;
	double deltaY = y2 - y1;

	// Calculate the angle in radians
	double angleRadians = atan2(deltaY, deltaX);

	// Convert radians to degrees
	float angleDegrees = angleRadians * 180 / PI;

	return angleDegrees;
}
