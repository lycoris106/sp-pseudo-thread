#include "threadutils.h"

void BinarySearch(int thread_id, int init, int maxiter)
{
    ThreadInit(thread_id, init, maxiter);
    /*
    Some initilization if needed.
    */
    if (setjmp(Current->Environment) == 0)
        longjmp(MAIN, 1);
    for (Current->i = 0; Current->i < Current->N; ++Current->i)
    {
        sleep(1);
        /*
        Do the computation, then output result.
        Call ThreadExit() if the work is done.
        */
        /* x stores init, y stores l, z stores right */
        if (Current->z < Current->y){
            ThreadExit();
        }
        int mid = (Current->z + Current->y)/2;
        printf("BinarySearch: %d\n", mid);
        if (mid == Current->x){
            ThreadExit();
        }
        else if (mid < Current->x){
            Current->y = mid+1;
        }
        else{
            Current->z = mid-1;
        }

        ThreadYield();
    }
    ThreadExit();
}

void BlackholeNumber(int thread_id, int init, int maxiter)
{
    ThreadInit(thread_id, init, maxiter);
    /*
    Some initilization if needed.
    */
    if (setjmp(Current->Next->Environment) == 0)
        longjmp(MAIN, 1);
    for (Current->i = 0; Current->i < Current->N; ++Current->i)
    {
        sleep(1);
        /*
        Do the computation, then output result.
        Call ThreadExit() if the work is done.
        */
        int a = Current->x / 100;
        int b = (Current->x % 100) / 10;
        int c = (Current->x % 10);
        int inc, dec;
        if (a >= b){
            if (b >= c){
                dec = Current->x;
                inc = c*100+b*10+a;
            }
            else if (a >= c){
                dec = a*100+c*10+b;
                inc = b*100+c*10+a;
            }
            else{
                dec = c*100+a*10+b;
                inc = b*100+a*10+c;
            }
        }
        else{
            if (b < c){
                dec = c*100+b*10+a;
                inc = Current->x;
            }
            else if (a >= c){
                dec = b*100+a*10+c;
                inc = c*100+a*10+b;
            }
            else{
                dec = b*100+c*10+a;
                inc = a*100+c*10+b;
            }
        }
        int result = dec-inc;
        printf("BlackholeNumber: %d\n", result);
        if (result == 495){
            ThreadExit();
        }
        else{
            Current->x = result;
        }

        ThreadYield();
    }
    ThreadExit();
}

void FibonacciSequence(int thread_id, int init, int maxiter)
{
    ThreadInit(thread_id, init, maxiter);
    /*
    Some initilization if needed.
    */
    if (setjmp(Current->Prev->Environment) == 0)
        longjmp(MAIN, 1);
    for (Current->i = 0; Current->i < Current->N; ++Current->i)
    {
        sleep(1);
        /*
        Do the computation, then output result.
        */
        int result = Current->y+Current->z;
        printf("FibonacciSequence: %d\n", result);
        Current->y = Current->z;
        Current->z = result;

        ThreadYield();
    }
    ThreadExit();
}