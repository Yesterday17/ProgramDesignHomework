#pragma once

/** 
 * �������� - ����ϵͳ��������Ʒ
 */
typedef struct {
	int index;           // ����
	char* name;          // �������
	ComponentType type; // ����ͺ�
	char* manufacturer;  // ������
}Component;

typedef struct {
	char* name;          // �ͺ�����
}ComponentType;

Component ReadComponent();
ComponentType ReadComponentType();