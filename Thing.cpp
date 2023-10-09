
#include "Thing.h"

std::string Thing::class_name = { "Thing1234567890" };

void
myPrintLog
(std::string content, std::string fname)
{
  if (fname.size() == 0) return;
  
  FILE *log_f = fopen(fname.c_str(), "a");
  if (log_f == NULL) return;

  // [int] [x] [= 5];
  // [FILE *] [log_f] [= fopen ( fname.c_str(), "a")];
  // data type {FILE *, int}
  // variable name {log_f, x}

  // a pointer is a data type, except specifying what data it is pointing to.
  // int *   [a pointer, type => int]
  // FILE *  [a pointer, type => FILE]
  // GPS_DD * [a pointer, type => GPS_DD, in GPS.cpp, this->latitude]

  // specify a pointer type
  // [int *] int_ptr = NULL;
  
  // dereference a pointer
  // printf("%d\n", [*int_ptr]);

  // obtain the reference or address of an integer;
  // int x = 5;
  // int_ptr = &x; // extracting the address of x
  // printf("%d\n", [*int_ptr]);
  
  
  JvTime *jv_ptr = getNowJvTime();
  std::string *str_ptr = jv_ptr->getTimeString();
  fprintf(log_f, "[%s] %s\n", str_ptr->c_str(), content.c_str());
  delete str_ptr;
  delete jv_ptr;
  fflush(log_f);
  fclose(log_f);
  return;
}

Thing::Thing
(void)
{
  // this->class_name = "Thing";
  printf("%s\n", (this->class_name).c_str());
  
  this->model = "";
  this->sequence_num = "";
  this->description = "";
}

Thing::Thing
(Person arg_owner)
{
  // this->class_name = "Thing";
  printf("%s\n", (this->class_name).c_str());

  this->model = "";
  this->sequence_num = "";
  this->description = "";
  this->owner = arg_owner;
}

void Thing::dump
(void)
{

#define ECS36B_ADVANCED
  
#ifdef ECS36B_ADVANCED
  
  // **** ecs36b f2023 Exam question related
  // review from ecs36a --> C pointer/address, pointer/address casting, struct and offsets
  // new stuff becasue of C++ --> std::string and c_str(), typeid
  long long x = (long long) ((Thing *) 1);
  // not working ==> long long y = static_cast<long long>((void *) ((Thing *) 1));
  void * this_address = (void *) this;
  unsigned long long ull_value = (unsigned long long) this;
  unsigned long long seq_num_offset = (unsigned long long) (&((Thing *) 0)->sequence_num);
  ull_value += seq_num_offset;
  printf("[%s]\n", ((std::string *) ull_value)->c_str());
  std::cout << "dump " << typeid(this).name() << " @ address = " << this << std::endl;

#endif /* ECS36B_ADVANCED */

  std::cout << "dump Thing" << std::endl;
  std::cout << "  {" << std::endl;
  std::cout << "    model          = " << this->model << std::endl;
  std::cout << "    sequence_num   = " << this->sequence_num << std::endl;
  std::cout << "    description    = " << this->description << std::endl;
  std::cout << "  }" << std::endl;
  return;
}

