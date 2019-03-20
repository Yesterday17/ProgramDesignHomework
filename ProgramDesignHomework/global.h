#pragma once
#include <stdint.h>
#include "./data/component.h"
#include "./ui/ui.h"
#include "./utils/linkedlist.h"

extern const char NAME[];
extern const char VERSION[];

extern Menu menuNow;

LinkedList component;
LinkedList purchase;
LinkedList sales;

extern char* nameToSearch;
extern uint64_t timeToSearch;
extern Component* componentToSearch;
extern char* customerToSearch;
extern char* retailerToSearch;
