func main(
    ) : void
{
    func mul( 
        i : int, 
        j : int 
        ) : int;

    func print() : void
    {
        var
            a : int,
            b : int,
            c : int;
            
        read a;
        read b;
        c = mul( a, b );
        write c;
    }

    func mul( 
        i : int, 
        j : int 
        ) : int
    {
        var
            x : int,
            y : int;
            
        x = i;
        y = 0;
    
        while ( 0 < x ) 
        {
            y = y + j;
            x = x - 1;
        }

        return y;
    }

    print();
}

