#include <iostream>
#include <iomanip>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include "WebGraph.h"
#include <iostream>
#include <string>
#include<fstream>
#include<string>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int guessBetween(int num1, int num2)
{
    if (num1 > num2)
    {
        return(guessBetween(num2, num1));
    }
    else if (num2 > num1)
    {
        int guess = rand() % (num2 - num1);          //guess in the range(0- (num2-num1) )
        guess += num1;                              //add lower bound
    }
    else
    {
        return num1;                                //equal nos passed
    }
}

int main()
{
    unsigned int seed = time(0);
    srand(seed);

    WebGraph webA;
    webA.calculatePageRank();
    return 0;
}