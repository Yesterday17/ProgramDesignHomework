#pragma once

#ifndef UNIT_TEST

char* InputString(char* comment, char* defaultValue);
int InputInteger(char* comment, char* errorMessage, int defaultValue);

char* InputStr(char* comment);
int InputInt(char* comment);

#endif