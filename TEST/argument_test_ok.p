func main() : void
{
    var 
        x : int;

    func f( 
        x : int, 
        y : int 
        ) : int
    {
        return x + y * 2;
    }
    
    func p( 
        x : int, 
        ref y : int 
        ) : void
    {
        write x;
        write y;
    }
    
    func p3( 
        ref x3 : int, 
        y3 : int 
        ) : void
    {
        func p4( 
            ref x4 : int, 
            y4 : int 
            ) : void
        {
            func p5( 
                ref x5 : int, 
                y5 : int 
                ) : void
            {
                write 555;
                p( x5, y5 );
                x5 = x5 + f( x5, y5 );
                p( x5, y5 );
                p( x4, y4 );
                p( x3, y3 );
                write -555;
            }
        
            write 444;
            p( x4, y4 );
            x4 = x4 + f( x4, y4 );
            p5( x4, y4 * 2 );
            p( x4, y4 );
            write -444;
        }
    
        write 333;
        p( x3, y3 );
        x3 = f( x3, y3 );
        p4( x3, y3 * 2 );
        p( x3, y3 );
        write -333;
    }
        
    func p2( 
        ref x2 : int, 
        y2 : int 
        ) : void
    {
        write 222;
        p( x2, y2 );
        x2 = x2 + f( x2, y2 );
        p3( x2, y2 * 2);
        p( x2, y2 );
        write -222;
    }
        
    func p1( 
        ref x1 : int, 
        y1 : int 
        ) : void
    {
        write 111;
        p( x1, y1 );
        x1 = x1 + f( x1, y1 );
        p2( x1, y1 * 2 );
        p( x1, y1 );
        write -111;
    }

    x = 1;
    p1( x, 2 );
}

