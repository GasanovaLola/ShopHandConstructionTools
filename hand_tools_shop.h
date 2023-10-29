#pragma once
/*#define _CRT_SECURE_NO_WARNINGS
#define ambiguous*/
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

typedef struct Product
{
	string NameOfProduckt;
	string Manufacturer;
	int VendorCode;
	int Price;
	struct Product* sled;
} Prod;

static int Size = NULL;

struct Product* create_add_Prod(void);
void add(Prod** first_add);
void update(Prod** first_cr);
void del(Prod** first_cr);
void prosm_Prod(Prod* first_pr);
void all_Prod_infa(Prod* first_infa);
void zvit(Prod* first_infa);
void to_file_Prod(Prod* first_tf);
bool from_file_Prod(Prod** first);