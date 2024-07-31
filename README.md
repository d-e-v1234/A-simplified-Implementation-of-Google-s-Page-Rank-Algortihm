1. Overview: 
As of 21 April 2023, there were over 30 billion web pages indexed on the World Wide Web. Without an appropriate ranking introduced amongst webpages, a search result for a specific keyword such as “apple” would lead to an arbitrary list  of webpages that would have the word “apple” placed on them.  
The PageRank algorithm developed at Stanford and that later led to the  
Foundation of Google Search Engine, is one of the algorithms that tries to bring order to the web.
1.1) Ranking a webpage:
A very simple definition of the rank of a webpage u might simply consider the number of webpages that refer to (have links to) webpage u. We call these link backlinks to u. 
 ![image](https://github.com/user-attachments/assets/43d9c72b-6c21-481d-95bc-47378ee371dc)

However, pages ranked in this way might be influenced by artificial manipulation.  The rank of a page is increased by creating many pseudo webpage and making them point to a target specific page.
 
  2 
1.2) Revised Definition for PageRank:  
Notations: 
Fu: the set of pages that webpage u points to 
Bu: be the set of pages that point to u 
Nu: be the number of links from u  
C: normalization factor  
R(u) = C *   Σ R(v)/ Nv 
The rank of a page is divided among its forward links evenly to contribute to the  ranks of the pages they point to. 
![image](https://github.com/user-attachments/assets/7b907010-56e7-44ba-a7c2-ab2416afa17f) 
Fig 2: The Distribution of PageRank among Forward Links 
2. GOALS: 
2.1) First Iteration:  
This Project aims to develop a simulation that models the behavior of a Random Surfer.  
The random surfer begins its quest by discovering a random page on the web. The surfer then chooses one of the forward links to traverse. The surfer continues to iterate through the web repeatedly. Whenever, the random user is stuck on a webpages (there are no forward links) it reinitiates its search from a random page with the previously maintained Rank vector. 
The probability of visiting a specific webpage is given by the number of times the random surfer has visited that webpage. Conversely, a webpage has high rank if the Random Surfer frequently visited it. 
2.2) Second Iteration:  
The output of the second iteration is the probability distribution for each webpage on the web. The input is a graph or web model stored in a database.  
3. Recommended Data Structure: 
3.1) Directed Graph:  
The ideal data structure for implementation of a web-based model is a graph. The  nodes of the graph represent the webpages indexed on the web. Edges model the  link between webpages. 
A matrix based (Array based) implementation of the graph would be used in this  scenario. 
3.1.1) Note on Selection Criteria:  
▪ It efficiently models the behavior of webpages connected across the web. ▪ It allows as many webpages as there are in the provided web database. ▪ A matrix based implementation allows to check the link between any two  given web pages with an ideal O (1) time complexity. 
▪ Space usage: Given that there are n webpages in total a grid of order n2is  required to store the connection between web links. 
▪ Flexibility: The graph allows accommodating more web links into the  web. 
3.2) Probability Matrix:  
Consider a webpage u and Fu the set of its connected webpages, 
For each webpage connected to u (a belonging to Fu), the probability of visiting a  from u is given by the respective uth and ath index in a Matrix A. 
If N gives the number of forward links of u, the probability of visiting a from the  current page, u is given by: 
P(a) = 1/N, if there is a forward link from u to a 
0, if there is no forward link from u to a
 
  4 
3.3) Rank Vector:  
A Rank Vector maintains rank of each webpage at their respective indexes. It is  initialized with equal ranks for all webpages i.e. 1/L, L is the total number of  Nodes/Webpages in the graph/web. These ranks are iteratively updated as random  surfer iterates through the web. 
4. Functional Requirements 
4.1) Database:  
The algorithm begins by reading the graph from a stored database. Since this is, a  simple implementation so I would be using a text file that would be my data set.  The database specifies the number of webpages added in the web to date and  updates its entries with each newly added webpage into the system. The database  maintains records for links between indexed webpages. The data set is stored in  the form of a matrix.  
Grid[a][u] = 
1, if a has a forward link to u  
0, if no link from a  
4.2) A simulation of random surfer traversing the web:  
A simulation that models the behavior of our random surfer on the internet. The  simulation calculates the probability of traversing to a node from a current node.  Then based on these probabilities makes a random decision to traverse to a  connected node/ webpage. 
4.3) Probability Distribution:  
The final output for the last iteration would be a probability distribution that maps  the probability of visiting each web page with its respective index. If two  webpages were to appear as result of a web search then the one ranked above  (with greater probability) should be placed at the top the list.  
5. Non-Functional Requirements 
▪ TIME COMPLEXITY: 
The time complexity for each operation performed on the graph would be  ideal O (1) as the nodes are properly index. However, an n number of  
iterations are needed to be performed on the web to get a correct estimate  of probabilities of visiting webpages. Similarly, the values in page rank can be updated in O (1) operations given that the vector index is already known.
▪ SPACE COMPLEXITY: given that there are, n webpages in total a grid of order n2is required to store the connection between web links. Another grid/matrix for storing the probabilities of visiting each node from a given node is required. A vector of size n, stores the ranks of respective webpages. 
6. A dummy project Output 
6.1) Simulation:  
Whenever the random surfer randomly decides to jump to a new node the system  records its moments and updates probability. The simulation shows that it has reached  a specific node:  

![image](https://github.com/user-attachments/assets/cf9e11bf-f3e0-4490-a9a1-bf475da5f3ca)


6.2) Probability Distribution: 
Consider a simple web with 4 webpages [ A, B, C, D] 
A 🡪 B 
B🡪C, D  
D🡪C 
C🡪no outedge
 
6 
Prob(B) = Prob(C) = 1 
Prob(D) = 1/2 
Prob(A) is determined by random chance in this case, as it is the start of the  simplified web.(In actual implementation A would have some probability  determined by itsbacklinks) 


7. References: 
1) A simplified Explanation of the Algorithm: 
https://www.youtube.com/watch?v=meonLcN7LD4

3) The paper that this algorithnm is based on: 
cis.upenn.edu/~mkearns/teaching/NetworkedLife/pagerank.pdf

