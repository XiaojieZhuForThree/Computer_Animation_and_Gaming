#include "Curve.h"

Curve::Curve()
{
}

Curve::~Curve()
{
}

void Curve::init()
{
	this->control_points_pos = 
	{
		{ 0.0, 8.5, -2.0 },
		{ -3.0, 11.0, 2.3 },
		{ -6.0, 8.5, -2.5 },
		{ -4.0, 5.5, 2.8 },
		{ 1.0, 2.0, -4.0 },
		{ 4.0, 2.0, 3.0 },
		{ 7.0, 8.0, -2.0 },
		{ 3.0, 10.0, 3.7 }
	};
	calculate_curve();
	
	this->control_points_quaternion = {
		{0.13964   , 0.0481732 , 0.831429 , 0.541043 , },
		{0.0509038 , -0.033869 , -0.579695, 0.811295 , },
		{-0.502889 , -0.366766 , 0.493961 , 0.592445 , },
		{-0.636    , 0.667177  , -0.175206, 0.198922 , },
		{0.693492  , 0.688833  , -0.152595, -0.108237, },
		{0.752155  , -0.519591 , -0.316988, 0.168866 , },
		{0.542054  , 0.382705  , 0.378416 , 0.646269 , },
		{0.00417342, -0.0208652, -0.584026, 0.810619   }
	};
}

void Curve::calculate_curve()
{
	this->curve_points_pos = {
	{ 0.0, 8.5, -2.0 },
	{ -3.0, 11.0, 2.3 },
	{ -6.0, 8.5, -2.5 },
	{ -4.0, 5.5, 2.8 },
	{ 1.0, 2.0, -4.0 },
	{ 4.0, 2.0, 3.0 },
	{ 7.0, 8.0, -2.0 },
	{ 3.0, 10.0, 3.7 }
	};
}