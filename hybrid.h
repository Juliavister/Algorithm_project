//
//  hybrid.h
//  ALGORITHMS project 1
//
//  Created by Julia Vister on 15/12/2022.
//

#ifndef hybrid_h
#define hybrid_h
#include <algorithm>
#include <chrono>
#include <cassert>
#include <iostream>
#include <random>
#include <fstream>
#include "lib.h"
#include "insert.h"
#include "merge.h"
#include "heap.h"
#include "quick.h"

// for vector size less than 60 insertion sort was the faster algorithm, so i call it.
//for sizes greather than 60 quick sort was always the fastest one

int dividing(std::vector<int> &vector, int start, int end)
{
    int divider = vector.at(end);
    int divindex = start-1;
        
    for(int i=start; i<=end; i++)
    {
        if(vector.at(i) < divider)
        {
            divindex++;
            std::swap(vector.at(divindex),vector.at(i));
        }
    }
    std::swap(vector.at(divindex+1), vector.at(end));
    int pivot = divindex+1;
    return pivot;
}

void hybridsort(std::vector<int> &vector, int start, int end)
{
    //need: check the two sub vectors to see which ones have less than 60 in size, if one of them is, i call insertion sort on it
     //divided the full vector so that i have a right and left side with a pivot
        if(end-start < 60 )
        {
            for (int i = start+1; i <=end; i++)
            {
                int val = vector[i];
                int cur = i;
                while ( (cur > 0) && vector[cur - 1] > val )
                {
                    vector[cur] = vector[cur - 1];
                    cur--;
                }
                vector[cur] = val;
            }
        }
        else //for vector sizes greater than 60 quick sort is better
        {
            int subdivider = dividing(vector,start,end);
            hybridsort(vector, start, subdivider-1); //first part of vector
            hybridsort(vector,subdivider+1, end); //second part of vector
        }
}
    
#endif /* hybrid_h */
