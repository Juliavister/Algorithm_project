//
//  heap.h
//  ALGORITHMS project 1
//
//  Created by Julia Vister on 08/12/2022.
//

#ifndef heap_h
#define heap_h
#include "lib.h"
#include <iostream>
#include <vector>
#include <algorithm>

void fix(std::vector<int> &V, int i, int h)
{
    int parent = i; //this is the root, the very top of the tree.. i think
    int left = 2*i+1;
    int right = 2*i+2;
    
    //checks what element, lefft child, right child or root is the largest one
    if(left < h)
    {
        if( V.at(left) > V.at(parent))
        {
            parent=left;
        }
    }
    
    if(right < h)
    {
        if(V.at(right) > V.at(parent))
        {
            parent=right;
        }
    }
    
    //swapping of the elements, if more elements continue to be larger, fixes these too
    if(parent!= i)
    {
        std::swap(V.at(i), V.at(parent));
        fix(V, parent, h);
    }
}

void buildheap(std::vector<int> &V)
{
    for(int i=V.size()-1; i>=0; i--) //have to start at the end of the vector, therfore -1 and i has to be either greater or = to the start to know we got all elements
    {
        fix(V, i, V.size());
    }
}

void heapsort(std::vector<int> &V)
{
    int h = V.size(); //heapsize
    buildheap(V);
    
    for(int i=V.size()-1; i>=0; i--)
    {
        std::swap(V.at(0), V.at(i));
        h--; //have to decrement heap size so that we remove the largest size element from the heap and can continue with rest of elements in same ordere
        fix(V, 0, h);
    }
}

#endif /* heap_h */
