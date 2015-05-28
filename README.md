# c-simple-refs
Basic reference counting implementation in C


## Usage

Simply `#include "ref.h"` into your code. There is nothing else to compile or link. The implementation consists solely of preprocessor macros.

For each type you want to use references with, you must specify `ref_define(type)` somewhere in your headers; for example, we use `ref_define(int)` to define a type for a reference to an integer.

To create an instance of a reference, use `ref_new(type)`; this will give you an instance of the type `ref_type(type)`.

In every function within which you want to use the reference, call `ref_acquire(instance)`; when your function is done with the reference it should call `ref_release(instance)`.

To refer to the value of the instance, use `ref_val(instance)`; this is a macro so you can assign to it as well as read from it.

When the number of acquired references to an instance drops to zero, the instance's memory will automatically be freed.

## Example

    #include "ref.h"
    #include <stdio.h>
    ref_define(long);
    
    int main(int argc, char *argv[]){
        ref_type(long) x = ref_new(long);
        ref_acquire(x);
        ref_val(x) = 123456;
        printf("%ld\n", ref(val(x));
        ref_release(x);
    }
    
## Running the tests

A shell script is included which compiles and runs the 3 included test/example programs. You will need `gcc` and `valgrind` (and `bash`, `grep`, and `awk`) to run this script.

## Caveats

I don't think there's a good way to allocate an array using these references. The only way that will for sure work is to use a `struct` to wrap your array, however this will require the array to be statically sized.

Also, note that using `-Wpedantic` adds a few constraints to the use of `ref_define`. It will generate warnings for (1) having a semicolon after your "call" to `ref_define`, and (2) for "calling" `ref_define` inside a function. I don't know of any functionally valid uses of my macros that will generate warnings if `-Wpedantic` is not used.

<sup>Pedantic aside: You should probably always use `-Wpedantic`, though; I think it makes you a better programmer.</sup>

## License

This code is public domain. See the `LICENSE` file for full details.
