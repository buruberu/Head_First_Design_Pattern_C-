#ifndef _MENUCOMPONENT_H_
#define _MENUCOMPONENT_H_

#include <iostream>
#include <string>

#include <memory>
#include <stdexcept>

class MenuComponent {
public:
  virtual ~MenuComponent() {}
  virtual void add(std::shared_ptr<MenuComponent> menuComponent) {
    throw std::runtime_error("unsupported.");
  }
  virtual void remove(std::shared_ptr<MenuComponent> menuComponent) {
    throw std::runtime_error("unsupported.");
  }
  virtual std::shared_ptr<MenuComponent> getChild(int i) {
    throw std::runtime_error("unsupported.");
  }

  virtual std::string getName() {
    throw std::runtime_error("unsupported.");
  }
  virtual std::string getDescription() {
    throw std::runtime_error("unsupported.");
  }
  virtual double getPrice() {
    throw std::runtime_error("unsupported.");
  }
  virtual bool isVegetarian() {
    throw std::runtime_error("unsupported.");
  }
  friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<MenuComponent> menuComponent) {
    // os << menuComponent->getName() << ": " << menuComponent->getPrice();
    //return os;
    throw std::runtime_error("unsupported.");
  }

  virtual void print() {
    throw std::runtime_error("unsupported.");
  }
};

#endif