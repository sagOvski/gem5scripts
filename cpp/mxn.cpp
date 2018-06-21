#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
// using namespace std;


const int   DIM = 64; //works up to 719, crashes at 720
// unsigned concurentThreadsSupported = std::thread::hardware_concurrency();
        
const int num_of_thr = 128;
const int   num_of_core = (sysconf(_SC_NPROCESSORS_ONLN) == 0 || 1 == sysconf(_SC_NPROCESSORS_ONLN)) ? 16 : sysconf(_SC_NPROCESSORS_ONLN);
int         matrix_A[DIM][DIM];
int         matrix_B[DIM][DIM];
int         c[DIM][DIM];

struct v
{
    int i;
    int j;
};

//worker thread
void* matrix_multi(void* data)
{
    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            c[i][j] = 0;
            for(int k = 0; k < DIM; k++)
            {
                c[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
    pthread_exit(0);
}

int main()
{

    pthread_t thr_id[DIM][DIM];
    pthread_attr_t thr_attr;
    pthread_attr_init(&thr_attr);



    //Filling the Matrices
    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            matrix_A[i][j]= i + j;
            matrix_B[i][j] = i + 3;
        }
    }


    //create the threads
    for(int i = 0; i < num_of_thr/2; i++)
    {
        for(int j = 0; j < num_of_thr/2; j++)
        {
            struct v *data = (struct v *) malloc(sizeof(struct v));
            data->i = i;
            data->j = j;
            pthread_create(&thr_id[i][j],NULL,matrix_multi,  &data);

            cpu_set_t cpuset;
            pthread_getaffinity_np(thr_id[i][j], sizeof(cpu_set_t), &cpuset);
            printf("Before Thread : %d %d \n",i, j);
            int k=0;
            for (k = 0; k < CPU_SETSIZE; k++)
                if (CPU_ISSET(k, &cpuset))
                    printf("    CPU %d\n", k);

            CPU_ZERO(&cpuset);
            printf("j num_of_core (j mod num_of_core) : %d %d %d \n", j, num_of_core, (j % num_of_core));
            CPU_SET((j % num_of_core), &cpuset);
            pthread_setaffinity_np(thr_id[i][j], sizeof(cpu_set_t), &cpuset);

            pthread_getaffinity_np(thr_id[i][j], sizeof(cpu_set_t), &cpuset);
            printf("After Thread : %d %d \n",i, j);
            for (k = 0; k < CPU_SETSIZE; k++)
                if (CPU_ISSET(k, &cpuset))
                    printf("    CPU %d\n", k);

            // std::cout<<"pthread: "<<i<<" "<<j<<" get_affinity: "<< cpuset;
        }
    }

    //joining the threads
    for(int i = 0; i < num_of_thr/2; i++)
    {
        for(int j = 0; j < num_of_thr/2; j++)
        {
            pthread_join(thr_id[i][j],NULL);
        }
    }

    return 0;
}
