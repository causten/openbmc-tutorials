#include <iostream>
#include "method_tutorial.hpp"


namespace phosphor
{
namespace tutorial
{

void Manager::commit(int32_t transactionId, std::string msg)
{
	fprintf(stderr,"Hi from the commit: Message = %s\n", msg.c_str());
}

} // tutorial
}