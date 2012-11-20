#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout<<"Incorrect number of arguements.\nPlease provide an input in the form ./a.out <width> <height>\n";
        return 0;
    }
    int height = atoi(argv[1]), width = atoi(argv[2]);

    clock_t start = clock();

    unsigned char input[width][height];
    int outputX[width][height], outputY[width][height];
    int xMin = 0, xMax = 0, yMin = 0, yMax = 0;
    int count = 1;    
    srand(time(NULL));
    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++)
        {
            input[i][j] = rand() % 256;
            outputX[i][j] = 0;
            outputY[i][j] = 0;
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
    cout<<"dx Matrix";
    for(int i = 0; i < width; i++) // Print out dx matrix
    {
        cout<<"\n";
        for(int j = 0; j < height; j++)
            cout<<outputX[i][j]<<"\t";
    }
    cout<<"\n\nMax: "<<xMax<<"\tMin: "<<xMin;

    cout<<"\n\n\ndy Matrix";
    for(int i = 0; i < width; i++) // Print out dy matrix
    {
        cout<<"\n";
        for(int j = 0; j < height; j++)
            cout<<outputY[i][j]<<"\t";
    }
    cout<<"\n\nMax: "<<yMax<<"\tMin: "<<yMin;
    cout<<"\n\n\nRun time: "<<(double)(clock() - start)/(float)CLOCKS_PER_SEC << "\n";

}
