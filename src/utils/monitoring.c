#include <codexion.h>

bool	has_finished(t_coder *coder)
{
	bool	finished;
	pthread_mutex_lock(&coder->lock);
	finished = coder->compiles_left <= 0;
	pthread_mutex_unlock(&coder->lock);
	return (finished);
}
