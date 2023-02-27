//
//  insert.h
//  ALGORITHMS project 1
//
//  Created by Julia Vister on 08/12/2022.
//

#ifndef insert_h
#define insert_h
#include "lib.h"
#include <iostream>
#include <vector>

void InsertionSort(std::vector<int> &sort) {
    for (int i = 1 ; i < sort.size() ; i++) {
        int val = sort[i];
        int cur = i;
        while ( (cur > 0) && sort[cur - 1] > val ) {
            /* p(arr, len); */
            sort[cur] = sort[cur - 1];
            cur--;
        }
        sort[cur] = val;
    }
}
#endif /* insert_h */
