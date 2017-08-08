func main() : void
{
    var 
        c : int,
        b : bool,
        x : int,
        y : int,
        z : int,
        i : int;
    
    func Compare( 
        x : bool, 
        y : bool 
        ) : void
    {
        c = c + 1;

        if ( x ) 
        {
            write 1;
        } 
        else 
        {
            write 0;
        }

        if ( y ) 
        {
            write 1;
        } 
        else 
        {
            write 0;
        }

        if ( x == y ) 
        {
            write 11100 + c;
        } 
        else 
        {
            write -99900 - c;
        }                
    }
    
    func Compare( 
        x : int, 
        y : int 
        ) : void
    {
        c = c + 1;

        write x;
        write y;

        if ( x == y ) 
        {
            write 11100 + c;
        } 
        else 
        {
            write -99900 - c;
        }                
    }

    c = 0;

    b = !true;
    Compare( b, false );
    Compare( !true, false );
    Compare( !( true ), false );

    b = !!!true;
    Compare( b, false );
    Compare( !!!true, false );
    Compare( !( !( !( true ) ) ), false );

    b = true || false && true;
    Compare( b, true );
    Compare( true || false && true, true );
    Compare( ( true || false ) && true, true );

    Compare( false || false, false );
    Compare( true || false, true );
    Compare( false || true, true );
    Compare( true || true, true );

    Compare( false || false || false, false );
    Compare( true || false || false, true );
    Compare( false || true || false, true );
    Compare( false || false || true, true );
    Compare( true || true || false, true );
    Compare( true || false || true, true );
    Compare( false || true || true, true );
    Compare( true || true || true, true );

    Compare( false && false, false );
    Compare( true && false, false );
    Compare( false && true, false );
    Compare( true && true, true );

    Compare( false && false && false, false );
    Compare( true && false && false, false );
    Compare( false && true && false, false );
    Compare( false && false && true, false );
    Compare( true && true && false, false );
    Compare( true && false && true, false );
    Compare( false && true && true, false );
    Compare( true && true && true, true );

    x = 3;
    y = 5;
    z = 7;

    Compare( x == 3, true );
    Compare( x == 5, false );
    Compare( x == x, true );
    Compare( x == y, false );
    Compare( x < 4, true );
    Compare( x < y, true );
    Compare( z < y, false );
    Compare( x <= 2, false );
    Compare( x <= 3, true );
    Compare( x <= 4, true );

    Compare( ! x == 3, false );
    Compare( ! x == 5, true );
    Compare( ! x == x, false );
    Compare( ! x == y, true );
    Compare( ! x < 4, false );
    Compare( ! x < y, false );
    Compare( ! z < y, true );
    Compare( ! x <= 2, true );
    Compare( ! x <= 3, false );
    Compare( ! x <= 4, false );

    b = x == y * 2 - z;
    Compare( b, true );
    Compare( x == y * 2 - z, true );
    Compare( x == ( ( y * 2 ) - z ), true );
    
    i = x + 3 * y - 5 - z + -10 - -20;
    Compare( i, 16 );
    Compare( x + 3 * y - 5 - z + -10 - -20, 16 );
    Compare( ( ( ( ( ( x + ( 3 * y ) ) - 5 ) - z ) + -10 ) - -20 ), 16 );

    b = ! x == 3 * 5;
    Compare( b, true );
    Compare( ! x == 3 * 5, true );
    Compare( !( x == ( 3 * 5 ) ), true );

    b = ! x == 3 * 5 && true;
    Compare( b, true );
    Compare( ! x == 3 * 5 && true, true );
    Compare( ( !( x == ( 3 * 5 ) ) ) && true, true );

    b = ! x == 3 * 5 && true || y <= x;
    Compare( b, true );
    Compare( ! x == 3 * 5 && true || y <= x, true );
    Compare( ( ( !( x == ( 3 * 5 ) ) ) && true ) || ( y <= x ), true );

    b = ! x == 3 * 5 && true && y <= x;
    Compare( b, false );
    Compare( ! x == 3 * 5 && true && y <= x, false );
    Compare( ( ( !( x == ( 3 * 5 ) ) ) && true ) && ( y <= x ), false );

    i = 2 + 3 * 4 - 10 / 2;
    Compare( i , 9 );
    Compare( 2 + 3 * 4 - 10 / 2, 9 );
    Compare( ( 2 + ( 3 * 4 ) ) - ( 10 / 2 ), 9 );
}

