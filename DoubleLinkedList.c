#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* prev;
	struct node* next;
	char* value;
} node_t;//Double linked list


int main(int argc,char* argv[]){
	node_t *first_node = (node_t*)(malloc(sizeof(node_t)));
	node_t *second_node = (node_t*)(malloc(sizeof(node_t)));
	first_node->prev = NULL;
	first_node->next = second_node;
	first_node->value = malloc(30);
	
	second_node->prev =  first_node;
	second_node->next = NULL;
	second_node->value = malloc(30);

	free(first_node);
	free(second_node);
	return 0;
}

//According to ChatGPT this code is shit, but its mine :)
//My instinct also told me there must be a better way gg
int insert(node_t  *current, node_t *new){
	if(current->next == NULL){
		current->next = new;
		new->prev = current;
	} else if(current->prev == NULL){
		new->prev = NULL;
		new->next = current;
		current->prev = new;
	} else{
		new->next = current->next;
		current->next->prev = new;
		new->prev = current;
	}
}

