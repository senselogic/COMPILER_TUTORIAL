func main(
    ) : void
{
    func f( 
        a : int 
        ) : int
    {
        var
            b : int,
            c : int;
            
        if b < 4 
        { 
            return f( c ); 
        }
    }

    var
        x : int,
        y : int;

    x = f( x + 2 );
}
