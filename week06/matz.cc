#include <iostream>
#include <sstream>

using namespace std;

int countNZ = 0;
/*int noRows;
int colNo;*/

void readArr(int, int, double **);
void formatZ(int, int, double **);

int main(int argc, char *argv[]) {
    int ar = atoi(argv[1]);
    int ac = atoi(argv[2]);

    double **A = new double *[ar];    // each el. of this points to a row of A
    for (int i = 0; i < ar; i++)
        A[i] = new double[ac];    // a row of 'ac' floats

    readArr(ar, ac, A);
    formatZ(ar,ac,A);

    return 0;
}

void readArr(int r, int c, double **arr) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] != 0) {
                countNZ++;
            }
        }
    }
    // code for reading in r rows of c elements each goes here
}

void formatZ(int r, int c, double **arr){
    cout << r << endl;
    for (int i = 0; i < r; i++) {
        ostringstream str;
        int nzRow = 0;
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != 0) {
                nzRow++;
                str << j + 1 << " " << arr[i][j] << " ";
            }
        }
        cout << nzRow << " " << str.str() << endl;
    }
    cout << countNZ << endl;
}

/*
 r
 nz cn cn cn cn
 nz cn cn cn
 nz cn cn cn cn cn cn
 total nz

 */