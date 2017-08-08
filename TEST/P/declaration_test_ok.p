func main(
    ) : void
{
    var
        a : int,
        b : bool;
    
    func fct1( 
        ref a : int, 
        b : bool 
        ) : void;
    
    func fct0(
        ) : int
    {
        var
            a : int;
            
        read a;
        return a;
    }
    
    func fct1( 
        ref a : int, 
        b : bool 
        ) : void
    {
        if ( b ) 
        {
            a = a+1;
        } 
        else 
        {
            a = a-1;
        }
    }
    
    a = fct0();
    b = a <= 0;
    fct1( a, b );
    write a;
}


