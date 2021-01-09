#include "LabirynthObject.h"

LabirynthObject::LabirynthObject(char object) : objectType(object)
{
}

char LabirynthObject::getObjectType(){
	return objectType;
}
