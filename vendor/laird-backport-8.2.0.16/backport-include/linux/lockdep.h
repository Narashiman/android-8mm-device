#ifndef __BACKPORT_LINUX_LOCKDEP_H
#define __BACKPORT_LINUX_LOCKDEP_H
#include_next <linux/lockdep.h>
#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(3,9,0)
#undef lockdep_assert_held
#ifdef CONFIG_LOCKDEP
#define lockdep_assert_held(l)	do {				\
		WARN_ON(debug_locks && !lockdep_is_held(l));	\
	} while (0)
#else
#define lockdep_assert_held(l)			do { (void)(l); } while (0)
#endif /* CONFIG_LOCKDEP */
#endif /* LINUX_VERSION_IS_LESS(3,9,0) */

#if LINUX_VERSION_IS_LESS(4,15,0)
#ifndef CONFIG_LOCKDEP
struct lockdep_map { };
#endif /* CONFIG_LOCKDEP */
#endif /* LINUX_VERSION_IS_LESS(4,15,0) */

#if LINUX_VERSION_IS_LESS(3,12,0)
#ifdef CONFIG_PROVE_LOCKING
	#define lock_acquire_exclusive(l, s, t, n, i) lock_acquire(l, s, t, 0, 2, n, i)
#else
	#define lock_acquire_exclusive(l, s, t, n, i) lock_acquire(l, s, t, 0, 1, n, i)
#endif
#endif /* LINUX_VERSION_IS_LESS(3,12,0) */

#endif /* __BACKPORT_LINUX_LOCKDEP_H */
