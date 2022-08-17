#include<stdio.h>
int main()
{
    int state=0,i=0;
    char token,input[20];
    printf("Enter input string \t :");
    scanf("%s",input);
    while((token=input[i++])!='\0')
    {
        switch(state)
        {
            case 0: if(token=='a')
                        state=3;
                    else if(token=='b')
                        state=1;
                    else
                    {
                        printf("Invalid token");
                        return 0;
                    }
                    break;
            case 1: if(token=='a')
                        state=3;
                    else if(token=='b')
                        state=2;
                    else
                    {
                        printf("Invalid token");
                        return 0;
                    }

                    break;
            case 2: if(token=='a')
                        state=3;
                    else if(token=='b')
                        state=2;
                    else
                    {
                        printf("Invalid token");
                        return 0;
                    }
                    break;
            case 3: if(token=='a')
                        state=4;
                    else if(token=='b')
                        state=1;
                    else
                    {
                        printf("Invalid token");
                        return 0;
                    }
                    break;
          case 4: if(token=='a')
                        state=4;
                    else if(token=='b')
                        state=1;
                    else
                    {
                        printf("Invalid token");
                        return 0;
                    }
                    break;
        }
    }
    if(state==2||state==4)
        printf("\n\nString accepted\n\n");
    else
        printf("\n\nString not accepted\n\n");
}
