#ifndef TYPES_H
# define TYPES_H

# include "main.h"

/*
**	This file contains only the types and defs used on more than one file across
**	the program.
*/

# define DEAD			-1
# define THINK			0
# define FIRST_FORK		1
# define SECOND_FORK	2
# define EAT			3
# define SLEEP			4
# define MILLISECS_IN_A_SEC 1000

/*
**	ERRORS
*/

typedef enum e_errors {
	ILLEGAL_INPUT				= -1,
	MALLOC_FAILED				= -2,
	THREAD_CREATION_FAILED		= -3,
	THREAD_JOINING_FAILED		= -4,
	MUTEX_FAILED				= -5,
	GET_TIME_FAILED				= -6,
}	t_errors;

typedef struct timeval	t_timeval;

typedef struct s_philo {
	int				index;
	int				status;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				must_eat;
	int				meal_count;
	t_timeval		last_meal_start;
	int				first_fork;
	int				second_fork;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data {
	int				nb_philo;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	bool			*is_fork_available;
	pthread_mutex_t	is_everybody_alive_lock;
	bool			is_everybody_alive;
	t_timeval		start_time_ms;
}	t_data;

#endif
