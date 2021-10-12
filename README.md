# Coursework-2-Question-1
This project contains files that perform some of interpolation. AbstractApproximator files contain a class that is derived from in other files. It contains functions that print an array of points to a file.
The class Lagrange is derived from AbstractApproximator and has a function that computes the values of the Lagrange polynomial interpolant at nxvalues uniformly spaced points in the interval [xmin,xmax] and saves them to a file. It also computes the maximum error in the approximation at these nxvalues points (an approximation to the ∞-norm error) and prints it to the screen.
The vector files were not created by me, but are just simple given functions for computing vector (scalar) multiplication, and is used in the other files.
The driver file is an example of how the code is used. It approximates four functions using varying numbers of interpolant points.
