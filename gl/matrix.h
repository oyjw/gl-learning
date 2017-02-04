#pragma once
#include <cstring>
class Matrix4
{
public:
	Matrix4() 
	{
		memset(values, 0, sizeof(values));
	}
	void mul(float in_vec[4], float* out_vec)
	{
		out_vec[0] = values[0] * in_vec[0] + values[4] * in_vec[1] + values[8] * in_vec[2] + values[12] * in_vec[3];
		out_vec[1] = values[1] * in_vec[0] + values[5] * in_vec[1] + values[9] * in_vec[2] + values[13] * in_vec[3];
		out_vec[2] = values[2] * in_vec[0] + values[6] * in_vec[1] + values[10] * in_vec[2] + values[14] * in_vec[3];
		out_vec[3] = values[3] * in_vec[0] + values[7] * in_vec[1] + values[11] * in_vec[2] + values[15] * in_vec[3];
	}
	float values[16];
};