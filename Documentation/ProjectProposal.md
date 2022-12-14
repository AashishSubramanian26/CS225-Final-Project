Project Proposal: 

## Leading Question - Soumil
Your final project should have a clear conclusion or target goal -- given a dataset and a code base that implements some graph algorithms, what can you learn from the dataset? Are you hoping to solve a specific problem? Are you hoping to produce a general search tool? You should clearly describe how your team will use your dataset and algorithms to answer your leading question. Be thorough in your description -- this is the foundation of your project and if your mentor cannot follow your logic, you will not be able to proceed further on the project. NOTE: Not every algorithm implemented in the project must directly answer this question, but you must answer the question using the algorithms you have selected.

Our leading question is “How can graphs be implemented to help us work with subsets of data?”

Our project has been inspired by one of the most fastest growing trends amongst gaming streamers during the pandemic – Wikipedia speedruns. This chaotic game of intellect works by giving the player a random webpage to start off, say the Wikipedia page for Waffles, and they have to reach the Wikipedia page for World War 1. Each Wikipedia page has embedded links for different Wikipedia pages for keywords on the initial page, that you can click to navigate to the page of the keyword. You have to keep choosing the correct links to get closer and closer to your end page. The person who used the least amount of links to get from page a to page b wins. Also, you may not go back to a previous page once you have clicked a link on a page. 
In our CS final project, we will be implementing a graph and associated algorithms in order to build a program that is capable of finding the shortest path through Wikipedia embedded links to get from one Wikipedia page to another. 
To build a graph data structure for us to traverse and find shortest paths within, we will be utilizing libcurl, an API that will allow us to make http requests and procure a list of wikipedia pages from which we can make our graph. We will also be using breadth-first search to traverse the graph, djikstra’s to find shortest path, and yen’s provides multiple paths, which we can use to find a path between pages we think is the most likely one used by a human user. 





## Dataset Acquisition - Ved
Your final project must use at least one publicly accessible dataset and your proposal must clearly describe what dataset you have chosen to use. This includes succinctly describing:

For our dataset acquisition, we want to be a bit more ambitious with our project and add extra content that we did not learn in this class. As a result, we plan to web scrape all of our Wikipedia pages and their respective links. When we web scrape the Wikipedia page and all of the links, we want to keep track of the parent link (the link where we found our link), parent title, child link (the link where we plan to add to our dataset), child title, and the number of links that the child Wikipedia page and the parent Wikipedia page share. The number of links that the child page and the parent page share will then be used as weights between two graph nodes. In order to actually web scrape all of our data, we plan to use python and dump all of the Wikipedia links that we collect into a CSV file. The specific library that we plan to use in python is called requests to be able to access links, but we will also use Beautiful Soup in order to clean up any weird formatting with the titles and links. Since all of our data is in a CSV file, we believe it will be very easy to quickly grab data when creating graphs in C++. This dataset acquisition will be a one-time process where we store all of our data in a CSV file, and we then use the CSV file for actually building our graph. A couple of information that we will collect includes the titles for the original link and for the child link, the actual urls for the main article and the child article, and also keeping track of the number of links that a child article shares with its parent article. We will only use python for the portion of the project where we create our dataset.

##Data Format - Ved
In roughly a paragraph, you should describe to the best of your ability the specifics of your input dataset. At minimum this includes: What is the source of the dataset and what is the input format of said dataset? How big is the dataset? Do you plan to use all of the data or only a subset? If so, how will you define the subset?

After we web scrape all our data, including the parent link, parent title, child link, child title, and the number of links that are shared, we plan to store the data in a simple CSV file. A CSV file is going to be used as it will be one of the simplest ways to store large sets of data other than using databases, which may be harder to implement using C++ since none of us have experience with that. We plan to always store our data in that order so that when we use these values to build a graph we can tell which way the graph is directed. The number of links they share with each other will be used as weights when we are creating our graph. When we create the graph, we plan to use the Wikipedia title names as the node value while the number of links shared will be the weights. When creating our graph, we plan to use a struct to store some essential pieces of information such as the link and the title of a article in each node. We also plan to keep track of which other nodes a node is connected to within this struct, using a vector of other structs.

##Data Correction - Adi
In a paragraph or two, you should describe how will you parse the input data and what checks are you doing to ensure the input data is error-free. At minimum this should dicuss how you will check for missing entries and how will you correct such instances when you find them. Depending on the dataset, it is also reasonable to check for values that are not physically possible or values which are statistical outliers. Note: These are just suggestions -- you may have many other ideas for how to find and correct problems in your dataset

Since we decided to webscrape and store all of our links and data in a CSV file, we will need to have a checker for bad or faulty links, and somehow replace them with better links among the set of links we are planning to scrape.  

The second issue that we know of as of right now is cycles. One way we can get rid of them could be the following algorithm : 

Utilizing the specified number of vertices and edges, construct the graph. 
Make a recursive function that initializes the visited array, current vertex, and stack of recursion. Mark the index in the recursion stack as well as the current node as visited. 
Recursively call the method for all the vertices that are close to the current node but have not been visited. Return true if the recursive function succeeds.
Return true if the neighboring vertices have previously been marked in the recursion stack. Make a wrapper function that calls the recursive function for each vertex and returns true if any function does. 
If the function returns false for any or all of the vertices, return false.

##Data Storage - Soumil
In a paragraph or two, you should describe what data structure are you using to store the data within your code. If you need any auxiliary data structures or preprocessed tables, you should also discuss them here. As part of this proposal you must include an estimate of the total storage costs for your dataset in Big O notation.

Our API will be able to give us the Wikipedia links that each will be stored one per line on a .txt file for our code to use. Our code will build a graph by reading through the .txt file. 

The graph will be stored as structs with pointers to other structs. Each struct will contain a string that is the wikipedia link, a string that is the wikipedia link’s title, and a vector of structs for each of the structs that the current corresponding wikipedia page has an embedded link to. Each struct will also have a vector of booleans for if they are visited, important for djikstra’s algorithm as we don’t want to keep visiting structs that we have already visited. We also don’t want to reset the boolean for each struct, so therefore we will have a vector of booleans for the number of times we’ll have to run djikstra’s altogether, and for each iteration of djikstra’s algorithm we’ll use the boolean at the index given the iteration number of djikstra’s. 

We will also be creating an adjacency matrix for the graph for our reference, stored as an adjacency list, where we have a vector where each element contains a vector of each of the adjacent nodes for each wiki page. 




## Algorithm - Adi
In no more than a few paragraphs, describe what algorithms you will use to answer the leading question. You should spend some time considering what algorithms you might try and, for all major functions you plan to use, include the following details in your proposal:
NOTE: To be considered a valid final project, your team must implement at least two graph data algorithms as well as a graph traversal from the list of example goals or you must propose an algorithm or set of graph algorithms that represent an equivalent amount of coding development.

Dijkstra’s Algo - The algorithm we are planning to use is Dijkstra's algorithm that helps us find the shortest path between two nodes on a graph, which contains nodes acquired through web scraping. 

The nodes on the graph are based off of a certain weight to differentiate i.e. we will use the number of links that are shared between two pages in our case to differentiate nodes. 
As the weight of the graph we plan to use 1 for each of the weights of the edges, but as a wrapper we plan to use the number of links that they share as a tiebreaker to see which node to then traverse with. The distance (from the beginning location) to every other intersection on the map is initially marked with infinite or a very big number in our case using Dijkstra's method. This is done not to indicate an infinite distance, but to emphasize that those crossings have yet to be visited. As one may assume, this algorithm makes no attempt at direct "exploration" towards the target. Rather, the distance from the beginning point is the only factor in finding the next "current'' junction. This algorithm has the worst time complexity of O(N^2). 

BFS - BFS travels through all the nodes in a single row i.e. explores all the parents followed by the children and then the grandchildren. BFS helps us get through all the nodes and edges and essentially just backtrack through all the nodes to check and update nodes. We are going through all the nodes and the edges, so assuming we have n nodes and m edges, out runtime will be O(n+m). 

Yen’s Algorithm - We will be using yen’s algorithm that builds on top of dijkstra’s algorithm and utilizes it to find k-1 paths. The Dijkstra method is assumed since Yen's algorithm's time complexity depends on the shortest path algorithm employed in the computation of the spur pathways. Now, we are using a fibonacci heap here, which will once again change our runtime to O(M+Nlog(N)), N being the runtime of dijkstra's algorithm and M being the number of edges. As discussed earlier, there are K paths to be found hence we will have the runtime of Kd per path, d here being the length of the paths. Combining these points, we get the total runtime of O(Kd(M+Nlog(N))).

##Function Inputs - Adi
What are the expected inputs for your algorithm? Do you have to do anything to convert your stored dataset into a usable input for the algorithm described? (Ex: A graph algorithm would require making the input into a graph.) For the more complex algorithms, be sure to include as part of the input any additional information you might need. For exlample, A* search requires a heuristic. If you choose to do A*, what are some possible heuristics you might use?

The three functions and algorithms that we plan on using are BFS for traversal, Dijkrta’s algorithm for finding the shortest path between two different nodes, and Yen’s algorithm to find a n number of paths that the user defines. The inputs of dijkstra’s algorithm include the graph, the start and the end. We will use a heuristic to find the weight of the graph. The graph here is weighted according to the link in common between two webpages acting as a tiebreaker. The only difference between yen’s and dijkstra’s is the fact that for yen’s algorithm, we have to include the number of paths we are trying to compute.

For BFS, the only input to the function should only be the starting node, and the ending node. Dijkstras’ inputs will be the starting node which will be specidified by the user, the ending node will also be specified by the user, 

##Function Outputs - Soumil
What is the expected output for your algorithm? How will you store, print, or otherwise visualize the outcome?
 
To output the outcome, we will be printing to the terminal the title of each Wikipedia page that you have to go to in the path formatted as “Page A -> ____ -> ____ -> ____ -> Page B.” We will then print out the most likely used path by the same format onto the terminal. 

##Function Efficiency - Aashish
Your algorithm likely has a theoretically optimal Big O that you can find online. But most algorithms also have multiple implementations and there is no guarantee that your implementation of this algorithm is optimal. As part of this proposal you must include an estimate or target goal on the Big O efficiency of your algorithm in both time and memory.

Dijkstra’s algorithm is not the most efficient algorithm to use here, so we can use a certain BFS traversal to get a different runtime of O(gᵈ). We can also use a bidirectional search, which uses BFS, to find the shortest path with a runtime of O(g^(d/2)). Comparing our algorithms to these, it is more efficient, but it can be modified down further hence making our goal to reach the temporal complexity, which is O((V+E)log V). As for the space complexity, we are looking at the base complexity of O(V^2), where V is the number of nodes on the graph. 


##Timeline - Soumil
As a team, identify a list of tasks such as data acquisition, data processing, completion of each individual algorithm, production of final deliverables, etc... and write a proposed timeline for the completion of these tasks. You are not required to adhere strictly to this timeline but it should represent a reasonable set of benchmarks to strive for. For example, stating that you will finish all graph algorithms over the span of a single week is not reasonable. At least one proposed task must be completed before the mid-project checkin -- part of the mid-project grade will be based on whether or not this target goal was met.

Weeks of 10/24 & 10/31: Finalize project idea and hammer out major details of execution and speak with professor to certify project idea. Complete team contract, project proposal, github repo creation, and the first dev/log

Week of 11/6: Setup API and setup data collection system. Coordinate meeting time with our mentor Kyle McNamara to discuss specifics of our project and approach. 

Week of 11/14: Debug data collection if we didn’t figure that out the previous week. This week will be stressful for all of us so workload will be to just fix data collection and make a UML flowchart for the whole program, and then a specific flowchart for functions the thread will go to based off our UML chart. 

Week of 11/21: Code. Code. Code. Use the UML chart and assign different classes and functions to the each of us to complete. 

Week of 11/28: Debug and work with Kyle to finalize project execution and begin testing phase. Make tests for code based on edge cases and to test if our time and space complexity of our program is more overbearing than expected. Program should be done by this point so we can work on final project deliverables. 

Week of 12/5: Write and finalize documentation for the project. The README on the github page, written report, and final presentation should be finished during dead week. 

