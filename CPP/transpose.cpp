#include <iostream>

using namespace std;

int ** transpose(const int *const *m, unsigned rows, unsigned cols){
    // int T[cols][rows];
    int **T = new int *[cols];
    T[0] = new int[cols*rows];
    for(size_t i=1; i!=cols; ++i){
        T[i]=T[i-1]+rows;
    }
    for (size_t i = 0; i!=cols; ++i){
        for (size_t j = 0; j!=rows; ++j){
            T[i][j]=m[j][i];
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
    return T;
}

int main()
{
    int mq[3] ={1, 2, 3};
    int mp[3] ={4, 5, 6};
    int *m[2] = {mq, mp};
    int ** T = transpose(m, 2, 3);
    // for (size_t i = 0; i!=3; ++i){
    //     for (size_t j = 0; j!=2; ++j){
    //         cout<<T[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    return 0;
}