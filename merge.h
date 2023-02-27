//
//  merge.h
//  ALGORITHMS project 1
//
//  Created by Julia Vister on 08/12/2022.
//

#ifndef merge_h
#define merge_h
#include "lib.h"
#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> &left, std::vector<int> &right);
std::vector<int> mergesort(std::vector<int> &vec);

std::vector<int> mergesort(std::vector<int> &vec)
{
    if( vec.size() == 0 || vec.size()== 1)
    {
        return vec;
    }
    
    //make two new vectors of the orginal one that are gonna be sorted and merged
    std::vector<int>up;
    up.reserve(vec.size()/2);
    
    std::vector<int>down;
    down.reserve(vec.size()/2);
    
    for(int i=0; i<vec.size(); i++)
    {
        if( i < vec.size()/2)
        {
            up.push_back(vec[i]);
        }
        else
        {
            down.push_back(vec[i]);
        }
    }
    std::vector<int> M1 = mergesort(up);
    std::vector<int> M2 = mergesort(down);
    std::vector<int> T1 = merge(M1, M2);
    
    return T1;
}

std::vector<int> merge(std::vector<int> &left, std::vector<int> &right)
{
        std::vector<int>temp;
        temp.reserve(left.size() + right.size());
    
        int rightindex = 0;
        int leftindex = 0;
        

        while(leftindex < left.size() and rightindex < right.size()) //while on of them are not empty
        {
                if(left.at(leftindex) <= right.at(rightindex)) //if first element of left <=
                {
                    temp.push_back(left.at(leftindex)); //push first element of left into temp
                    leftindex++;
                }
                else
                {
                    temp.push_back(right.at(rightindex));
                    rightindex++;
                }
        }
    
    for(int i= leftindex; i < left.size(); i++)
    {
        temp.push_back(left[i]);
    }
    
    for(int i=rightindex; i< right.size(); i++)
    {
        temp.push_back(right[i]);
    }
        return temp;
}

#endif /* merge_h */
