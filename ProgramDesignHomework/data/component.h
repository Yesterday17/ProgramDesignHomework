#pragma once

typedef struct {
	int index;
	char* name;
	ComponentType* type;
	char* manufacturer;
}Component;

typedef struct {
	char* name;
}ComponentType;