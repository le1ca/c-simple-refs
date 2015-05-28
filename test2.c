#include "ref.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    char hello[32];
    long number;
} my_thing;

ref_define(my_thing)

void foo(ref_type(my_thing) x){
        ref_acquire(x);
        printf("%s\n", ref_val(x).hello);
        ref_val(x).number = 123;
        ref_release(x);
}

int main(int argc, char** argv){
        ref_type(my_thing) x = ref_new(my_thing);
        ref_acquire(x);
        
        strncpy(ref_val(x).hello, "Hello world!", 32);
        
        foo(x);
        printf("%ld\n", ref_val(x).number);
        
        printf("\n");
        printf("total acquisitions: %d\n", x->l);
        printf("current references: %d\n", x->c);
        
        ref_release(x);
        return 0;
}
