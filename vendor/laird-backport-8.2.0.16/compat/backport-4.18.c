/*
 * Copyright (C) 2018 Intel Corporation
 */

#include <linux/export.h>
#include <linux/hrtimer.h>


#if LINUX_VERSION_IS_LESS(3, 17, 0)

#if BITS_PER_LONG == 32
/*
 * Divide a ktime value by a nanosecond value
 */
u64 ktime_divns(const ktime_t kt, s64 div)
{
	u64 dclc;
	int sft = 0;

	dclc = ktime_to_ns(kt);
	/* Make sure the divisor is less than 2^32: */
	while (div >> 32) {
		sft++;
		div >>= 1;
	}
	dclc >>= sft;
	do_div(dclc, (unsigned long) div);

	return dclc;
}
#endif

#endif

time64_t ktime_get_boottime_seconds(void)
{
	return ktime_divns(ktime_get_boottime(), NSEC_PER_SEC);
}
EXPORT_SYMBOL_GPL(ktime_get_boottime_seconds);
