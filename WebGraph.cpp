#include "WebGraph.h"

WebGraph::WebGraph(string filename) :DAMPING_FACTOR(0.85)
{

	for (int pageNum = 0; pageNum < NUM_WEBPAGES; pageNum++)
	{
		PRVecotr[pageNum] = 0.0;
	}


	for (int pageNum = 0; pageNum < NUM_WEBPAGES; pageNum++)
	{
		numLinks[pageNum] = 0;
	}

	for (int row = 0; row < NUM_WEBPAGES; row++)
	{
		for (int col = 0; col < NUM_WEBPAGES; col++)
		{
			adjacencyMatrix[row][col] = false;
		}
	}

	int page;
	int fLink;				//foward link from "page"

	ifstream inFile;
	inFile.open(filename);
	if (!inFile)
	{
		cout << "The file couldn't be opened.\n Recheck filename...\n";
		exit(EXIT_FAILURE);
	}
	for (int pageNum = 0; pageNum < NUM_WEBPAGES; pageNum++)
	{
		inFile >> page;
		inFile >> fLink;
		while (fLink != -999)
		{
			adjacencyMatrix[page][fLink] = true;
			numLinks[page]++;
			inFile >> fLink;
		}
	}


	//for each page create an array to accomodate all its forward links
	for (int pageNum = 0; pageNum < NUM_WEBPAGES; pageNum++)
	{
		graph[pageNum] = new int[numLinks[pageNum]];;
	}
	/************************************************************************
		each PAGE on THE WEB -> A ROW ON THE GRAPH 2-D ARRAY
		FOR EACH PAGE'S ROW :
		GRAPH[ROW][COLOUMN] SOTRES for EACH WEBPAGE(ROW) ITS RESPECTIVE FORWARD LINKS
	************************************************************************/
	for (int page = 0; page < NUM_WEBPAGES; page++)
	{
	//	cout << "\n\n\nIn outer loop...\n\n\n";											Tested +
	//	cout << "\n\nPage " << page << ": ";											Tested +
		int pos = 0;					//the Forward Link index/position/value

		int numfLinks = numLinks[page];
		for (int fLinksFound = 0; fLinksFound < numfLinks; fLinksFound++)			
/*	
					fLinksFound is the num of foward Links  discovered till now
					and numfLinks is the maximum number of foward Links				 
*/
		{
			int col = pos;
			for (; (adjacencyMatrix[page][col] != true) && (col < NUM_WEBPAGES); col++)		//keep scanning a row in adjacency matrix until an Flink is found
			{
				pos++;					//last index ath which a foward link was found - will start from here next time
			}

			if (fLinksFound < numfLinks)
			{
				graph[page][fLinksFound] = pos;
	//			cout << graph[page][fLinksFound] << ", ";
			}
			else
			{
				cerr << "Out of Bound error occured.\n";
				exit(EXIT_FAILURE);
			}
			pos++;						//will start next time from te very next postion
		}
	}

	/****************************************
	************Tested + *****************

	for (int row = 0; row < NUM_WEBPAGES; row++)
	{
		cout << "\n\nPage " << row << ": ";
		for (int col = 0; col < numLinks[row]; col++)
		{
			cout << graph[row][col] << " , ";
		}
	}
	*****************************************/
}

void WebGraph::sortParallel(double PRVector[], int webPages[], int size)
{
	
	for (int i = 0; i < size; i++)
	{
		double smallestRank = PRVector[i];
		int smallestPage = webPages[i];
		for (int j = i+1; j < size; j++)
		{
			if (smallestRank > PRVector[j])
			{
				double dTemp = smallestRank;
				int iTemp = smallestPage;
				PRVector[i] = smallestRank = PRVecotr[j];
				webPages[i] = smallestPage = webPages[j];

				PRVector[j] = dTemp;
				webPages[j] = iTemp;
			}
		}
	}

	return;
}
void WebGraph::calculatePageRank(void)
{
	int currentPage = guessBetween(0, NUM_WEBPAGES-1);
	/*
	cout << endl << "Current Page = " << currentPage << endl;*/
	cout << "\n\n(^~^)Visited----->" << currentPage << endl << endl;
	Sleep(1000);
	
	int possiblePaths = 0;
	double totalJumps = 0;
	for(int iter = 0; iter < (NUM_WEBPAGES * 50); iter++)
	{
		int possiblePaths = numLinks[currentPage];
		//cout << endl << endl << "There are " << possiblePaths << " Possible Paths to choose from." << endl << endl;
		if (possiblePaths == 0)
		{
			cout << "(<_>) Got hit by a wall!.\n";
			Sleep(1000);
			currentPage = guessBetween(0, NUM_WEBPAGES - 1);			//there were 0 possible forward links
			continue;
		}

		//out of the pages directly connected to current page
		//choose a single page by selecting an index of one page from graph[page] array
		bool stay = true;
		int guess = guessBetween(1, 100);
		if (guess <= 15)
		{
			stay = false;
		}

		int nxtPage;
		if (stay)
		{
			int nxtIdx = guessBetween(0, possiblePaths - 1);
			nxtPage = graph[currentPage][nxtIdx];
			/*
			cout << endl  << "The next current Page = " << nxtPage << endl;
			*/
			PRVecotr[nxtPage] += 1.0;
		}
		else
		{
			nxtPage = guessBetween(0, NUM_WEBPAGES - 1);
		}
		currentPage = nxtPage;
		cout << "\n\n(^~^)Visited----->" << currentPage << endl << endl;
		Sleep(1000);
		totalJumps += 1.0;
	}


	//int webPages[NUM_WEBPAGES];
	//for (int i = 0; i < NUM_WEBPAGES; i++)
	//{
	//	webPages[i] = i;
	//}

	//sortParallel(PRVecotr, webPages, NUM_WEBPAGES-1);

	for (int i = NUM_WEBPAGES-1; i >= 0; i--)
	{
		cout << "Rank of " << i << " = " << PRVecotr[i] << endl;
	}
}