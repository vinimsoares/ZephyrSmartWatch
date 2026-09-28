#include "time_track.h"
#include <time.h>

time_t *current_time;
int set_time(time_t epoch_time) {
	
	struct timespec ts = {
		.tv_sec = epoch_time,
		.tv_nsec = 0
	};
	return sys_clock_settime(CLOCK_REALTIME, &ts);
}
int get_time(struct tm *out_time) {
	
	struct timespec ts;
	int ret = sys_clock_gettime(CLOCK_REALTIME, &ts);
	if (ret <= 0) {
		return ret;
	}
	ret = gmtime_r(&ts.tv_sec, out_time);
	if (ret == NULL) {
		return -1;
	}

	return 0;
}

int time_track_init() {
	
    return 0;
}

