//
//  main.cpp
//  ALGORITHMS project 1
//
//  Created by Julia Vister on 08/12/2022.
//
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
#include "hybrid.h"

constexpr int step = 100;
constexpr int maxlen = 10000;
constexpr int times = 100;
/* constexpr int step = 10; */
/* constexpr int maxlen = 100; */
/* constexpr int times = 10; */

using std::chrono::nanoseconds;
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::ofstream file("/Users/juliavister/Desktop/Outputdatahybrid10000.txt");
    
    for (int len = step ; len <= maxlen ; len += step) {
        nanoseconds mer(0);
        nanoseconds ins(0);
        nanoseconds heap(0);
        nanoseconds quick(0);
        nanoseconds hybrid(0);

        std::vector<int>original(len);
        for (int i = 0 ; i < len ; i++) {
            original[i] = i;
        }

        std::vector<int> arr;
        std::vector<int> sorted;


        for (int t = 0 ; t < times ; t++) {
            std::shuffle(original.begin(), original.end(), gen); //random vector
            {
                arr = original;
                auto begin = std::chrono::steady_clock::now();
                heapsort(arr);
                auto end = std::chrono::steady_clock::now();
                nanoseconds total(end - begin);
                heap += total;
            }
        
            {
                arr = original;
                auto begin = std::chrono::steady_clock::now();
                InsertionSort(arr);
                auto end = std::chrono::steady_clock::now();
                nanoseconds total(end - begin);
                ins += total;
            }
            {
                arr = original;
                auto begin = std::chrono::steady_clock::now();
                mergesort(arr);
                auto end = std::chrono::steady_clock::now();
                nanoseconds total(end - begin);
                mer += total;
            }
            {
                arr = original;
                auto begin = std::chrono::steady_clock::now();
                Quicksort(arr,0, arr.size()-1);
                auto end = std::chrono::steady_clock::now();
                nanoseconds total(end - begin);
                quick += total;
            }
            {
                arr = original;
                auto begin = std::chrono::steady_clock::now();
                hybridsort(arr,0,arr.size()-1 );
                auto end = std::chrono::steady_clock::now();
                nanoseconds total(end - begin);
                hybrid += total;
            }
        }
        
        /*std::cout
            << len << " "
            << mer.count() / times << " "
            << ins.count() / times << " "
            << heap.count() / times << " "
            << quick.count() / times << std::endl; */
        
       
        if (file.is_open())
        {
            file << len << " " << mer.count() / times << " " << ins.count() / times << " " << heap.count() / times << " " << quick.count() / times << " " << hybrid.count() / times <<std::endl;
        }
        else
        {
            std::cout << "Unable to open file";
        }
    }
    file.close();
    return 0;
}

