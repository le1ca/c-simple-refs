#include "ref.h"
#include <stdio.h>

ref_define(int)

void foo(ref_type(int) x){
        ref_acquire(x);
        printf("foo: %3d\n", ref_val(x));
        ++ref_val(x);
        ref_release(x);
}

void bar(ref_type(int) x){
        ref_acquire(x);
        printf("bar: %3d\n", ref_val(x));
        ref_val(x) *= -1;
        ref_release(x);
}

int main(int argc, char** argv){
        ref_type(int) newint = ref_new(int);
        ref_acquire(newint);
        
        ref_val(newint) = 42;
        foo(newint);
        bar(newint);
        
        printf("baz: %d\n", ref_val(newint));
        
        printf("\n");
        printf("total acquisitions: %d\n", newint->l);
        printf("current references: %d\n", newint->c);
        
        ref_release(newint);
        return 0;
}
