#include <stdio.h>
#include <stdlib.h>
#include "glthread.h"


/*glthread is nothing but a linked list of glnodes*/

void initialize_glthread(glthread_t *glnode) {
	glnode->next = NULL;
	glnode->prev = NULL;
}

void insert_glnode(glthread_t **head, glthread_t *glnode){
	glthread_t **curr, *temp;
	curr = head;
	initialize_glthread(glnode);

	if(!(*curr)) {
		*curr = glnode;
		return 1;
	}
	
	glnode->next = *curr;
	(*curr)->prev = glnode;
	*curr = glnode;
}
emp_t * return_glnode_pointer (glthread_t *curr ){
	return  (emp_t *)( (char *)curr - (char *)offset(emp_t,glnode));
}
void traverse_glnode(glthread_t **head){	
	glthread_t **temp;
	temp = head;
	emp_t *p;
	while(*temp) {
		p = return_glnode_pointer(*temp);
		printf("emp_name = %s emp_project = %s emp_num = %d, emp_salary = %d\n", p->emp_name, p->emp_project,p->emp_num, p->emp_salary);
		temp = &(*temp)->next;
	}

	//	temp = &(*temp)->prev;
	//	p = return_glnode_pointer(*temp);
	//	printf("\nprevemp = %s\n",p->emp_name);

}
int main(int argc, char **argv) {
	glthread_t base_node ;
	initialize_glthread(&base_node);
	
	emp_t *emp1 = (emp_t *) malloc(sizeof(emp_t));
        emp_t *emp2 = (emp_t *) malloc(sizeof(emp_t));
        emp_t *emp3 = (emp_t *) malloc(sizeof(emp_t));
        emp_t *emp4 = (emp_t *) malloc(sizeof(emp_t));
        strcpy(emp1->emp_name,"Arun");
        strcpy(emp1->emp_project,"SAT");
        emp1->emp_salary = 100000;
        emp1->emp_num = 1111;
        strcpy(emp2->emp_name,"Kiran");
        strcpy(emp2->emp_project,"PAT");
        emp2->emp_salary = 100001;
        emp2->emp_num = 1112;
        strcpy(emp3->emp_name,"Parun");
        strcpy(emp3->emp_project,"TAT");
        emp3->emp_salary = 100002;
        emp3->emp_num = 1113;
        strcpy(emp4->emp_name,"Karan");
        strcpy(emp4->emp_project,"MAT");
        emp4->emp_salary = 100003;
        emp4->emp_num = 1114;

	insert_glnode(&base_node,&emp1->glnode);	
	insert_glnode(&base_node,&emp2->glnode);	
	insert_glnode(&base_node,&emp3->glnode);	
	insert_glnode(&base_node,&emp4->glnode);	

        strcpy(emp1->emp_name,"HArun");

	traverse_glnode(&base_node);
	return 1;
}
