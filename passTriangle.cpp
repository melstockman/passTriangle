/*
By starting at the top of the triangle and moving to adjacent numbers on the row below, 
the maximum total from top to bottom

5
9 6
4 6 8
0 7 1 5
5 + 9 + 6 + 7 = 27
INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Input example is the following

5
9 6
4 6 8
0 7 1 5
You make also check full input file which will be used for your code evaluation.
OUTPUT SAMPLE:

The correct output is the maximum sum for the triangle. So for the given example the correct answer would be

27



*/


//#include <iostream>
#include <stdio.h>
#include <string.h>
//using namespace std;

int findLargestAdjacentIndex( int prevLargestNumIndex, int *lineOfNums )
{
	if (*(&lineOfNums[prevLargestNumIndex]) > *(&lineOfNums[prevLargestNumIndex+1]) )
		return prevLargestNumIndex;
	else
		return prevLargestNumIndex+1;
}

int main(int argc, char **argv)
{
	FILE *fp;
	int i;
	int numsOnLine;
	int theIndex;
	int lineOfNums[500];
	double total=0;
	//int numScanned; // just to get rid of warnings
	
		
	fp=fopen(argv[1],"r");
	if (fp <= 0)
	{
		printf("Can't open file %s\n", argv[1]);
		return 1;
	} // if
	
	
    numsOnLine = 0;
	theIndex = 0;
	
	while (!feof(fp))
	{
		
	    numsOnLine++;
	    for (i=0;i<numsOnLine;i++)
	    {
			/*numScanned =*/ fscanf(fp,"%d",&lineOfNums[i]);
		    if (lineOfNums[i] == '\n'	)
				continue;
		} 
		//numScanned = fscanf(fp,"\n");
	    if (numsOnLine==1)
			total += *(&lineOfNums[0]);
		else
		{
		    theIndex = findLargestAdjacentIndex(theIndex,&lineOfNums[0]);
		    total += *(&lineOfNums[theIndex]);
		}
	}
    printf("%.0f\n",total);
  
    return 0;
} // main
 
