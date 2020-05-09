#ifndef _MENU_ITEM_H_
#define _MENU_ITEM_H_

#include <iostream>
#include <string>

#include <memory>
#include <stdexcept>

class MenuItem : public MenuComponent {
  std::string name;
  std::string description;
  bool vegetarian;
  double price;

public:
  MenuItem(std::string name,
           std::string description,
           bool vegetarian,
           double price) {
    this->name = name;
    this->description = description;
    this->vegetarian = vegetarian;
    this->price = price;
  }
  ~MenuItem() {}
  
  std::string getName() override {
    return name;
  }
  std::string getDescription() override {
    return description;
  }
  bool isVegetarian() override {
    return vegetarian;
  }
  double getPrice() override {
    return price;
  }

  friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<MenuItem> menuItem) {
    os << " " << menuItem->getName();
    if(menuItem->isVegetarian()) os << " (v)";
    os << " : " << menuItem->getPrice(); 
    os << " -- " << menuItem->getDescription();
    return os;
  }
  void print() override {
    std::cout << std::make_shared<MenuItem>(*this) << std::endl;
  }
};

#endif