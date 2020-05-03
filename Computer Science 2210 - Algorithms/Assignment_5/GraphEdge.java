/**
 * 
 */

import java.util.*;

public class GraphEdge {
	
	private GraphNode firstEndpoint, secondEndpoint;
	private char busLineOfEdge;

	// The constructor for the class.
	// The first two parameters are the endpoints of the edge. The last parameter is the bus line to which 
	// the street represented by the edge belongs.
	// Each bus line has a name that consists of a single character: Either a digit or a letter, except ’S’ and ’D’
	// which are used to mark the starting point and the destination.
	// For example ’a’, ’I’, and ’2’ might be the names of three bus lines.
	// Note that case matters, so a bus line might have name ’a’ and another might have name ’A’.                
	// There might be bus lines called ’s’ or ’d’, but no bus line can be called ’S’ or ’D’. 
	GraphEdge(GraphNode u, GraphNode v, char busLine){

		this.firstEndpoint = u;
		this.secondEndpoint = v;
		this.busLineOfEdge = busLine;
	}

	// Returns the first endpoint of the edge.
	GraphNode firstEndpoint(){
		
		return firstEndpoint;
	}

	// Returns the second endpoint of the edge.
	GraphNode secondEndpoint(){

		return secondEndpoint;
	}

	// Returns the name of the busLine to which the edge belongs.
	char getBusLine(){

		return busLineOfEdge;
	}

}
