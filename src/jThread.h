#ifndef _JTHREAD_H_
#define _JTHREAD_H_

#include <pthread.h>

#include "jRunnable.h"

struct NativeThread;

class jThread : public jRunnable
{
public:
	jThread();
	virtual ~jThread();
	virtual void	run();

	void			start();
	void			join();
	bool			isAlive();

	static jThread* currentThread();

private:
	NativeThread*	m_native;
};

#endif /* _JTHREAD_H_ */
