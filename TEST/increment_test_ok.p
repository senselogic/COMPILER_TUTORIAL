func main() : void
{
    var 
        b : bool;

    func increment( 
        i : int, 
        ref j : int 
        ) : int
    {
        var
            k : int;
            
        b = !b;
        k = i * 2;

        if b && !j == 0 
        {
            j = i + k;
        } 
        else 
        {
            j = i + 1;
        }

        return i + 1;
    }

    var
        i : int,
        j : int;
 
    b = true;
    i = 1;
    j = i - 1;

    while i < 10 
    {
        i = increment( i, j );
        write j;
    }
}
