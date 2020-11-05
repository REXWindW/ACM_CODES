#include<iostream>
#include<windows.h>
#include<ctime>
using namespace std;
const int MAX_PATIENT = 20;
const int MAX_WEIGHT = 200;//最大体重
const int MIN_WEIGHT = 40;//最小体重
const int WEIGHT_LIMIT = 2000;//电梯最大载重
const int MAX_FLOOR = 20;//二十层楼

double gauss_rand(){//高斯分布随机数
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

struct People{
    int patient;//耐心值
    int to;//目标楼层
    int weight;//体重
    People(){
        patient = //这里面想用正态分布求
    }
};

int main(){
    srand((unsigned)time(NULL));//随机种子
}
