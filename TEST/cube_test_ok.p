func main() : void
{
    var 
        integer : int,
        cube : int;

    func cube( 
        integer : int 
        ) : void
    {
        func square( 
            ref square : int, 
            integer : int 
            ) : void
        {
            square = integer * integer;
        }

        func cube( 
            integer : int 
            ) : int
        {
            var
                square : int;
                
            square( square, integer );

            return integer * square;
        }
    
        cube = cube( integer );
    }

    integer = 1;

    while integer <= 4 
    {
        cube( integer );

        if cube == integer * integer * integer 
        {
            write cube;
        } 
        else 
        {
            write -1;
        }
        
        integer = integer + 1;
    }
}

