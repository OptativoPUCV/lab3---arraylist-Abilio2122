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
    return n;
}

void append(ArrayList * l, void * data){

  if(l->size==l->capacity)
  {
    l->data=realloc(l->data,sizeof(void)*2);
    l->capacity= (l->capacity)*2;
    l->data[l->size]=data;
    l->size++;
  }
  else{ 
    l->data[l->size]=data;
    l->size++;
  }
}

void push(ArrayList * l, void * data, int i){
  if(i>l->size) return;
  if(l->size==l->capacity)
  {
    l->data=realloc(l->data,sizeof(void)*2);
    l->capacity= (l->capacity)*2;
  }
  if(i<l->size)
  {
    for(int j=l->size; j>i; j--){
      l->data[j] = l->data[j-1];
    }
    l->data[i]=data;
    l->size++;
  }

}

void* pop(ArrayList * l, int i){
  void *aux=l->data[i];

  if (l->size == 0){
    return NULL;
  }
  if(i>l->size)
    return NULL;
  
  if(i<0){
    int pos = l->size + i;
    for(int j=pos;j<l->size;j++){
      l->data[j]=l->data[j+1];
    }
  }
  else{
    for(int j=i;j<l->size;j++){
      l->data[j]=l->data[j+1];
    }
  }
  
  l->size--;
  
  return aux;
  
}

void* get(ArrayList * l, int i){
    if(i>=l->size)
      return NULL;
  
    if(i<0){
      
      if(l->capacity==0)
      return NULL;
      
     return l->data[l->size+i]; 
    }
      
    return l->data[i];

}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
  l->capacity=2;
  l->size=0;
  l->data=(void*) malloc(sizeof(void) * l->capacity);;
}
