#ifndef TRACE_H
#define TRACE_H

#include <string>
#include <stdexcept>

#define CLASS(CLASS) \
	static const char* abcClass = CLASS; 

#define METHOD(METHOD) \
	Trace abcTrace(abcClass, METHOD, __FILE__, __LINE__);

#define LOG(LOG) \
	abcTrace.log(LOG);

#define EXCEPTION(EXCEPTION) \
	throw std::logic_error(EXCEPTION);

class Trace {

public:
	Trace(std::string clazz, std::string meths, std::string file, int line);
	~Trace();
	void log(const char* msg);

private:
	std::string clazz;
	std::string method;
	static int scope;
};

#endif
