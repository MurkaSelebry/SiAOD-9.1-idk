#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <numeric>
#include <windows.h>
#include <algorithm>

#define UI unsigned int 

using namespace std;


class Table {
    struct HNPrecord {
        UI cadastral_number;
        string adress;
    };
    vector<HNPrecord> storage;
    vector<HNPrecord>::iterator it;
    vector<string> rand_adresses;
    HNPrecord inline convert_2_HNPrecord(UI cadastral_number, string adress);
public:
    //Constructors
    Table();
    Table(std::size_t size);
    Table(UI cadastral_number, std::string adress);
    //Operations with table
    void insert(UI cadastral_number, std::string adress);
    void fill_adresses();
    void rand_init(std::size_t size);
    void keyboard_init(std::size_t size);
    void print_table();
    //Searching algorithms
    std::string brute_force(UI key);
    std::string barrier_search(UI key);
};