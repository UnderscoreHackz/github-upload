#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

using namespace std;
 
int getMedian(int ar1[],int ar2[], int n)
{
    int i = 0; /* Current index of i/p  array ar1[] */
    int j = 0; /* Current index of i/p array ar2[] */
    int count;
    int m1 = -1, m2 = -1;
 
    /* Since there are 2n elements,
    median will be average of elements
    at index n-1 and n in the array
    obtained after merging ar1 and ar2 */
    for (count = 0; count <= n; count++)
    {
       
        if (i == n)  /* Below is to handle case where all elements of ar1[] are smaller than smallest(or first) element of ar2[]*/
        {
            m1 = m2;
            m2 = ar2[0];
            break;
        }
        else if (j == n)  /*Below is to handle case where all elements of ar2[] are smaller than smallest(or first) element of ar1[]*/
        {
            m1 = m2;
            m2 = ar1[0];
            break;
        }
        if (ar1[i] <= ar2[j])  /* equals sign because if two arrays have some common elements */
        {
            /* Store the prev median */
            m1 = m2;
            m2 = ar1[i];
            i++;
        }
        else if (ar1[i] > ar2[j])
        {
            /* Store the prev median */
            m1 = m2;
            m2 = ar2[j];
            j++;
        }
    }
 
    return (m1 + m2)/2;
}
 
// Driver Code
int main()
{
    int ar1[] = {14,15,21,53};
    int ar2[] = {9,10,100,200};
    int n = 4;
 
    cout << "Median is " << getMedian(ar1, ar2, n) << endl;

    return 0;
}
 

