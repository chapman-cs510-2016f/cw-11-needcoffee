#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK new_stack() {
    STACK new = NULL;
    return new;
}

void push_stack(STACK *s, SVALUE val) {
    STACK new = (STACK) malloc(sizeof(struct stack)); //create a pointer to a stack called new and allocate memory for it
    new->data = val; //set the data in the structure being pointed to by new to val
    new->head = *s; //make new->head point to the same thing s is pointing to 
    *s = new; //make s point to the same thing new is pointing to
}

SVALUE pop_stack(STACK *s) {
    SVALUE val;
    STACK temp;
    if (*s == NULL) { //test to see if stack is empty
      val = -1; //set val to -1 if stack is empty; this will be returned by thr function
    }
    else { //for a non-empty stack
      val = (*s)->data; //set val to the value in the structure being pointed to by s
      temp = (*s);  //make temp point to the same structure s is pointing to
      *s = (*s)->head; //go to the structure being pointed to by s, then set s to that
      free(temp); //free temp, which points to the structure with val, which we want to remove now
    }
    return val; //return the data from the removed structure
}

void print_svalue(SVALUE val) {
    int sVal = (int) val; //cast val to an int
    printf("%i", sVal); //print the value as an int
}

void print_stack(STACK s) {
    while (s != NULL) { //while pointer is pointing to structure with data
        print_svalue(s->data); //print the data
        puts(""); //add a newline
        s = (s->head); //move to the next item in the stack
    } 
}
