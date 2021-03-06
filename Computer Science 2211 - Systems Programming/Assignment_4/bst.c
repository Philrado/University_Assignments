#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Input: �size�: size of an array
// Output: a pointer of type BStree,
// 	i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
// 	allocate memory for a Node array of size+1 for member tree_nodes
// 	allocate memory for an unsigned char array of size+1 for member is_free
// 	set all entries of is_free to 1
// 	set member size to �size�;
BStree bstree_ini(int size) {
	BStree *BStree_pointer;
	Node *tree_node_pointer;
	unsigned char *is_free_pointer;

	*BStree_pointer = (BStree_struct*) malloc(sizeof(BStree_struct));
	*tree_node_pointer = (Node*) malloc(sizeof(size+1));
	*char_pointer = (unsigned char*) malloc(sizeof(size+1));

	int i;
	for (i=0; i<size+1; i++){
		is_free[i] = 1;
	}

	BStree_struct.size -> size = size;

	return *BStree_pointer;
}

// SELF MADE.
// Input: �bst�: a binary search tree
// 	�key�: a pointer to Key
//	�data�: an integer
// Effect: finds the position of the key with data in the bst.
int bstree_search(BStree bst, Key *key, int data) {

    int i;

	if (bst -> tree_nodes[i] == NULL) return 0;
	else if (bst -> tree_nodes[i].data == data) return 1;
	else if (bst -> tree_nodes[i].data < data) return bstree_search (bst -> tree_nodes[i*2], key, data);
	else if (bst -> tree_nodes[i].data > data) return bstree_search (bst -> tree_nodes[i*2+1], key, data);
	return -1;
}

// Input: �bst�: a binary search tree
// 	�key�: a pointer to Key
//	�data�: an integer
// Effect: �data� with �key� is inserted into �bst�
// 	if �key� is already in �bst�, do nothing
void bstree_insert(BStree bst, Key *key, int data) {

    if (bstree_insert(bst, *key, data) == 1) break;

	// if the array is empty, just insert.
	if (bst -> is_free[key] == '1'){
		bst -> tree_nodes[key].key = key;
        bst -> tree_nodes[key].data = data;
        break;
	}
    else {
        // Otherwise while the first key is smaller then the second key:
        if(key_comp(key, bst -> tree_nodes[1].key) > 0){
            bstree_insert(bst -> tree_nodes*2+1, key, data)
        }
        if (key_comp(key, bst -> tree_nodes[1].key) < 0) {
            bstree_insert(bst -> tree_nodes*2, key, data)
        }
    }
}

// Input: �bst�: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
	int n = 1;

	if (bst -> tree_nodes[n] == NULL) return;

	bstree_traversal (bst -> tree_nodes[n*2]);
	print_node(bst -> tree_nodes[n]);
	bstree_traversal (bst -> tree_nodes[n*2+1]);
}

// Input: �bst�: a binary search tree
// Effect: all memory used by bst are freed
void bstree_free(BStree bst) {
	free(tree_nodes);
	free(is_free);
	free(bst);
}
