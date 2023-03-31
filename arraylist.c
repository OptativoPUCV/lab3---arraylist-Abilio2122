#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
    ArrayList *n= (ArrayList *) malloc(sizeof(ArrayList));
    n->data= (void **) malloc(sizeof(void));
    n->capacity=2;
    n->size=0;
    n->data=(void*) malloc(sizeof(void) * n->capacity);
    return n;
}

void append(ArrayList * l, void * data){
  if(l->size==l->capacity)
  {
    l->data=realloc(l->data,sizeof(void)*2);
    l->capacity= (l->capacity)*2;
  }
  l->data[l->size]=data;
  l->size++;
}

void push(ArrayList * l, void * data, int i){
  if(i>l->size) return;
  if(l->size==l->capacity)
  {
    l->data=realloc(l->data,sizeof(void)*2);
    l->capacity= (l->capacity)*2;
  if(i<l->size)
  {
    for(size_t i=0;i<l->size;i++)
    {
      l->data[i]=l->data[i+1];
    }
    l->data[i]=data;
    l->size++;
  }

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
