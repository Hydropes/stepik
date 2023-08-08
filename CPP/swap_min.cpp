#include <iostream>

using namespace std;

void swap_min(int *m[], unsigned rows, unsigned cols){
    int min = 100000;
    int min_row = 0;
    for (int i=0; i!= rows; ++i){
        for (int j=0; j!= cols; ++j){
            if (m[i][j]<min){
                min =m[i][j];
                min_row = i;
            }
        }
    }
    int *tpl= m[min_row];
    m[min_row] = m[0];
    m[0] = tpl;

}

int main()
{
    int mq[3] ={1, 2, 3};
    int mp[3] ={4,0, 6};
    int ml[3] ={7, 8, 9};
    int *m[3] = {mq, mp, ml};
    swap_min(m, 3, 3);
    for (size_t i = 0; i!=3; ++i){
        for (size_t j = 0; j!=3; ++j){
            cout<<m[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}