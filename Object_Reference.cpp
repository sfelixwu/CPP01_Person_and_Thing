
#include <iostream>

class item_ecs36b
{
 private:
 protected:
 public:
  std::string item;
  int quantity;
};

// int
void
set_quantity_by_value // need to make a copy of _item
(item_ecs36b _item, int _quantity)
{
  _item.quantity = _quantity;
  std::cout << "the address of the object _item    is " << &(_item) << std::endl;
  std::cout << "the address of the member quantity is " << &(_item.quantity) << std::endl;
  // return 2.5 * quantity;
}

void
set_quantity_by_reference
(item_ecs36b& _item, int _quantity)
{
  _item.quantity = _quantity;
  std::cout << "the address of the object _item    is " << &(_item) << std::endl;
  std::cout << "the address of the member quantity is " << &(_item.quantity) << std::endl;
}

void
set_quantity_by_pointer
(item_ecs36b * _item_ptr, int _quantity)
{
  _item_ptr->quantity = _quantity;
  std::cout << "the address of the object _item    is " << _item_ptr << std::endl;
  std::cout << "the address of the member quantity is " << &(_item_ptr->quantity) << std::endl;
  // (*_item_ptr).quantity = _quantity;

  // item_ptr  @0x21
  // *item_ptr 25
  // &item_ptr @0x07

}

int
main(void)
{
  
  std::cout << "the size of std::string is " << sizeof(std::string) << std::endl;
  
  item_ecs36b my_item;
  my_item.quantity = 0;
  std::cout << "the address of the object _item    is " << &(my_item) << std::endl;
  std::cout << "the address of the member quantity is " << &(my_item.quantity) << std::endl;
  std::cout << "the original          quantity is " << my_item.quantity << std::endl;
  // 0
  // std::cout << "the original          quantity is " << my_item.quantity << "\n";
  
  set_quantity_by_value(my_item, 10);
  // 0 or 10
  std::cout << "the call-by-value     quantity is " << my_item.quantity << std::endl;

  set_quantity_by_reference(my_item, 1000);
  std::cout << "the call-by-reference quantity is " << my_item.quantity << std::endl;
  // 1000
  
  set_quantity_by_pointer(&my_item, 3000);
  std::cout << "the call-by-address   quantity is " << my_item.quantity << std::endl;
  // 3000
  
  return 0;
}
