#ifndef LAGRANGEHEADERDEF
#define LAGRANGEHEADERDEF

#include "AbstractApproximator.hpp"
#include "Vector.hpp"

class Lagrange:

    public AbstractApproximator
    {

    public:

        //Specialised constructor
        Lagrange( double (* pFunction ) ( double ) ,
const double xmin , const double xmax ,const int npoints ,
const std :: string outputFileName) ;

        void Approximate ( const int nxvalues );

    private:

        //Hiding default constructor
        Lagrange();



    };

#endif
