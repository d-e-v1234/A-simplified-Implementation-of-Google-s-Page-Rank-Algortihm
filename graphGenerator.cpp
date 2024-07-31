#include <iostream>
#include <iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

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
    const int NUM_WEBPAGES = 50;

    int webMatrix[NUM_WEBPAGES][NUM_WEBPAGES];
    for (int page = 0; page < NUM_WEBPAGES; page++)
    {
        //display vertex no.
        cout << page << " ";

        /****************************************************************
        web graph can or can't possible be a fully connected graph
        Model of this web graph:
            There are a total of 50 webpages(vertices) in the weh graph
            there is 75% channce that a web page has a forward link to  less than or equal to 20  pages
            There is 25% chance that a web page is adjacent to more than 20 webpages

        ***************************************************************/
        int prob_connection = guessBetween(1, 100);                     //prob of forming N connections
        if (prob_connection >= 1 && prob_connection <= 25)             //prob(more than 20 coonections) = 0.25
        {
            const int numConnections = guessBetween(21, 49);

            bool isConnected[NUM_WEBPAGES];                      //marks connection that are already connected or should be ignored(like a connection to self)
            for (int i = 0; i < NUM_WEBPAGES; i++)
            {
                if (i == page)
                {
                    isConnected[i] = true;
                }
                else
                {
                    isConnected[i] = false;
                }
            }
            for (int i = 0; i < numConnections; i++)
            {


                int adjacentVertex = guessBetween(0, 49);
                while (isConnected[adjacentVertex] == true)        //make upreapted guesses for connections 
                {
                    adjacentVertex = guessBetween(0, 49);
                }
                cout << adjacentVertex << " ";

                isConnected[adjacentVertex] = true;
            }
        }
        else if (prob_connection >= 26 && prob_connection <= 100)
        {
            const int numConnections = guessBetween(0, 20);
            bool isConnected[NUM_WEBPAGES];                      //marks connection that are already connected or should be ignored(like a connection to self)
            for (int i = 0; i < NUM_WEBPAGES; i++)
            {
                if (i == page)
                {
                    isConnected[i] = true;
                }
                else
                {
                    isConnected[i] = false;
                }
            }

            for (int i = 0; i < numConnections; i++)
            {
                int adjacentVertex = guessBetween(0, 49);
                while (isConnected[adjacentVertex] == true)        //make upreapted guesses for connections 
                {
                    adjacentVertex = guessBetween(0, 49);
                }
                cout << adjacentVertex << " ";

                isConnected[adjacentVertex] = true;
            }
        }
        cout << "-999\n";
    }
    return 0;
}