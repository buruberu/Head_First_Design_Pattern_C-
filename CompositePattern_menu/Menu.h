#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <string>
#include <vector>

#include <memory>
#include <stdexcept>

class Menu : public MenuComponent {
  std::vector<std::shared_ptr<MenuComponent>> menuComponents;
  std::string name;
  std::string description;

public:
  Menu(std::string name, std::string description) {
    this->name = name;
    this->description = description;
  }
  ~Menu(){}

  void add(std::shared_ptr<MenuComponent> menuComponent) override {
    menuComponents.push_back(menuComponent);
  }
  void remove(std::shared_ptr<MenuComponent> menuComponent) override {
    for(auto it = menuComponents.begin();it!=menuComponents.end();it++) {
      if((*it)->getName() == menuComponent->getName()) {
        menuComponents.erase(it);
        break;
      }
    }
  }
  std::shared_ptr<MenuComponent> getChild(int i) override {
    return menuComponents.at(i);
  }
  std::string getName() override {
    return name;
  }
  std::string getDescription() override {
    return description;
  }
  friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Menu> menu) {
    os << " " << menu->getName();
    os << " -- " << menu->getDescription();
    return os;
  }

  void print() override {
    std::cout << std::make_shared<Menu>(*this) << std::endl;
    for(auto a : this->menuComponents) {
      a->print();
    }
  }

};

#endif
