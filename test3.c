#include "ref.h"
#include <stdio.h>
ref_define(long)
    
int main(int argc, char *argv[]){
        ref_type(long) x = ref_new(long);
        ref_acquire(x);
        ref_val(x) = 123456;
        printf("%ld\n", ref_val(x));
        ref_release(x);
        return 0;
}
