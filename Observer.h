#ifndef Observer_H
#define Observer_H

class Observer {
	public:
		virtual void notify() = 0;
		~Observer() = default;
};

#endif