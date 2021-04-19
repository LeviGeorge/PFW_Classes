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
    //seed our random numbers
    srand(time(NULL));

    //vector of points
    vector<pair<int, int>> pointArray;

    //radius/circumference of circle = r
    int r = 10;

    //length, width of square = 2r
    int s = 2 * r;

    //points to generate = 1000 (N)
    unsigned int N = 1000;
    //points in circle M
    int M = 0;

    //we want to share this so that we don't exceed the N count of points for our circle
    int i = 0;

    omp_set_num_threads(16);//we set number of threads

    /*
    *********************************************************
                            Results of Thread Variation
                       Average Thread Time          Slowest Thread Time
    One Thread:               1.3732 ms                      1.3732 ms
    Two Threads:              1.4802 ms                      1.7383 ms
    Four Threads:             1.992 ms                       2.5967 ms
    Eight Threads:            2.538 ms                       3.6392 ms
    Sixteen Threads:          3.634 ms                       6.2366 ms

    It appears that increasing the number of threads increases the time required to run
    it could be that my parallel programming is not as efficient, so I have each thread stumbling over one another.

    However, I believe that it could also be that the size of our test (1000) is too small to properly manage and make use of concurrent programming. 

    ********************************************************
    */

    #pragma omp parallel shared (pointArray, i)//begin our parallel programming, share pointArray and i
    {
        double startTime = omp_get_wtime();

        //generate a bunch of points
        for (; i < N;)
        {
            //we are going to perceive the circle with the center at 0,0
            int x, y;
            x = (rand() % 20) - 10; //generate between -10 and 10, 20 options, 20 is the width and height of our square
            y = (rand() % 20) - 10;

            //debugging code: cout << x << " " << y << endl;

             //use pairs to store info in a orderly manner

            //I did this to prevent excess push backs
            #pragma omp critical
            {
                pair<int, int> newPair = make_pair(x, y);

                pointArray.push_back(newPair);//place pair in vector
            }
            
            //prevents multiple threads from incrementing at once, and surpassing N
            #pragma omp critical
            i++;

        }//END FOR LOOP

        //debugging code: cout << "Number of items in Vector: " << pointArray.size() << endl;

        #pragma omp barrier//we want all threads to start the next loop at the same time
        

        //we only want one thread to execute this to prevent losing progress on our for loop.
        //If one thread is a little slow, it could delete the progress of our previous loops.
        #pragma omp master
        {
            i = 0;
        }

        //check if in circle
        for (; i < N;)
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

                //prevent excess increments
                #pragma omp critical
                M++;
            }

            //prevents multiple threads from incrementing at once, and surpassing N
            #pragma omp critical
            i++;
            
        }//END FOR LOOP

        //We do this to make sure the two lines print together for any thread
       #pragma omp critical
        {
            cout << "Thread Num: " << omp_get_thread_num()  << endl;
            cout << "Thread Time: " << (omp_get_wtime() - startTime) * 1000 << endl;
        }

        //We want our output to be neater, so we tell the threads to wait until they syncrhonize and we don't have to 
        //worry about our final output being hidden amongst other outputs
        #pragma omp barrier

        //output results, use iomanip to control output

        //we let the master thread handle this
        #pragma omp master
        {
            //calculate pi using 4 * M/ N
            double quotient = (double)M / (double)N;
            cout << "\n M: " << M << " N: " << N << endl; //<--- This was debugging code
            cout << fixed << setprecision(2) << "\nApproximation: " << (4 * quotient) << endl;
        }

    }//END PARALLEL

}


