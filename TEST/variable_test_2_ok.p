func main() : void
{
    func f( 
        a : int
        ) : int
    {
        func f( 
            b : int
            ) : int
        {
            if true 
            {
                a = b;
            } 
            else 
            {
                if true 
                {
                    return 2;
                }

                b = 0;

                if a < 3 
                {
                    return 3;
                }
            }
        }
    
        if f( 1 ) == 1 
        {
            write 1;
        }

        return 0;
    }

    func g( 
        a : int
        ) : int
    {
        func g( 
            b : int
            ) : int
        {
            if true 
            {
                a = b;
            } 
            else 
            {
                if true 
                {
                    return 2;
                }

                b = 0;

                if a < 3 
                {
                    return 3;
                }
            }
        }
    
        if g( 1 ) == 1 
        {
            write 1;
        }

        return 0;
    }

    func h( 
        a : int
        ) : int
    {
        func h( 
            b : int
            ) : int
        {
            if true 
            {
                a = b;
            } 
            else 
            {
                if b < 2 
                {
                    return a;
                }

                if a < 3 
                {
                    return 3;
                }
            }

            return 0;
        }
    
        if h( 1 ) == 1 
        {
            return 1;
        }

        return 0;
    }

    func i( 
        a : int
        ) : int
    {
        func i( 
            b : int
            ) : int
        {
            if true 
            {
                a = b;
            } 
            else 
            {
                if b < 2 
                {
                    return a;
                }

                if a < 3 
                {
                    return 3;
                }
            }

            return 0;
        }
    
        if true 
        {
            return i( 1 );
        }

        return 0;
    }

    func j( 
        a : int
        ) : int
    {
        func j( 
            b : int
            ) : int
        {
            if true 
            {
                a = b;
            } 
            else 
            {
                if b < 2 
                {
                    return a;
                }

                if a < 3 
                {
                    return 3;
                }
            }

            return 0;
        }
    
        if true 
        {
            return j( 1 );
        }

        a = 0;

        return 0;
    }

    func k( 
        a : int
        ) : int
    {
        func k( 
            b : int
            ) : int
        {
            if true 
            {
                return b;
            } 
            else 
            {
                if true 
                {
                    return b;
                }

                if a < 3 
                {
                    return 3;
                }
            }

            b = 0;

            return 0;
        }
    
        if k( 1 ) == 1 
        {
            return 1;
        }

        return 0;
    }

    var
        x : int,
        y : int;

    x = f( x + 2 );
}
