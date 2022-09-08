#include<iostream>
#include<unistd.h>
#include<iomanip>
using namespace std;

void eulers(double x, double y, double stepSize);

int main(int argc, char const *argv[])
{
    FILE *sennin;
    sennin = fopen("output.txt", "a+");
    if(sennin == NULL){
        printf("The File handling error !!\n");
    }
    int file = fileno(sennin);
    int copy = dup(STDOUT_FILENO);

    dup2(file, STDOUT_FILENO);
    eulers(0,1,0.1);
    cout << "----------------------------------------------" << endl;
    eulers(0,1,0.05);
    cout << "----------------------------------------------" << endl;
    eulers(0,1,0.01);
    cout << "----------------------------------------------" << endl;

    fflush(stdout);
    fclose(sennin);
    dup2(copy, STDOUT_FILENO);
    // eulers()
    return 0;
}

void eulers(double x, double y, double stepSize)
{
    double ans;
    while (x < 1)
    {
        ans = y + (stepSize * y);
        y = ans;
        // printf("x: %f and y(x): %f \n", x, y); 
        cout << "X: " << setw(4) << x  << "     y(x): " << setw(4)<< y << endl;
        x += stepSize;
    }
};
