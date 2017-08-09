func main(
    ) : void
{
    var 
        i : int;

    func next( 
        i : int 
        ) : int
    {
        return i + 1;
    }

    i = 0;

    if i < 1 
    {
        write next( i );
    }
}

