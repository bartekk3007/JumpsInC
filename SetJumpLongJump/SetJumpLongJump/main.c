#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>


int main() 
{
    int val;
    int val2 = 0;
    jmp_buf env_buffer;
    jmp_buf env2;

    val2 = setjmp(env2);
    if (val2 != 0)
    {
        printf("Tak\n");
    }

    val = setjmp(env_buffer);

    printf("Jump function call\n");
    //jmpfunction(env_buffer);
    
    if (val != 0) 
    {
        printf("Returned from a longjmp() with value = %d\n", val);
        //exit(0);
    }
    
    longjmp(env_buffer, 0);

    return(0);
}

