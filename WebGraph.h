#pragma once

#include "WebGraph.h"
#include <iostream>
#include <string>
#include<fstream>
#include<string>
#include <windows.h>
//#include <unistd.h>

using namespace std;

const int  NUM_WEBPAGES = 50;
int guessBetween(int num1, int num2);
class WebGraph
{
private:
	bool adjacencyMatrix[NUM_WEBPAGES][NUM_WEBPAGES];
	double PRVecotr[NUM_WEBPAGES];
	const double DAMPING_FACTOR;

	int numLinks[NUM_WEBPAGES];								//the number of forward links each page has
	int* graph[NUM_WEBPAGES];								//an array of pointers || for each page(represented by a single row) stores it fLinks in coloumns of the the row
public:
	WebGraph(string filename = "WebGraph.txt");
	void sortParallel(double PRVector[], int webPages[],  int size);

	void calculatePageRank(void);

};
