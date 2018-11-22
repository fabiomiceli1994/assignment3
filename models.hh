#ifndef modelS_HH
#define modelS_HH

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

struct Test
{
  unsigned modelNumber_;
  double l = -0.1;
  double f(double t,const double &y) const
  {
    if(modelNumber_==1) //first assignment equation
    {
      return (1 - cos(t)*(cos(t) - 1) - y*y);
    }else if(modelNumber_==2) //second assignment equation
    {
      return (1 - cos(t)*(cos(t) - exp(l*t)) - exp(-2*l*t)*y*y + l*y); //f(t,y) = -y . So we have the equation y' = f(t,y) = -y
    }else if(modelNumber_==3) //test case
    {
      return -y; //f(t,y) = -y . So we have the equation y' = f(t,y) = -y
    }else
    { //exit with an appropriate warning
      std::cout << "No model defined for this choice of model index. Exiting." << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  double df(double t,const double &y) const //first derivative of f wrt to y
  {
    if(modelNumber_==1) //first assignment equation
    {
      return -2*y;
    }else if(modelNumber_==2) //second assignment equation
    {
      return ( -2*y*exp(-2*l*t) + l );
    }else if(modelNumber_==3) //test case
    {
      return -1;
    }else
    { //exit with an appropriate warning
      std::cout << "No model defined for this choice of model index. Exiting." << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  double T() const //maximum time of integration
  {
    if(modelNumber_==1) //first assignment equation
    {
      return 2*M_PI;
    }else if(modelNumber_==2) //second assignment equation
    {
      return 10.;
    }else if(modelNumber_==3) //test case
    {
      return 1.;
    }else
    { //exit with an appropriate warning
      std::cout << "No model defined for this choice of model index. Exiting." << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  double y0() const //initial condition
  {
    if(modelNumber_==1 || modelNumber_==2)
    {
      return 0.;
    }else if(modelNumber_==3)
    {
      return 1.;
    }else
    { //exit with an appropriate warning
      std::cout << "No model defined for this choice of model index. Exiting." << std::endl;
      exit(EXIT_FAILURE);
    }

  }
  double exact(double t) const //exacr solution for this particular case
  {
    if(modelNumber_==1) //first assignment equation
    {
      return sin(t);
    }else if(modelNumber_==2) //second assignment equation
    {
      return exp(l*t)*sin(t);
    }else if(modelNumber_==3) //test case
    {
      return exp(-t); //f(t,y) = -y . So we have the equation y' = f(t,y) = -y
    }else
    { //exit with an appropriate warning
      std::cout << "No model defined for this choice of model index. Exiting." << std::endl;
      exit(EXIT_FAILURE);
    }
  }
};

#endif // modelS_HH
