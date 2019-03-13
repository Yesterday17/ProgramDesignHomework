#pragma once

typedef struct {
	char* name;          // �ͺ�����
}ComponentType;

/** 
 * �������� - ����ϵͳ��������Ʒ
 */
typedef struct {
	int index;           // ����
	char* name;          // �������
	ComponentType type; // ����ͺ�
	char* manufacturer;  // ������
}Component;

Component ReadComponent();
ComponentType ReadComponentType();