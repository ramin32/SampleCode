/************************************************************************
 * void_stack.c
 *
 * A generic stack container that can work with int's double's and
 * string's all at the same time.
 *
 *      OUTPUT:
 *      Enter type (d,f,s) or q to quit> d
 *      Enter int> 123
 *      Enter type (d,f,s) or q to quit> s
 *      Enter string> hello world!
 *      Enter type (d,f,s) or q to quit> s
 *      Enter string> C is nice!
 *      Enter type (d,f,s) or q to quit> f
 *      Enter float> 4.5589
 *      Enter type (d,f,s) or q to quit> d
 *      Enter int> 9978
 *      Enter type (d,f,s) or q to quit> q
 *      You entered:
 *      9978
 *      4.558900
 *      C is nice!
 *      hello world!
 *      123
 *
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 * ********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {INT,DOUBLE,STRING} type;

typedef struct node{
    void *data;
    type t;
    struct node *prev;
}node;

/**********************************************************************
 * 
 * returns an initialized chunk of memory, if type is a string then 
 * str_size must be strlen(string);
 * otherwise any numb may be passed.
 * The memory segment is then initialized to the value in data.
 *
 **********************************************************************/
void *get_init_mem(type t,void *data,int str_size){
    int *int_mem;
    double *double_mem;
    char *char_mem;

    if(t == INT){
        int_mem = malloc(sizeof(int));
        *int_mem = *((int *)data);
        return int_mem;
    }
    else if(t == DOUBLE){
        double_mem = malloc(sizeof(double));
        *double_mem = *((double *)data);
        return double_mem;
    }
    else if(t == STRING){
        char_mem = malloc(str_size + 1);
        strcpy(char_mem,data);
        return char_mem;
    }
    return NULL;
}


void push(node **stack,void *data,type t){
    int str_size;
    if(t == STRING)
        str_size = strlen(data);
    else
        str_size = 0;

    node *prev_node = *stack;
    *stack = malloc(sizeof(node));
    (*stack)->data = get_init_mem(t,data,str_size); 
    (*stack)->t = t;
    (*stack)->prev =  prev_node;
}

node *pop(node **stack){
    if(*stack == NULL)
        return NULL;
    node *current_node = *stack;
    *stack = (*stack)->prev;
    return current_node;
}

//prints the contents of a node containing int,double or string
void print_node(node n){
    if(n.t == INT){
        printf("%d\n",*((int *)n.data));
    }
    else if(n.t == DOUBLE){
        printf("%f\n",*(double *)n.data);

    }
    else if(n.t == STRING){
        printf("%s",(char *)n.data);
    }
}

//Free's a node and its contents.
void free_node(node *current_node){
    free(current_node->data);
    free(current_node);
}

int main(){
    node *stack = NULL;
    node *current_node;
    int numb;
    char ch;
    double decimal;
    char str_buffer[80];

    //Interactively push int's, double's or string's
    do{
        printf("Enter type (d,f,s) or q to quit> ");
        scanf(" %c",&ch);
        getchar();   //<--Eat up \n from scanf
        switch(ch){
            case 'd':
                printf("Enter int> ");
                scanf("%d",&numb);
                push(&stack,&numb,INT);
                break;
            case 'f':
                printf("Enter float> ");
                scanf("%lf",&decimal);
                push(&stack,&decimal,DOUBLE);
                break;
            case 's':
                printf("Enter string> ");
                fgets(str_buffer,79,stdin);
                push(&stack,str_buffer,STRING);
                break;
            default:
                if(ch != 'q')
                    printf("Invalid input\n");
                break; 
        }
    }while(ch != 'q');

    //Return if stack is NULL
    if(stack == NULL) return 0;

    //pop and print all pushed elements.
    printf("You entered:\n");
    while(current_node = pop(&stack)){
        print_node(*current_node);
        free_node(current_node);
    }

    return 0;
}
