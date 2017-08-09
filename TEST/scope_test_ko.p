func main(
    ) : void
{
    func fct1(
        ) : void;
    
    func fct0(
        ) : int
    {
        func fct01(
            ) : int
        {
            func fct012(
                ) : int 
            { 
            }
        {
        }
        
        func fct02(
            ) : int 
        { 
        }
    {
        fct01(); /* valid */
        fct02(); /* valid */
        fct012(); /* invalid */
        
        fct0(); /* valid */
        fct1(); /* valid */
        fct2(); /* invalid */
    }
    
    func fct1(
        ) : void 
    { 
    }
    
    func fct2(
        ) : void 
    { 
    }
}

