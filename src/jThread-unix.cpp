#include <stdio.h>

#include "jThread.h"

struct NativeThread {
	pthread_t		thread;
	pthread_attr_t	attr;
};

static void* start_routine(void* arg)
{
	jRunnable* runnable = static_cast<jRunnable*>(arg);
	if (runnable != NULL)
		runnable->run();
	
	pthread_exit(NULL);
}

jThread::jThread()
{
	m_native = new NativeThread;
	pthread_attr_init(&(m_native->attr));
	pthread_attr_setdetachstate(&(m_native->attr), PTHREAD_CREATE_JOINABLE);
}

jThread::~jThread()
{
	pthread_attr_destroy(&(m_native->attr));
	delete m_native;
}

void
jThread::run()
{
}

jThread*
jThread::currentThread()
{
	return NULL;
}

void
jThread::start()
{
	int ret = pthread_create(&(m_native->thread),
							 &(m_native->attr),
							 start_routine,
							 this);
	if (ret != 0) 
		printf("error: return value from pthread_create() is %d\n", ret);
}

void
jThread::join()
{
	int ret = pthread_join(m_native->thread, NULL);
	if (ret != 0)
		printf("error: return value from pthread_join() is %d\n", ret);
}

bool
jThread::isAlive()
{
	return true;
}
