#include "Curve.h"

Curve::Curve()
{
}

Curve::~Curve()
{
}

double calculate(double u, double P0, double P1, double P2, double P3) {
	double point;
	point = u * u * u * ((-1) * P0 + 3 * P1 - 3 * P2 + P3) / 2;
	point += u * u * (2 * P0 - 5 * P1 + 4 * P2 - P3) / 2;
	point += u * ((-1) * P0 + P2) / 2;
	point += P1;
	return point;
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
	//this->curve_points_pos = {
	//{ 0.0, 8.5, -2.0 },
	//{ -3.0, 11.0, 2.3 },
	//{ -6.0, 8.5, -2.5 },
	//{ -4.0, 5.5, 2.8 },
	//{ 1.0, 2.0, -4.0 },
	//{ 4.0, 2.0, 3.0 },
	//{ 7.0, 8.0, -2.0 },
	//{ 3.0, 10.0, 3.7 }
	//};
	int len = this->control_points_pos.size();
	for (int i = 0; i < this->control_points_pos.size(); i++) {
		glm::vec3 P0 = this->control_points_pos[(len + i - 1) % len];
		glm::vec3 P1 = this->control_points_pos[(len + i) % len];
		glm::vec3 P2 = this->control_points_pos[(len + i + 1) % len];
		glm::vec3 P3 = this->control_points_pos[(len + i + 2) % len];
		for (int i = 0; i < 200; i++) {
			double u = (double)i / (double)200;
			double x = calculate(u, P0[0], P1[0], P2[0], P3[0]);
			double y = calculate(u, P0[1], P1[1], P2[1], P3[1]);
			double z = calculate(u, P0[2], P1[2], P2[2], P3[2]);
			this->curve_points_pos.push_back({ x, y, z });
		}
	}
}