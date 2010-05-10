#include <stdio.h>
#include <UnitTest++.h>

#include "../src/jThread.h"

class SingleThread : public jThread
{
public:
	SingleThread() {
		m_count = 0;
	}
	virtual ~SingleThread() {}

	virtual void run() {
		for (int i = 0; i < 10; i++) {
			m_count++;
		}
	}

	int getCount() {
		return m_count;
	}

private:
	int m_count;
};

class MultiThread : public jThread
{
public:
	MultiThread(int id) {
		m_id = id;
	}
	
	virtual ~MultiThread() {}

	virtual void run() {
		for (int i = 0; i < 10; i++) {
			s_count++;
			sleep(0);
		}
	}

	int getCount() {
		return s_count;
	}

private:
	static int s_count;
	int m_id;
};

int MultiThread::s_count = 0;

SUITE(jThread)
{
	
TEST(start)
{
	SingleThread* th = new SingleThread();
	th->start();
	th->join();
	CHECK(th->getCount() == 10);
	delete th;
}

TEST(join)
{
	SingleThread* th = new SingleThread();
	th->start();
	th->join();
	CHECK(th->getCount() == 10);
	delete th;
}

TEST(multiThread)
{
	MultiThread th1(1);
	MultiThread th2(2);

	th1.start();
	th2.start();
	th1.join();
	th2.join();
}

}
