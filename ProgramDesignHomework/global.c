#include "global.h"

const char NAME[] = "SALES_MANAGEMENT_SYSTEM";
const char VERSION[] = "0.0.1-SNAPSHOT";

char* nameToSearch;//
char* customerToSearch;
char* retailerToSearch;//
char *manufacturerToSearch;//
char *typeToSearch;//
uint64_t timeToSearch;
Component* componentToSearch = NULL;

LinkedList* component;
LinkedList* purchase;
LinkedList* sales;