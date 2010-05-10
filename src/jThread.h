#include <pthread.h>

#include "jRunnable.h"

class jThread : public jRunnable
{
public:
	jThread();
	virtual ~jThread();
	virtual void	run();

	void			start();
	void			join();
	bool			isAlive();
	
private:
	static jThread* currentThread();
	
	pthread_t		m_thread;
	pthread_attr_t	m_attr;
}; 
