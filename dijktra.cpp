#include <iostream>
using namespace std;

#define max 100
#define infinity 9999
#define nil -1
#define temp 0
#define permanent 1

int adj[max][max]; // Adjacency matrix to represent the graph
int predecessor[max]; // Array to store predecessors in shortest path
int pathlength[max]; // Array to store shortest path lengths
int status[max]; // Array to track the status of each vertex during Dijkstra's algorithm

// Function prototypes
int create_graph();
void dijkstra(int src, int n);
int min_path(int n);
int find_path(int s, int v);

int main() {
    int src, v;
    int n = create_graph();
    cout << "Enter source vertex of graph: ";
    cin >> src;
    dijkstra(src, n);

    while (1) {
        cout << "Enter destination vertex (-1 to exit): ";
        cin >> v;
        if (v == -1)
            break;
        if ((v < 0) || (v >= n))
            cout << "This vertex does not exist" << endl;
        else if (v == src)
            cout << "Source and destination vertices are the same" << endl;
        else if (pathlength[v] == infinity)
            cout << "There is no path from source to destination vertex" << endl;
        else
            find_path(src, v);
    }

    return 0;
}

// Function to create a graph and return the number of vertices
int create_graph() {
    int n, max_e, i, origin, destination, wt, j;
    cout << "Enter number of vertices in the graph: ";
    cin >> n;
    max_e = n * (n - 1);
    for (i = 0; i < max_e; i++) {
        cout << "Enter the origin and destination of edge " << i + 1 << ": ";
        cin >> origin >> destination;
        cout << "Enter the weight: ";
        cin >> wt;
        adj[origin][destination] = wt;
    }
    // Print the adjacency matrix
    cout << "Adjacency matrix of the graph:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << adj[i][j] << "  ";
        }
        cout << endl;
    }
    return n;
}

// Dijkstra's algorithm for finding shortest paths
void dijkstra(int src, int n) {
    int i, current;
    // Initialize all vertices to temporary status and initialize path lengths and predecessors
    for (i = 0; i < n; i++) {
        status[i] = temp;
        pathlength[i] = infinity;
        predecessor[i] = nil;
    }
    // Set path length of source vertex to 0
    pathlength[src] = 0;

    while (1) {
        // Find the vertex with the minimum path length among temporary vertices
        current = min_path(n);
        if (current == nil)
            return;
        status[current] = permanent; // Set the vertex as permanent

        // Update path lengths of adjacent temporary vertices
        for (i = 0; i < n; i++) {
            if ((adj[current][i] != 0) && (status[i] == temp)) {
                if (pathlength[current] + adj[current][i] < pathlength[i]) {
                    predecessor[i] = current;
                    pathlength[i] = pathlength[current] + adj[current][i];
                }
            }
        }
    }
}

// Function to find the vertex with the minimum path length among temporary vertices
int min_path(int n) {
    int i, min = infinity, k = nil;
    for (i = 0; i < n; i++) {
        if ((status[i] == temp) && (pathlength[i] < min)) {
            min = pathlength[i];
            k = i;
        }
    }
    return k;
}

// Function to find and print the shortest path from source to destination vertex
int find_path(int s, int v) {
    int i, u;
    int path[max];
    int shortdist = 0;
    int count = 0;
    while (v != s) {
        count++;
        path[count] = v;
        u = predecessor[v];
        shortdist += adj[u][v];
        v = u;
    }
    count++;
    path[count] = s;
    cout << "Shortest path is: ";
    for (i = count; i >= 1; i--) {
        cout << path[i] << " ";
    }
    cout << endl;
    cout << "Shortest distance is: " << shortdist << endl;
    return 0;
}
/*
Output:
svkm@svkm-VirtualBox:~$ cd Documents
svkm@svkm-VirtualBox:~/Documents$ cd SY_IT_54 
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$ g++ dijkstra.cpp
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$ ./a.out
Enter number of vertices
3
Enter edges (-1 to quit)1 
0 1 
Enter welght for this edge: 2
Enter edges (-1 to quit)2 
1 2 
Enter weight for this edge: 5
Enter edges (-1 to quit)3
0 2
Enter weight for this edge: 3 
Enter edges (-1 to quit)4 
2 2
Enter welght for this edge: 1
Enter edges (-1 to quit)5 
2 1
Enter weight for this edge: 3
Enter edges (-1 to quit)6 
1 1
Enter weight for this edge: 2
Enter source vertex: 0
Enter destination vertex(-1 to quit): 2
Shortest path is 032767
The shortest distance is 3
Enter destination vertex(-1 to quit):
*/





















