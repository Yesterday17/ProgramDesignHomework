#pragma once
#include <stdint.h>
#include "./data/component.h"
#include "./ui/ui.h"
#include "./utils/linkedlist.h"


#ifndef UNIT_TEST

extern const char NAME[];
extern const char VERSION[];

extern Menu menuNow;

extern LinkedList component;
extern LinkedList purchase;
extern LinkedList sales;

extern char* nameToSearch;
extern uint64_t timeToSearch;
extern Component* componentToSearch;
extern char* customerToSearch;
extern char* retailerToSearch;

#endif