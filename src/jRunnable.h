#ifndef _JRUNNABLE_H_
#define _JRUNNABLE_H_

class jRunnable
{
public:
	jRunnable();
	virtual ~jRunnable();
	virtual void run() = 0;
};

#endif /* _JRUNNABLE_H_ */
