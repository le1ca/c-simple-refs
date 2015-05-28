#ifndef _ref_h_
#define _ref_h_

#include <stdlib.h>

#define ref_type(type)          ref_to_##type *
#define ref_define(type)        typedef struct ref_to_##type##_s {unsigned c, l; type *o;} ref_to_##type;       \
                                ref_type(type) ref_new_##type () {                                              \
                                        type *o = (type *) malloc(sizeof(type));                                \
                                        ref_type(type) r = ((ref_type(type)) malloc(sizeof(ref_to_##type)));    \
                                        r->o = o;                                                               \
                                        r->c = 0;                                                               \
                                        r->l = 0;                                                               \
                                        return r;                                                               \
                                }
#define ref_new(type)           ref_new_##type ()
#define ref_acquire(ref)        {ref->c++; ref->l++;}
#define ref_release(ref)        if(!--ref->c){free(ref->o); free(ref);}
#define ref_val(ref)            (*(ref->o))

#endif
