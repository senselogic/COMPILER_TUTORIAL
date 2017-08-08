func main(
    ) : void
{
    func GetSquare( 
        value : int 
        ) : int
    {
        var
            square : int;
            
        if value < 2 
        {
            square = value;
        } 
        else 
        {
            square = value * value;
        }

        return square;
    }

    func SetSquare( 
        ref square : int, 
        value : int 
        ) : void
    {
        square = GetSquare( value );
    }

    var
        square : int;

    square = GetSquare( 5 );
    write square;

    SetSquare( square, 5 );
    write square;
}
