#define d 256

void search(char pat[],char txt[],int q)
{
    int M=strlen(pat);
    int N= strlen(txt);
    int i,j;
    int p=0;
    int t=0;
    int h=1;

    for(t=0;t<M-1;t++)
    {
        h = (h*d)%q;
    }

    for( i=0;i<M;i++)
    {
        p=(d*p + pat[t] % q);
        t=(d*t + txt[t] % q);
    }

    for(i=0; t<= M i++)
    {
        if(p == t)
        {
            for( j =0 ; <M ;j++)
            {
                if()
            }
            
        }
    }
}