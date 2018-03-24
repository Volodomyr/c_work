#pragma once
#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <unordered_map>
#include <iostream>

template<typename Type>
class Resource {
private:

	const std::string resFolder; //папка ресурсов
	const std::string resExtention; //расширение всех ресурсов добавляемых в контейнер map
	std::unordered_map<std::string, Type> resources; //ассоциативный массив имен и привязаным к ним ресурсам

public:
	Resource(const std::string& _resFolder, const std::string& _resExtention);

	//метод добавляет в контейнер ресурс
	void Add(const std::string& _name);

	// метод проверяет наличие ресурса в контейнере
	bool Exist(const std::string& _name);

	//метод возвращает ссылку на ресурс из контейнера
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
	if (!new_res.loadFromFile(resFolder + _name + resExtention)) { //если ресурс не подгрузился
		std::cout << "Error! File " << _name << resExtention << " not exist." << std::endl;
	}
	else {
		resources.insert(std::make_pair(_name, new_res)); //добавляем ресурс в контейнер
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
