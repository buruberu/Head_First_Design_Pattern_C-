#include "MenuComponent.h"
#include "MenuItem.h"
#include "Menu.h"
#include "Waiter.h"

#include <memory>

int main() {
  std::shared_ptr<Menu> pancakeHouseMenu
  = std::make_shared<Menu>(std::string("pancakeHouseMenu"), std::string("breakfast"));
  std::shared_ptr<Menu> dinerMenu
  = std::make_shared<Menu>(std::string("lunchMenu"), std::string("lunch"));
  std::shared_ptr<Menu> cafeMenu
  = std::make_shared<Menu>(std::string("caffeMenu"), std::string("dinnar"));
  std::shared_ptr<Menu> dessertMenu
  = std::make_shared<Menu>(std::string("dessertMenu"), std::string("dessert"));
  
  std::shared_ptr<Menu> allMenus
  = std::make_shared<Menu>(std::string("allMenu"), std::string("allMenu"));

  allMenus->add(pancakeHouseMenu);
  allMenus->add(dinerMenu);
  allMenus->add(cafeMenu);
  
  dinerMenu->add(std::make_shared<MenuItem>(std::string("pasta"),
                                            std::string("marinara sauce pasta with sourdough bread."),
                                            true,
                                            3.89));
  
  dinerMenu->add(dessertMenu);
  dessertMenu->add(std::make_shared<MenuItem>(std::string("applePie"),
                                              std::string("apple pie with vanilla ice."),
                                              true,
                                              1.59));
  
  auto waiter = std::make_shared<Waiter>(allMenus);
  waiter->printMenu();
  
}