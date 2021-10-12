#include <iostream>
#include <cmath>
#include <cassert>

#include "Vector.hpp"
#include "Lagrange.hpp"

double function_1(double x);
double function_2(double x);
double function_3(double x);
double function_4(double x);

int main(int argc, char* argv[])
{

    //Number of points to be approximated
    int nxvalues = 101;



    //Calculates the approximation over 101 points
    //using polynomials of degree 9.

    std::cout << "Approximating function 1: " << std::endl;

    Lagrange* p_f1Lagrange1
    = new Lagrange(&function_1, 0.0,1.0,10,"F_1");

    p_f1Lagrange1->Approximate(nxvalues);

    std::cout << "Approximating function 2: " << std::endl;

    Lagrange* p_f2Lagrange1
    = new Lagrange(&function_2, 0.0,1.0,10,"F_2");

    p_f2Lagrange1->Approximate(nxvalues);

    std::cout << "Approximating function 3: " << std::endl;

    Lagrange* p_f3Lagrange1
    = new Lagrange(&function_3, 0.0,1.0,10,"F_3");

    p_f3Lagrange1->Approximate(nxvalues);

    std::cout << "Approximating function 4: " << std::endl;

        Lagrange* p_f4Lagrange1
    = new Lagrange(&function_4, 0.0,1.0,10,"F_4");

    p_f4Lagrange1->Approximate(nxvalues);




        //Approximates the four functions of 101 points with
        //Lagrange polynomials of degree 19

    std::cout << "Approximating function 1: " << std::endl;

        Lagrange* p_f1Lagrange2
    = new Lagrange(&function_1, 0.0,1.0,20,"F_1(2)");

    p_f1Lagrange2->Approximate(nxvalues);

    std::cout << "Approximating function 2: " << std::endl;

            Lagrange* p_f2Lagrange2
    = new Lagrange(&function_2, 0.0,1.0,20,"F_2(2)");

    p_f2Lagrange2->Approximate(nxvalues);

    std::cout << "Approximating function 3: " << std::endl;

    Lagrange* p_f3Lagrange2
    = new Lagrange(&function_3, 0.0,1.0,20,"F_3(2)");

    p_f3Lagrange2->Approximate(nxvalues);

    std::cout << "Approximating function 4: " << std::endl;

        Lagrange* p_f4Lagrange2
    = new Lagrange(&function_4, 0.0,1.0,20,"F_4(2)");

    p_f4Lagrange2->Approximate(nxvalues);



    delete p_f1Lagrange1;
    delete p_f2Lagrange1;
    delete p_f3Lagrange1;
    delete p_f4Lagrange1;
    delete p_f1Lagrange2;
    delete p_f2Lagrange2;
    delete p_f3Lagrange2;
    delete p_f4Lagrange2;

    return 0;
}


double function_1(double x)
{
    return pow(x,3);
}

double function_2(double x)
{
    return sin(2*x);
}

double function_3(double x)
{
    return 1/(1+25*pow((2*x-1),2));
}

double function_4(double x)
{
    assert (x >= 0);
    return sqrt(x);
}
