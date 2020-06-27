#pragma once
#include <valarray>
#include <string>
#include <map>


using vec = std::valarray<double>;
class equation
{
public:
	int NumPoint;
	double Lx;
	double dt;
	double h;
	double Hi;
	double Ro;
	double DeltaP;
	double Nu;
    
	std::map<std::string, double> consts;
	vec T;
	vec dT;
	vec v;
	vec dv;
	
	equation(int NumPoint, double L, std::map<std::string, double> consts);
	void SetInitial(vec T, vec v);
	void step();
	void write(std::string adr);
	~equation();
};



