#ifndef LABIRYNTHOBJECT_H
#define LABIRYNTHOBJECT_H

class LabirynthObject
{
	public:
		LabirynthObject(char);
		virtual char getObjectType();
	private:
		char objectType;
};

#endif
