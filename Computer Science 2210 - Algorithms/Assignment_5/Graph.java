/**
 * 
 */

import java.util.*;

public class Graph {

	private int Node [] list_graph;
	private GraphEdge [][] list_edges;
	
	// Creates a graph with n nodes and no edges. This is the constructor for the class. The names of the nodes are 0,1,... , n-1. 
	Graph(int n){
		
		
	}
	
	// Adds an edge connecting u and v and belonging to the specified bus line. 
	// This method throws a GraphException if either node does not exist or if in the graph there is 
	// already an edge connecting the given nodes.
	void insertEdge(GraphNode u, GraphNode v, char busLine){
		
		
	}

	// Returns the node with the specified name. If no node with this name exists, the method should throw // a GraphException. 
	GraphNode getNode(int name){

	}

	// Returns a Java Iterator storing all the edges incident on node u. It returns null if u does not have any // edges incident on it. 
	Iterator<GraphEdge> incidentEdges(GraphNode u){

	}
	// Returns the edge connecting nodes u and v. This method throws a GraphException if there is no edge // between u and v.
	GraphEdge getEdge(GraphNode u, GraphNode v){

	}
	// Returns true if nodes u and v are adjacent; it returns false otherwise.
	boolean areAdjacent(GraphNode u, GraphNode v){

	}
	
}
