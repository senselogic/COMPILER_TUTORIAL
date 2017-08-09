func main(
    ) : void
{ 
    var 
        b : bool,
        i : int;
        
    b = true;

    if ( b ) 
    {
        i = 1;
    } 
    else 
    {
        i = 0;
    }

    write i;

    if ( !b ) 
    {
        i = 0;
    } 
    else 
    {
        i = 1;
    }

    write i;
}

