/********************************************************************************
  *                                                                              *
  * CS 372                                                                       *
  * Recursion Problems                                                           *
  *                                                                              *
  * Description: This program performs recursion operations for                  *
  * many different scenarios.                                                    *
  ********************************************************************************/ 
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ofstream outfile;

//prototypes
void fileHeader();
int numDigits(int nbr);
void printReverse(int nbr);
void reverseArray(int a[], int arySize);
int sumArray(int a[], int n);
int location(int a[], int first, int last, int element);
int GDC(int a, int b);
void printArray(int arr[], int start, int arySize);

/**************************************************
 * Recursion Function #21 - Function that returns *
 * the number of digits in a nonnegative integer  *
 * ***********************************************/
int numDigits(int nbr)
{
    int numDig;
    if(nbr == 0)
    {
        return 0;
    }
    
    numDig=(nbr%10);
    return numDigits(nbr/10)+1;
}

/****************************************************
 * Recursion Function #23 - Function called         *
 * printReverse() that displays an integer's digits *
 * in reverse order                                 *
 * *************************************************/
void printReverse(int nbr)
{
    if(nbr == 0)
    {
        return;
    }
    
    outfile<<nbr%10;
    printReverse(nbr/10);
}

/****************************************************
 * Recursion Function #27 - Function called         *
 * reverseArray() that reverses the contents on an  *
 * array                                            *
 * **************************************************/
void reverseArray(int a[],int size)
{
    if(size <= 1 )
    {
        return ;
    }
    
    else
    {
        int temp;
        int i= 0;
        temp = a[i];
        a[i]= a[size-1];
        a[size -1] = temp;
        reverseArray(&a[1], size-2);
    }
}

/****************************************************
 * Recursion Function #28 - Function called         *
 * sumArray() that returns the sum of an array      *
 * *************************************************/
int sumArray(int a[], int n)
{
    if(a == 0 || n>9)
    {
        return 0;
    }
    
    return a[n] + sumArray(a, n+1);
}

/****************************************************
 * Recursion Function #29 - Function called         *
 * location() that returns the location of an       *
 * element in an array. If not found, return 0      *
 ****************************************************/
int location(int a[], int first, int last, int element)
{
    if(first == last && element != a[first])
    {
        return -1;
    }
    
    else if(element == a[last])
    {
        return last;
    }
    
    else

       return location(a, first+1, last-1, element);
   
}
/******************************************************
 * Recursion Function #33 - Function used to find the *
 * GCD (Greatest Common Divisor) of two integers      *
 ******************************************************/
int GDC(int a, int b)
{
    if(b == 0)
        return a;
    
    return GDC(b, a % b);
}

void printArray(int arr[], int start, int arySize)
{
    if(start >= arySize)
        return;
 
    outfile<<arr[start]<<" ";

    printArray(arr, start + 1, arySize);
}

void fileHeader()  //header for top of file output 
{
    outfile<<"**********************************"<<endl;
    outfile<<"Rachel Coughanour CS 372"<<endl;
    outfile<<"Output file for Recursion problems"<<endl;
    outfile<<"**********************************"<<endl;
}


//beginning of main 
int main()
{
  
    int nbr = 73264;
    int numDig;
    int arySize=10;
    int ary[arySize]={0};
    int arySum;
    int pos;
    int elementToFind=2;
    int a=15387;
    int b=549;
    int greatComDiv;
  
    outfile.open("C:\\data\\recursionSolutions.txt");
    fileHeader();
    
    //calling #21, returning the number of digits in an int
    outfile<<"#21, number of digits in an int"<<endl;
    numDig=numDigits(nbr);
    outfile<<"Number: "<<nbr<<endl;
    outfile<<"Number of digits: "<<numDig<<endl<<endl;
    
    
    //calling #23, printing the reverse of a number
    outfile<<"#23 Reverse printing a number"<<endl;
    outfile<<"Result: ";
    printReverse(nbr);
    outfile<<endl<<endl;
    
    //calling #27, calling reverseArray() to reverse the array and print
    //first, have to fill the array with values
    outfile<<"Contents of the array: ";
    for(int i=0;i<10;i++)
    {
        ary[i]=i;
        outfile<<ary[i]<<" ";
    }
    outfile<<endl<<endl;
    
    outfile<<"#27, Reverse the contents of an array"<<endl;
    reverseArray(ary, arySize);
   
    //printing the array 
    printArray(ary,0, arySize);
    outfile<<endl<<endl;
  
    //calling #28, sumArray() to return the sum of an array
    outfile<<"#28, the sum of the values of the array"<<endl;
    arySum=sumArray(ary, 0);
    outfile<<"Sum of the array: "<<arySum<<endl<<endl;
    
    //calling #29, returning the location of an element in the array 
    outfile<<"#29, returning the location of an element in the array"<<endl;
    pos=location(ary, 0, arySize, elementToFind);
    outfile<<"The location of element 2 in the array is: "<<pos<<endl<<endl;
    
    
    //calling #33, finding the greatest common divisor 
    outfile<<"#33, the Greatest Common Divisor (GDC) of two integers"<<endl;
    outfile<<"Integer a = "<<a<<" and integer b = "<<b<<endl;
    greatComDiv=GDC(a, b);
    outfile<<"GDC of "<<a<<" and "<<b<< " is: "<<greatComDiv<<endl;
    
    outfile.close();
    return 0;
}
