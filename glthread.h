#ifndef __GLTHREAD_H__
#define __GLTHREAD_H__


typedef struct glthread_ glthread_t;



typedef struct glthread_ {
	struct glthread_ *next;
	struct glthread_ *prev;
}glthread_t;

typedef struct employee_ {
        //char *emp_name;
        char emp_name[20];
        char emp_project[20];
        int emp_num;
        int emp_salary;
	glthread_t glnode;
}emp_t;


#define offset(struct_name, fld_name) \
    (unsigned int)&(((struct_name *)0)->fld_name)

#endif /*__GLTHREAD_H*/
