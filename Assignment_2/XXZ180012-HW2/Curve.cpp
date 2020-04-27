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
	this->control_points_pos = {
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

void Curve::calculate_curve()
{
	int len = this->control_points_pos.size();
	for (int i = 0; i < this->control_points_pos.size(); i++) {
		glm::vec3 P0 = this->control_points_pos[(len + i - 1) % len];
		glm::vec3 P1 = this->control_points_pos[(len + i) % len];
		glm::vec3 P2 = this->control_points_pos[(len + i + 1) % len];
		glm::vec3 P3 = this->control_points_pos[(len + i + 2) % len];
		for (int i = 1; i <= 200; i++) {
			double u = (double)i / (double)200;
			double x = calculate(u, P0[0], P1[0], P2[0], P3[0]);
			double y = calculate(u, P0[1], P1[1], P2[1], P3[1]);
			double z = calculate(u, P0[2], P1[2], P2[2], P3[2]);
			this->curve_points_pos.push_back({x, y, z});
		}
	}

	//this->curve_points_pos = {
	//	{ 0.0, 8.5, -2.0 },
	//	{ -3.0, 11.0, 2.3 },
	//	{ -6.0, 8.5, -2.5 },
	//	{ -4.0, 5.5, 2.8 },
	//	{ 1.0, 2.0, -4.0 },
	//	{ 4.0, 2.0, 3.0 },
	//	{ 7.0, 8.0, -2.0 },
	//	{ 3.0, 10.0, 3.7 }
	//};
}
