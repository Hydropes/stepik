#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

enum move_dir{MD_UP, MD_RIGHT, MD_DOWN, MD_LEFT, MD_NONE};
typedef void (*move_callback)(enum move_dir);

struct callback
{
    move_callback* move;
    struct callback* next;
};

struct callback* node_create(move_callback* dir){
    struct callback* a = (struct callback*)(malloc(sizeof(struct callback)));;
    a->move = dir;
    a->next =NULL;
    return a;
}

void callback_add_front(struct callback** old, move_callback* dir){
    struct callback* new = node_create(dir);
    new->next=*old;
    *old = new;
}

void callback_destroy(struct callback* callback){
    if(callback ==NULL){
        return;
    }
    struct callback* prev = NULL;
    while (callback->next)
    {
        free(prev);
    }
    free(callback);    
}

struct robot{
    const char* name;
    struct callback* stack;
};


void register_callback(struct robot* robot, move_callback new_cb){
    callback_add_front(&(robot->stack), &new_cb);
}

void unregister_all_callback(struct robot* robot){
    callback_destroy(robot->stack);
}

void move(struct robot* robot, enum move_dir dir){
    struct callback* ptr =robot->stack;
    while(ptr){
        register_callback(robot, (void*)dir);
        ptr = ptr->next;
    }
}

int main(){
    
}