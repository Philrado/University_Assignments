/**
 * 
 */

import java.util.*;

public class GraphNode {
	
	private int node_name;
	private boolean node_mark;

	// This is the constructor for the class and it creates an unmarked node (see below) with the given name. 
	// The name of a node is an integer value between 0 and n-1, where n is the number of nodes in the graph. 
	// A node can be marked with a value that is either true or false using method setMark.
	// This is useful when traversing the graph to know which vertices have already been visited. 
	GraphNode(int name){
		
		this.node_name = name;
	}

	// Marks the node with the specified value. 
	void setMark(boolean mark){
		
		this.node_mark = mark;
	}

	// Returns the value with which the node has been marked. 
	boolean getMark(){

		return node_mark;
	} 

	// Returns the name of the node.
	int getName(){

		return node_name;
	}

	
}
