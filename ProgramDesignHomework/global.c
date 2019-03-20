#include "global.h"

const char NAME[] = "SALES_MANAGEMENT_SYSTEM";
const char VERSION[] = "0.0.1-SNAPSHOT";

Menu menuNow = MENU_Welcome;

char* nameToSearch;
uint64_t timeToSearch = 0;
Component* componentToSearch = NULL;
char* customerToSearch;
char* retailerToSearch;