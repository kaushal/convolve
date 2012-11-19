#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
    int height, width;

    cout<<"Please enter the height: ";
    cin>>height;
    cout<<"Please enter the width: ";
    cin>>width;
    
    clock_t start = time(0);

    int input[width][height];
    int outputX[width][height], outputY[width][height];
    int xMin = 0, xMax = 0, yMin = 0, yMax = 0;
    
    srand(time(NULL));
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            input[i][j] = rand() % 256;
            cout<<input[i][j]<< "\t";
            outputX[i][j] = 0;
            outputY[i][j] = 0;
        }
        cout<<"\n";
    }
    int j = 0, i = 0; 
    for(i = 0; i < width; i++) // Loops that apply the [-1, 0, 1] vertical and horizontal filters
    {
        for(j = 0; j < height; j++)
        {
            bool setX = false, setY = false;
            if(j == 0)
            {
                outputX[i][j] += input[i][j+1];
                setX = true;
            }
            else if(j == height - 1)
            {
                outputX[i][j] += -1 * input[i][j-1];
                setX = true;
            }
            if(i == 0)
            {
                outputY[i][j] += input[i+1][j];
                setY = true;
            }
            else if(i == width - 1)
            {
                outputY[i][j] += -1 * input[i-1][j];
                setY = true;
            }
            if(!setX)
            {
                outputX[i][j] += input[i][j-1] * -1;
                outputX[i][j] += input[i][j+1];
            }
            if(!setY)
            {
                outputY[i][j] += input[i-1][j] * -1;
                outputY[i][j] += input[i+1][j];
            }
            // Statements to calculate mina and max values
            if(outputX[i][j] < xMin)
                xMin = outputX[i][j];
            if(outputX[i][j] > xMax)
                xMax = outputX[i][j];
            if(outputY[i][j] < yMin)
                yMin = outputY[i][j];
            if(outputY[i][j] > yMax)
                yMax = outputY[i][j];
        }
    }
    cout<<"\ndx Matrix\n";
    for(int i = 0; i < width; i++)
    {
        cout<<"\n";
        for(int j = 0; j < height; j++)
            cout<<outputX[i][j]<<"\t";
    }
    cout<<"\nMax: "<<xMax<<"\tMin: "<<xMin;

    cout<<"\n\ndy Matrix\n";
    for(int i = 0; i < width; i++)
    {
        cout<<"\n";
        for(int j = 0; j < height; j++)
            cout<<outputY[i][j]<<"\t";
    }
    cout<<"\nMax: "<<yMax<<"\tMin: "<<yMin;
    cout<<"\nRun time: "<<(double)(time(0) - start)/CLOCKS_PER_SEC << "\n";

}
