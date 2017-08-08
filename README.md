# P-Code Tutorial

## Purpose

Shows how to translate a minimalistic Go-like imperative language to P-Code instructions, using Flex and Bison.

## Samples

```
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

## Version

1.0

## Author

Eric Pelzer (ecstatic.coder@gmail.com).

## License

This project is licensed under the GNU General Public License version 3.

See the [LICENSE.md](LICENSE.md) file for details.
