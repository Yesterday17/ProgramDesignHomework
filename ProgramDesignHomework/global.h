#pragma once
#include <stdint.h>
#include "./data/component.h"
#include "./utils/linkedlist.h"

#ifndef UNIT_TEST

extern const char NAME[];
extern const char VERSION[];

extern LinkedList component;
extern LinkedList purchase;
extern LinkedList sales;

extern char* nameToSearch;
extern uint64_t timeToSearch;
extern Component* componentToSearch;
extern char* customerToSearch;
extern char* retailerToSearch;
extern char *typeToSearch;
extern char * manufacturerToSearch;

#endif