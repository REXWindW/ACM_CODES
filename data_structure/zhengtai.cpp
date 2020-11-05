#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

double gauss_rand(){
    static double V1, V2, S;
    static int phase = 0;
    double X;
    srand((unsigned)time(NULL));
    if (phase == 0){
        do{
            double U1 = (double)rand() / RAND_MAX;
            double U2 = (double)rand() / RAND_MAX;
            V1 = 2 * U1 - 1;
            V2 = 2 * U2 - 1;
            S = V1 * V1 + V2 * V2;
        } while (S >= 1 || S == 0);
        X = V1 * sqrt(-2 * log(S) / S);
    }
    else
        X = V2 * sqrt(-2 * log(S) / S);
    phase = 1 - phase;
    //X = X * 0.04 + 40;
    return X;
}

int main(int argc, char *argv[])
{
    gaussrand();
    return 0;
}