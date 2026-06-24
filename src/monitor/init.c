#include <codexion.h>

void	*monitor_func(void *arg)
{
	t_data	*data;
	t_coder	*coder;

	data = (t_data *) arg;
	printf("Monitor monitoring monitoringfully!\n");
	coder = &data->coders[0];
	while (!has_finished(coder))
	{
		//pthread_mutex_lock(&coder->lock);
		//printf("%d\n", coder->compiles_left);
		//pthread_mutex_unlock(&coder->lock);
		usleep(30000);
	}
	(void)data;
	return (NULL);
}

t_monitor	*init_monitor(t_data *data)
{
	//int			errors;
	t_monitor	*monitor;

	monitor = malloc(sizeof(t_monitor));
	if (!monitor)
		return (NULL);
	//errors = pthread_create(&monitor->thread_id, NULL, monitor_func, data);
	//if (errors > 0)
	//{
	//	free(monitor);
	//	return (NULL);
	//}
	(void)data;
	return (monitor);
}
