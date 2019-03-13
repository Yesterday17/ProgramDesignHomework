#pragma once

/** 
 * 计算机配件 - 管理系统所管理物品
 */
typedef struct {
	int index;           // 索引
	char* name;          // 配件名称
	ComponentType type; // 配件型号
	char* manufacturer;  // 制造商
}Component;

typedef struct {
	char* name;          // 型号名称
}ComponentType;

Component ReadComponent();
ComponentType ReadComponentType();