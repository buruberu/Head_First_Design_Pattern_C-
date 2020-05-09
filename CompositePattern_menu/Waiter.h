#ifndef _WAITER_H_
#define _WAITER_H_

#include "MenuComponent.h"

class Waiter {
  std::shared_ptr<MenuComponent> allMenus;

public:
  Waiter(std::shared_ptr<MenuComponent> allMenus) {
    this->allMenus = allMenus;
  }
  void printMenu() {
    allMenus->print();
  }
};

#endif