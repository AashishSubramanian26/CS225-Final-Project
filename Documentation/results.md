𝐖𝐫𝐢𝐭𝐭𝐞𝐧 𝐑𝐞𝐩𝐨𝐫𝐭
The output and correctness of each algorithm:
Yen's Algorithm - We chose to implement this algorithm that we had not learnt in class. It basically finds K-1 paths from the start to the end, which are strings we pass in. The method also requires us to push in a map that will be traversed in the span of the method. Next, I used Djikstra's to actually find the multiple paths. In other words, we break the original path we found while removing certain nodes from the graph in order to facilitate new/undiscovered paths using Djikstra's algorith or rather any shortest path algorithm. For example, if we have two paths from two nodes : Paris -> Turkey -> France, and Paris -> Tower -> France. In this case, we will first find the most efficient path between the two and put that in the return vector. Lets just say that's path 1 here. In our second iteration, we remove the edge Paris -> Turkey, hence making path 2 the only path we can use. Now, we are using a fibonacci heap here, which will once again change our runtime to O(M+Nlog(N)), N being the variable being the runtime of dijkstra's algorithm and M being the number of edges. As discussed earlier, there are K paths to be found hence we will have the runtime of Kd per path, d here being the length of the paths. Combining these points, we get the total runtime of O(Kd(M+Nlog(N))).

Dijkstra's Algorithm - Dijkstra's algorithm is called by Yen's for multiple variants of our Wikipedia Graph. This is due to the lack of strength to our weights, because it is hard to have good weights between two webpages because the computer does not know how related the two webpages are. Yen's will remove an edge from the AdjacencyList and Dijkstra's will make a path between page A to page B for each graph variant. Yen's will be storing each path and will return the shortest path it recieves from Dijkstra. Dijkstra's algorithm conventionally uses a min heap in the form of a PriorityQueue ADT as part of its MST building process. However for us, since our weights are based on the number of adjacent vertices a vertex has, we want to use a max-heap, which we implemented using a vector. We also used maps instead of arrays for our "previous" and "distance" data structures, because we do not have numbers for each vertex, but the a string. Dijkstra's at its core creates an MST (Minimal Spanning Tree) using Prim's algorithm, and calculates the distance of each vertex in the MST relative to a start vertex. When we do this process, we build the "previous" map, which we utilize to build a vector of strings which stores the path from our start vertex to our passed in end vertex. In terms of the runtime of Dijkstra's algorithm, it is generally O(nlogn), but our graph is pretty dense with the number of edges each vertex has, so our runtime is between O(nlogn) and O((n^2)logn), where n is the number of vertices.

BFS Algorithm - Our BFS algorithm is not used in a conventional sense. It is not used to find a node in the graph or to check whether a path exists between our start and end nodes. It is also not applied on the verticies, but on the edges of the graph. Our BFS algorithm is designed to remove cycles between two adjacent vertices. So, if I have Paris that points to Croissant, and Croissant also points to Paris, one of those directed edges will be deleted based on which edge is traversed to first by our BFS, and that depends on the start node we start the traversal from. Our runtime for BFS is O(n), where n is the number of verticies. Additionally, for your reference, in all of our algorithms, because we do not have a GraphNode ADT, we have to move around the right information, such as the weights of the edges, and the vector names in pairs in data structures in our code. We also use the word node and word vertex interchangeably in our vernacular on this documentation.

The answer to your leading question:
Our goal here was to find the shortest path from one link to the next link faster than a human through webscraping and algorithms. In the end, we were successful in creating a program that successfully speedruns Wikipedia, better than any human ever can. With humans, its possible the player chooses the wrong next Wikipedia page that causes more time to be spent on trying to get to the destination page. Instead, while our program finds multiple paths and returns in the shortest one in less time. Although, we concede a player has to account for internet speed in going between webpages, while our program has pre-saved wikipedia data to use. If we had to account for the time it takes to webscrape tens or hundreds of thousands of pages, then it is possible our code would loose in simple Wikipedia pages, where the start page and end page have some relevancy.