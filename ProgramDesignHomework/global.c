#include "global.h"

const char NAME[] = "SALES_MANAGEMENT_SYSTEM";
const char VERSION[] = "0.0.1-SNAPSHOT";

string nameToSearch;
string customerToSearch;
string retailerToSearch;
string manufacturerToSearch;
string typeToSearch;
uint64_t timeToSearch;
Component* componentToSearch = NULL;

LinkedList* component;
LinkedList* purchase;
LinkedList* sales;