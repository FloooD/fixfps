#include <time.h>
#include <sys/time.h>
#define DELTA 5000000
int gettimeofday(struct timeval *tv, struct timezone *tz)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	tv->tv_sec = ts.tv_sec;
	tv->tv_usec = (DELTA / 1000) * (ts.tv_nsec / DELTA);
}

int usleep(int asdf)
{
	struct timespec t;
	clock_gettime(CLOCK_MONOTONIC, &t);
	t.tv_nsec = DELTA * (t.tv_nsec / DELTA + 1);
	if (t.tv_nsec >= 1000000000) {
		t.tv_nsec = 0;
		t.tv_sec++;
	}
	clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t, NULL);
	return 0;
}
