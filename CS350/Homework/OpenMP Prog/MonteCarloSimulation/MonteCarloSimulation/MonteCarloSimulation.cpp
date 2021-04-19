// MonteCarloSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Levi George
//Date: 4/17/2021
//CS 350: Prog. Lang. Design
//

#include <iostream>
#include <random>
#include <math.h>
#include <vector>
#include <utility>
#include <time.h>
#include <iomanip>
#include <omp.h>

using namespace std;
int main()
{

    double startTime = omp_get_wtime();
    //seed our random numbers
    srand(time(NULL));

    //vector of points
    vector<pair<int, int>> pointArray;

    //radius/circumference of circle = r
    int r = 10;

    //length, width of square = 2r
    int s = 2 * r;

    //points to generate = 1000 (N)
    int N = 1000;
    //points in circle M
    int M = 0;

    //generate a bunch of points
    for (int i = 0; i < N; i++)
    {
        //we are going to perceive the circle with the center at 0,0
        int x, y;
        x = (rand() % 20) - 10; //generate between -10 and 10, 20 options, 20 is the width and height of our square
        y = (rand() % 20) - 10;

        //debugging code: cout << x << " " << y << endl;

         //use pairs to store info in a orderly manner
        pair<int, int> newPair = make_pair(x, y);

        pointArray.push_back(newPair);//place pair in vector
    }

    //debugging code: cout << "Number of items in Vector: " << pointArray.size() << endl;

    //check if in circle
    for (int i = 0; i < pointArray.size(); i++)
    {
        //gets current point from 
        pair<int, int> currPair = pointArray.at(i);

        //calculates radicand
        double xLen = pow(currPair.first, 2);
        double yLen = pow(currPair.second, 2);

        //debugging code:cout << "Pair " << i << endl;
        //debugging code:cout << "\t xVal = " << xLen << endl;
        //debugging code:cout << "\t yVal = " << yLen << endl;

        double radicand = (xLen + yLen);

        //calculates radical
        double ptVector = sqrt(radicand);

        //for every point vector that is less than the radius of the circle is within the circle.
        if (abs(ptVector) <= (double)r)
        {
            //debugging code:cout << ptVector << " < " << r << " M is now; " << M << endl;
            M++;
        }
    }

    //calculate pi using 4 * M/ N
    double quotient = (double)M / (double)N;

    //output results, use iomanip to control output
    cout << fixed << setprecision(2) << (4 * quotient);
    cout << "\n Time Elapsed - " << (omp_get_wtime() - startTime) * 1000;


}


