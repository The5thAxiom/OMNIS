/*
    Making a graph
    The class will store the number of vertices, the number of edges, the adjacency matrix and the adjacency list.
*/

#include <iostream>
#include <list>

class GraphNode {
public:
    std::string name;
    int weight;
    GraphNode(std::string name, int weight = 0) {
        this->name = name;
        this->weight = weight;
    }
};

class Graph {
private:
    int numVerts;
    int numEdges;
    std::list<std::list<struct GraphNode>> adj; // a list of GraphNode list pointers
public:
    Graph() {
        this->numVerts = 0;
        this->numEdges = 0;
    }
    void addVertex(std::string name) { // add a check for name already being in the list
        GraphNode node(name);
        std::list<struct GraphNode> newVert;
        newVert.push_back(node);
        this->adj.push_back(newVert);
        this->numVerts++;
    }
    void addEdge(
        std::string source,
        std::string dest,
        int weight = 1,
        bool first = true) {
        for (
            std::list<std::list<GraphNode>>::iterator i = this->adj.begin();
            i != adj.end();
            i++
        ) {
            if (i->begin()->name == source) {
                for (
                    std::list<GraphNode>::iterator j = i->begin();
                    j != i->end();
                    j++
                ) {
                    if (j->name == dest) {
                        std::cout
                            << "(" 
                            << source 
                            << ", " 
                            << dest 
                            << ") is an existing edge." 
                            << std::endl
                        ;
                        return;
                    }
                }
                GraphNode newDest(dest, weight);
                i->push_back(newDest);
                if (first) {
                    this->addEdge(dest, source, weight, false);
                    this->numEdges++;
                }
            }
        }
    }
    void show() {
        std::cout << "Graph with " << this->numVerts << " vertices and " << this->numEdges << " edges:" << std::endl;
        for (
            std::list<std::list<GraphNode>>::iterator i = this->adj.begin();
            i != adj.end();
            i++
        ) {
            for (
                std::list<GraphNode>::iterator j = i->begin();
                j != i->end();
                j++
            ) {
                if (j == i->begin()) std::cout << j->name << ": ";
                else std::cout << j->name << "(" << j->weight << ") ";
            }
            std::cout << std::endl;
        }
    }
    void printAdjacencyMatrix() {
        std::cout << "are bhai method banaane to do" << std::endl;
    }
    void printIncidenceMatrix() {
        std::cout << "are bhai method banaane to do" << std::endl;
    }
};

int main() {
    Graph G;
    G.addVertex("A");
    G.addVertex("B");
    G.addEdge("A", "B");
    G.addEdge("B", "A", 2);
    G.show();
    Graph a;
    a.addVertex("1");
    a.addVertex("2");
    a.addVertex("3");
    a.addVertex("4");
    a.addVertex("5");
    a.addVertex("6");
    a.addVertex("7");
    a.addVertex("8");
    a.addEdge("1", "2");
    a.addEdge("1", "3");
    a.addEdge("1", "4");
    a.addEdge("2", "5");
    a.addEdge("2", "6");
    a.addEdge("3", "5");
    a.addEdge("3", "7");
    a.addEdge("4", "6");
    a.addEdge("4", "7");
    a.addEdge("5", "8");
    a.addEdge("6", "8");
    a.addEdge("7", "8");
    a.show();
    a.printAdjacencyMatrix();
    a.printIncidenceMatrix();
    return 0;
}