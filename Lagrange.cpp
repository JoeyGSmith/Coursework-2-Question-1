#include <iostream>
#include <cassert>
#include <iomanip>
#include <fstream>

#include "Lagrange.hpp"

//Specialised constructor
Lagrange::Lagrange( double (*pFunction) (double),
const double xmin, const double xmax, const int npoints,
const std :: string outputFileName )
{
    //Initialise
    SetInterval(xmin,xmax);
    SetNoPoints(npoints);
    Setfunction(pFunction);
    mOutputFileName = outputFileName + ".dat";
}


void Lagrange::Approximate(const int nxvalues)
{

    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Using Lagrange method with the following values: " << std::endl;
    std::cout << "Lower interval bound = " << mXmin << std::endl;
    std::cout << "Upper interval bound = " << mXmax << std::endl;
    std::cout << "Number of points = " << nxvalues << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;



    //Creates vector of x values

    Vector* xpoints
    = new Vector(nxvalues);

    //Exact solution vector

    Vector* fexact
    = new Vector(nxvalues);

    //Vector of approximated points
    Vector* approx
    = new Vector(nxvalues);

    Vector* interp
    = new Vector(nxvalues);


    //Calculating gap in points
    double stepsize = (mXmax-mXmin)/(double)(nxvalues-1);

    double stepsize2 = (mXmax-mXmin)/(double)(mNpoints-1);

    //Variable for calculating Lagrange polynomial at given point
    double Lcount, approxvalue;

    double MaxError = 0.0;


    //fills the vectors for the points and exact solutions
    for (int i=0; i < nxvalues; i++)
    {
        (*xpoints)[i] = mXmin + i*stepsize;
        (*fexact)[i] = mpFunction(xpoints->Read(i));
    }

    for (int i=0; i < mNpoints; i++)
    {
        (*interp)[i] = mXmin + i*stepsize2;
    }


    for (int i=0; i < nxvalues; i++)
    {

        approxvalue =0;

        for (int j=0; j < mNpoints; j++)
        {
            Lcount = 1.0;


            for (int k=0; k < mNpoints; k++)
            {

                if (k == j)
                {
                    continue;
                }
                else
                {
                    Lcount *= (xpoints->Read(i)-interp->Read(k))/(interp->Read(j)-interp->Read(k));
                }
            }

            approxvalue+=Lcount*mpFunction(interp->Read(j));
        }

        (*approx)[i] = approxvalue;

        if ( MaxError <= std::abs(approx->Read(i)-fexact->Read(i)))
        {
            MaxError = std::abs(approx->Read(i)-fexact->Read(i));
        }

    }

    std::cout << "Function approximated with maximum error " << MaxError
    << std::endl;

    SaveFile(mOutputFileName,xpoints,fexact,approx);

    delete xpoints;
    delete fexact;
    delete approx;


}
