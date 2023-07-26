bool find(long long int x , long long int i)
{
    if( i == 0 )
        if( arr[i]== x)
            return  true;;
        else 
            return false
    if( n == x )
        return true;
    find(x, i-1)
}