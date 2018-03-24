#pragma once
#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <unordered_map>
#include <iostream>

template<typename Type>
class Resource {
private:

	const std::string resFolder; //����� ��������
	const std::string resExtention; //���������� ���� �������� ����������� � ��������� map
	std::unordered_map<std::string, Type> resources; //������������� ������ ���� � ���������� � ��� ��������

public:
	Resource(const std::string& _resFolder, const std::string& _resExtention);

	//����� ��������� � ��������� ������
	void Add(const std::string& _name);

	// ����� ��������� ������� ������� � ����������
	bool Exist(const std::string& _name);

	//����� ���������� ������ �� ������ �� ����������
	Type& Get(const std::string& _name);
};

template <typename Type>
Resource<Type>::Resource(const std::string& _resFolder, const std::string& _resExtention) :
	resFolder("resources/" + _resFolder + "/"),
	resExtention("." + _resExtention)
{
}

template <typename Type>
void Resource<Type>::Add(const std::string& _name) {
	Type new_res;// = new Type;
	if (!new_res.loadFromFile(resFolder + _name + resExtention)) { //���� ������ �� �����������
		std::cout << "Error! File " << _name << resExtention << " not exist." << std::endl;
	}
	else {
		resources.insert(std::make_pair(_name, new_res)); //��������� ������ � ���������
	}
}

template <typename Type>
bool Resource<Type>::Exist(const std::string& _name) {
	return resources.find(_name) != resources.end();
}

template <typename Type>
Type& Resource<Type>::Get(const std::string& _name) {
	if (!Exist(_name)) {
		this->Add(_name);
	}

	return resources[_name];
}

#endif // RESOURCE_H
