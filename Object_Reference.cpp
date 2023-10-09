
#include <iostream>

class item_ecs36b
{
 private:
 protected:
 public:
  std::string item;
  int quantity;
};

void
set_quantity_by_value
(item_ecs36b _item, int _quantity)
{
  _item.quantity = _quantity;
}

void
set_quantity_by_reference
(item_ecs36b& _item, int _quantity)
{
  _item.quantity = _quantity;
}

void
set_quantity_by_pointer
(item_ecs36b * _item_ptr, int _quantity)
{
  _item_ptr->quantity = _quantity;
}

int
main(void)
{
  item_ecs36b my_item;
  my_item.quantity = 0;
  std::cout << "the original          quantity is " << my_item.quantity << std::endl;
  
  set_quantity_by_value(my_item, 10);
  std::cout << "the call-by-value     quantity is " << my_item.quantity << std::endl;

  set_quantity_by_reference(my_item, 1000);
  std::cout << "the call-by-reference quantity is " << my_item.quantity << std::endl;

  set_quantity_by_pointer(&my_item, 3000);
  std::cout << "the call-by-address   quantity is " << my_item.quantity << std::endl;

  return 0;
}
