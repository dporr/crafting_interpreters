#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define FIELD_SIZE 30

typedef struct node {
	struct node* prev;
	struct node* next;
	char* value;
} node_t;//Double linked list


node_t *HEAD;

int main(int argc,char* argv[]){
	node_t *first_node = (node_t*)(malloc(sizeof(node_t)));
	node_t *second_node = (node_t*)(malloc(sizeof(node_t)));
	HEAD = first_node;
	first_node->prev = NULL;
	first_node->next = second_node;
	first_node->value = malloc(FIELD_SIZE);
	
	second_node->prev =  first_node;
	second_node->next = NULL;
	second_node->value = malloc(FIELD_SIZE);
	strncpy(first_node->value, "Im the first", FIELD_SIZE);
	strncpy(second_node->value, "Im the SECOND", FIELD_SIZE);
	find("AA");
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

//Transverse -> derreference value -> compare with searched value
int find(char *value){
	node_t *current = HEAD;
	while(current){
		if(strcmp(current->value, value) == 0){
			return 1;
		}
		current = current->next;
	}
	return -1;
}
int delete(node_t *node){
	if(node == NULL) return -1;
	node->next->prev = node->prev;
	node->prev->next = node->next;
	free(node);
	return 1;
}