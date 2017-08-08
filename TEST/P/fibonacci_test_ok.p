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

