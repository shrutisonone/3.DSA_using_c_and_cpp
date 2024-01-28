#include<stdio.h>
#include<string.h>

void removeChar(char str[],const char *removeChars)
int srcind,destind,
int auxi[256];

for(srcind=0;srcind<256;srcind++)
{
    auxi[srcind]=0;
}
srcindex=0;

while(removeChars[srcind])
{
    auxi[removeChars[srcind]]=1;
    srcind++;
}

srcind=destind=0;
while(str(srcind++))
{
    if(!auxi[str[srcind]])
      str[dest]
}