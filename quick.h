//
//  quick.h
//  ALGORITHMS project 1
//
//  Created by Julia Vister on 08/12/2022.
//

#ifndef quick_h
#define quick_h
#include "lib.h"
#include <iostream>
#include <vector>


int partitioning(std::vector<int> &vector, int start, int end) //starting index and ending index
{
    
    int divider = vector.at(end); // the element we divide the vector with, its value i think
    int divindex = start-1; //the index of the divider, this will be incremented until it reaches pivot, so that we can have something to swap with --> regulate left side
    
    for(int i=start; i<=end; i++) //we search for an element that is less than the divider
    {
        if(vector.at(i) < divider) //puts elememnts smaller then divider on the left side
        {
            divindex++; //incremented until it reaches pivot, so that we can have something to swap with
            std::swap(vector.at(divindex),vector.at(i)); //swap divider index with i that is less than divider, now i get elememnts less than divider on left side
        }
    }
    //elemets greater than divider is already on the right side now, but we have put the divider in its correct place now inbetween the two subarrays. Therefore, swap the divider, aka vector end with the index of the last element on left side + 1, since thats betweeen them.
    std::swap(vector.at(divindex+1), vector.at(end));
    
    //now that divider is in correct place, i need to return this cuz this is what we work with further
    int pivot = divindex+1;
    return pivot;
}

void Quicksort(std::vector<int> &vector, int start, int end)
{
    if(start < end) //if the smaller subvector (the one with smaller elements than divider) is smaller than the right subvector
    {
       int subdivider = partitioning(vector,start, end); //partition further so that each subvector will get sorted as well, just like how we did the original vector
        //now that they are further partioned, each with another divider, we can sort the subvectors. Since each has another divider, we have to recursivly partition the subvectors so that the divider is in the right place with the elements.
        Quicksort(vector, start, subdivider-1); //places the right subvector on the right side
        Quicksort(vector,subdivider+1, end); //places the left subvector on the left side
    }
}

#endif /* quick_h */
