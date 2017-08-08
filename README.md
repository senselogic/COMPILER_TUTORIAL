# P-Code Tutorial

## Purpose

Shows how to translate a minimalistic Go-like language to P-Code instructions, using Flex and Bison.

## Example

```go
func main(
    ) : void
{
    func GetFibonacci( 
        index : int 
        ) : int
    {
        var
            fibonacci : int;
            
        if index < 2 
        {
            fibonacci = index;
        } 
        else 
        {
            fibonacci = GetFibonacci( index - 1 ) + GetFibonacci( index - 2 );
        }
        
        return fibonacci;
    }

    func SetFibonacci( 
        ref fibonacci : int, 
        index : int 
        ) : void
    {
        fibonacci = GetFibonacci( index );
    }

    var
        fibonacci : int;
    
    fibonacci = GetFibonacci( 8 );
    write fibonacci;

    SetFibonacci( fibonacci, 8 );
    write fibonacci;
}
```

```go
ssp 0
ujp @program
define @function_int_GetFibonacci_int_of_void_main
ssp 7
lda i 0 5
ind i
ldc i 2
les i
fjp @if_else_1
lda i 0 6
lda i 0 5
ind i
sto i
ujp @if_end_1
define @if_else_1
lda i 0 6
mst 1
lda i 0 5
ind i
ldc i 1
sub i
cup 1 @function_int_GetFibonacci_int_of_void_main
mst 1
lda i 0 5
ind i
ldc i 2
sub i
cup 1 @function_int_GetFibonacci_int_of_void_main
add i
sto i
define @if_end_1
lda i 0 0
lda i 0 6
ind i
sto i
retf
retf
define @function_void_SetFibonacci_int_int_of_void_main
ssp 7
lod a 0 5
mst 1
lda i 0 6
ind i
cup 1 @function_int_GetFibonacci_int_of_void_main
sto i
retp
define @function_void_main
ssp 7
lda i 0 5
mst 0
ldc i 8
cup 1 @function_int_GetFibonacci_int_of_void_main
sto i
lda i 0 5
ind i
prin
mst 0
lda i 0 5
ldc i 8
cup 2 @function_void_SetFibonacci_int_int_of_void_main
lda i 0 5
ind i
prin
retp
define @program
mst 0
cup 0 @function_void_main
stp
```

## Version

1.0

## Author

Eric Pelzer (ecstatic.coder@gmail.com).

## License

This project is licensed under the GNU General Public License version 3.

See the [LICENSE.md](LICENSE.md) file for details.
