func main() : void
{
    var 
        integer : int,
        square : int,
        scope1 : int;

    func square( 
        integer : int 
        ) : int
    {
        var
            square : int;
            
        square = integer * integer;
        write integer;
        write square;
        
        return square;
    }

    func square( 
        ref square : int, 
        integer : int 
        ) : void
    {
        square = square( integer );
    }

    func write1(
        ) : void
    {
        write -11;
        write scope1;
        write -11;
    }

    func scope2( 
        scope2 : int 
        ) : void
    {
        func write2(
            ) : void
        {
            write1();

            write -22;
            write scope1;
            write scope2;
            write -22;
        }

        func scope3( 
            scope3 : int 
            ) : void
        {
            func write3(
                ) : void
            {
                write1();
                write2();

                write -33;
                write scope1;
                write scope2;
                write scope3;
                write -33;
            }

            func scope4( 
                scope4 : int 
                ) : void
            {
                write -4;
                write scope1;
                write scope2;
                write scope3;
                write scope4;
                write -4;

                write1();
                write2();
                write3();
            }
        
            write -3;
            write scope1;
            write scope2;
            write scope3;
            write -3;

            write1();
            write2();
            write3();
            scope4( 444 );
        }
    
        write -2;
        write scope1;
        write scope2;
        write -2;

        write1();
        write2();
        scope3( 333 );
    }

    integer = 5;

    square = 0;
    square = square( integer );
    write integer;
    write square;

    square = 0;
    square = square( 2 + 3 );
    write 2 + 3;
    write square;

    square = 0;
    square( square, integer );
    write integer;
    write square;

    square = 0;
    square( ( square ), 2 + 3 );
    write 2 + 3;
    write square;

    scope1 = 111;

    write -1;
    write scope1;
    write -1;

    write1();
    scope2( 222 );
}

