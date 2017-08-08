func main(
    ) : void
{
    var
        power : int,
        square : int;

    func GetRecursivePower( 
        basis : int, 
        exponent : int 
        ) : int
    {
        var
            power : int; 
            
        if ( exponent == 0 ) 
        {
            power = 1;
        } 
        else 
        {
            power = basis * GetRecursivePower( basis, exponent - 1 );
        }
        
        return power;
    }

    func SetRecursivePower( 
        ref power : int, 
        basis : int, 
        exponent : int 
        ) : void
    {
        if ( exponent == 0 ) 
        {
            power = 1;
        } 
        else 
        {
            SetRecursivePower( power, basis, exponent - 1 );
            power = power * basis;
        }
    }

    func GetPower( 
        basis : int, exponent : int ) : int
    {
        var
            power : int; 
            
        power = 1;

        while ( 0 < exponent )
        {
            power = power * basis;
            exponent = exponent - 1;
        }

        return power;
    }

    func SetPower( 
        ref power : int, 
        basis : int, 
        exponent : int 
        ) : void
    {
        power = GetPower( basis, exponent );
    }

    func GetSquare( 
        basis : int 
        ) : int
    {
        var
            square : int;
            
        square = GetPower( basis, 2 );

        return square;
    }

    func SetSquare( 
        ref square : int, 
        basis : int 
        ) : void
    {
        SetPower( square, basis, 2 );
    }

    power = GetRecursivePower( 5, 2 );
    write power;

    SetRecursivePower( power, 5, 2 );
    write power;

    power = GetPower( 5, 2 );
    write power;

    SetPower( power, 5, 2 );
    write power;

    square = GetSquare( 5 );
    write square;

    SetSquare( square, 5 );
    write square;
}

