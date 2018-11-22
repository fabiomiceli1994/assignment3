#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <chrono>

#include "schemes.hh"
#include "models.hh"

template <class Model>
double solve(const Model &model, const DIRK &scheme, double tau)
{
  double maxError = 0;
  double y=model.y0();
  double t=0;
  while ( t<=model.T() )
  {
    y =  scheme.evolve(y,t,tau,model);
    t += tau;
    double error = y - model.exact(t);
    maxError = std::max(maxError,std::abs(error));
  }
  return maxError;
}

int main ( int argc, char **argv )
{
  if (argc<5)
  {
    std::cerr << "Usage: " << std::endl
			  << "  " << argv[0] << " <model> <scheme> <tau_0> <J>" << std::endl << std::endl
			  << "where" << std::endl
			  << "  <model>    model index (int)" << std::endl
			  << "  <scheme>   scheme index (int)" << std::endl
			  << "  <tau_0>    initial stepsize (double)" << std::endl
			  << "  <J>        number of eocs (int)" << std::endl;
    return 1;
  }
  const int modelNumber = atoi( argv[1] );
  const int schemeNumber = atoi( argv[2] );
  double tau = atof( argv[3] );
  const int level = atoi( argv[4] );

  // choose correct model and scheme
  Test model;
  model.modelNumber_= modelNumber;
  std::vector<DIRK *> schemes;
  schemes.push_back(new FE());
  schemes.push_back(new BE());
  schemes.push_back(new IM());
  schemes.push_back(new Heun3());
  schemes.push_back(new DIRK2());

  std::vector<double> maxErrors(level);

  std::ofstream myFile;
  myFile.open("Errors_Model_" + std::to_string(modelNumber) + "_Scheme_" + std::to_string(schemeNumber) + "_tau_" + std::to_string(tau) + "_J_" + std::to_string(level) + ".dat", std::ios::out);
  if(!myFile.good())
  {
    std::cout << "Failed to open the file." << std::endl;
    exit(EXIT_FAILURE);
  }
  myFile << "#Error for different scheme" + std::to_string(schemeNumber) << std::endl;
  myFile.width(25);
  myFile << std::left << "1-tau" ;
  myFile.width(25);
  myFile << std::left << "2-Maximum Error" ;
  myFile.width(25);
  myFile << std::left << "3-EOCS" << std::endl;

  for (int i=0;i<level;++i,tau/=2.)
  {
    maxErrors[i] = solve(model, *schemes[schemeNumber], tau);
    myFile.width(25);
    myFile << std::left << tau ;
    myFile.width(25);
    myFile << std::left << maxErrors[i] ;
    if( i == 0 ) //skips the first call since no ratio can be calculated and avoids printing "nan" if error is qual to zero
    {
      myFile << std::left << "\t" << std::endl;
    }else
    {
      myFile << std::left << log(maxErrors[i]/maxErrors[i-1])/log(0.5) << std::endl;
    }
    //std::cout << "tau=" << tau << " and " << "maxError=" << maxError << "." << std::endl;
  }
  myFile.close();
  return 0;
}
