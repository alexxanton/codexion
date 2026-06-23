#include <codexion.h>

void	*monitor_func(void *arg)
{
	t_data		*data;

	data = (t_data *) arg;
	printf("Monitor monitoring monitoringfully!\n");
	while (true)
		printf("%d\n", data->coders[0].compiles_left);
	(void)data;
	return (NULL);
}

t_monitor	*init_monitor(t_data *data)
{
	int			errors;
	t_monitor	*monitor;

	monitor = malloc(sizeof(t_monitor));
	if (!monitor)
		return (NULL);
	errors = pthread_create(&monitor->thread_id, NULL, monitor_func, data);
	if (errors > 0)
	{
		free(monitor);
		return (NULL);
	}
	return (monitor);
}
