#pragma once

bool fequals(float lhs, float rhs);
//curving
float deg2rad(float deg);
float rad2deg(float rad);
float linearHalf(float x);
float growFast(float x);
float growSlow(float x);
float HardAngle(float x);
float bounce(float x);
//curve curve
float lerp(float start, float end, float alpha);
float quadBezier(float start, float mid, float end, float alpha);
float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha);
float cardinalSpline(float start, float mid, float end,float tight, float alpha);
float  catRomSpline(float start, float mid, float end, float alpha);