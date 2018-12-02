#ifndef SCHEMES_HH
#define SCHEMES_HH

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "models.hh"

class DIRK
{
public:

  DIRK(int stages) //default constructor
  : stages_(stages),
    a_(stages*stages), b_(stages), c_(stages)
  {
    for (int i=0;i<stages_;++i)
      for (int j=0;j<stages_;++j)
        a_[i*stages_+j] = 0.;
     // putting in forward Euler here (although we are not using them at the moment)
     b_[0] = 1.;
     c_[0] = 0.;
  }

  // evolves the solution y(t) to y(t+h)
  // takes y,t,h, and the model and returns the approximation at the next
  // time level
  // The Model is given by a template argument, which has to provide the
  // following methods:
  // - model.f(t,y)
  // - model.df(t,y)
  //
  // replace this function by a function that works for an arbitrary
  // DIRK method
  template <class Model>
  double evolve(const double &y,double t,double h,const Model &model,unsigned &count) const //one step forward
  {
    //ret is what will be returned
    double ret = y; //u_n + h*F for RK methods. Is set to y because we start at u_n
    double tmp_sum; //I use this sum for updating the k[i] values. Is u_n + h*sum_{j=1}^{s}a_{ij}k[j]
    std::vector<double> k(stages_);

    for(int i=0; i<stages_; ++i)
    {
      tmp_sum = y;
      for(int j=0; j<i; ++j)
      {
        tmp_sum += h*a(i, j)*k[j];
      }
      if( a(i,i)!=0 ) //implementing newton method
      {
        unsigned iter = 0;
        double error = ( -k[i] + model.f(t + c_[i]*h, tmp_sum + h*a(i,i)*k[i]) );
        count ++;
        double den; //den stays for the denumerator of the fraction which updates k[i] in Newton's method
        while(iter < 1e6 && std::abs(error) > 1e-6 ) //1e6 is maximum number of iterations and 1e-6 is the given tol
        {
          den = -1 + model.df( t + c_[i]*h, tmp_sum + k[i] )*h*a(i,i);
          count++;
          k[i] -= error/den;
          error = -k[i] + model.f(t + c_[i]*h, tmp_sum + h*a(i,i)*k[i]) ;
          count++;
          iter ++;
        }
        tmp_sum += h*a(i,i)*k[i]; //plugging the result of the newton method in the tmp_sum
      }
      k[i] = model.f(t + c_[i]*h, tmp_sum);
      count++;
      ret += h*b_[i]*k[i];
    }
    return ret; //return u_{n+1}
  }

protected:

  // accessing A for convenience
  double a(int i, int j) const { return a_[i*stages_+j]; }
  double& a(int i, int j) { return a_[i*stages_+j]; }

  int stages_;

  std::vector<double> a_,b_,c_;
};


class FE: public DIRK
{
public:

  FE() : DIRK(1)
  {
	a(0,0) = 0.;
	b_[0] = 1.;
	c_[0] = 0.;
  }

};

class BE: public DIRK
{
public:

  BE() : DIRK(1)
  {
	a(0,0) = 1.;
	b_[0] = 1.;
	c_[0] = 1.;
  }
};

class IM: public DIRK
{
public:

  IM() : DIRK(1)
  {
	a(0,0) = 0.5;
	b_[0] = 1.;
	c_[0] = 0.5;
  }
};

class Heun3: public DIRK
{
public:

  Heun3() : DIRK(3)
  {
	a(1,0) = 1./3;
  a(2,1) = 2./3;
	b_[0] = 1./4;
  b_[1] = 0;
  b_[2] = 3./4;
	c_[0] = 0;
  c_[1] = 1./3;
  c_[2] = 2./3;
  }
};

class DIRK2: public DIRK
{
public:

  DIRK2() : DIRK(3)
  {
  double delta = 0.5 + sqrt(3)/6;
	a(0,0) = delta;
  a(1,0) = 1 - 2*delta;
  a(1,1) = delta;
	b_[0] = (0.5 - delta)/(1 - 2*delta);
  b_[1] = (0.5 - delta)/(1 - 2*delta);
	c_[0] = delta;
  c_[1] = 1 - delta;
  }
};

#endif
