/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   log.c                                                   :+:    :+:       */
/*                                                          +:+               */
/*   By: mde-beer <mde-beer@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/17 18:12:25 by mde-beer            #+#    #+#           */
/*   Updated: 2026/01/17 19:19:51 by mde-beer            ########   odam.nl   */
/*                                                                            */
/*   —————No norm compliance?——————                                           */
/*   ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝                                           */
/*   ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇                                           */
/*   ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀                                           */
/*   ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀⠀                                           */
/*   ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ——————————————————————————————                                           */
/* ************************************************************************** */

#include <errno.h>
#include <libft.h>
#include <framework.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void	unknown_logger(t_test test, const int fd);
void	err_logger(t_test test, const int fd);
void	ok_logger(t_test test, const int fd);
void	ko_logger(t_test test, const int fd);
void	segv_logger(t_test test, const int fd);
void	bus_logger(t_test test, const int fd);
void	abrt_logger(t_test test, const int fd);
void	fpe_logger(t_test test, const int fd);
void	pipe_logger(t_test test, const int fd);
void	ill_logger(t_test test, const int fd);
void	time_logger(t_test test, const int fd);

#define LOGGER_COUNT 11

const static struct s_loggers
{
	t_status	status;
	void		(*func)(t_test test, const int fd);
}	g_loghelpers[LOGGER_COUNT] = {
	{UNKNOWN, unknown_logger},
	{ERR, err_logger},
	{OK, ok_logger},
	{KO, ko_logger},
	{SEGV, segv_logger},
	{BUS, bus_logger},
	{ABRT, abrt_logger},
	{FPE, fpe_logger},
	{PIPE, pipe_logger},
	{ILL, ill_logger},
	{TIME, time_logger}
};

void	ko_logger(t_test test, const int fd)
{
	char *const	is_launcher
		= ft_strnstr(test.name, "tests", ft_strlen(test.name));

	ft_dprintf(fd,
		C_KO
		"%s failed.",
		test.name
		);
	if (is_launcher)
	{
		ft_dprintf(fd,
			" look in %.*s.log for more detailed information.",
			(int)(is_launcher - (test.name - 1)),
			test.name
			);
	}
	ft_dprintf(fd, "\n");
}

void	ok_logger(t_test test, const int fd)
{
	ft_dprintf(fd,
		C_OK
		"%s passed.\n",
		test.name
		);
}

void	err_logger(t_test test, const int fd)
{
	ft_dprintf(fd,
		C_ERR
		"A standard library function failed unexpectedly while preparing %s. "
		"It's exceedingly unlikely your code is at fault.\n",
		test.name
		);
}

void	unknown_logger(t_test test, const int fd)
{
	ft_dprintf(fd,
		"Somehow, %s didnt execute. "
		"This is most likely an error with the tests, not with your code.\n",
		test.name
		);
}

#define DIR "./logs/"

void	log_test(const char *file_basename, t_test test)
{
	struct stat	statbuf;
	char		*path;
	char		*tmp;
	int			fd;
	int			i;

	path = ft_strjoin(file_basename, ".log");
	if (!path)
		return ;
	if (stat(DIR, &statbuf) && mkdir(DIR, 0755))
		return ;
	tmp = ft_strjoin(DIR, path);
	free(path);
	path = tmp;
	if (!path)
		return ;
	fd = open(path, (O_WRONLY | O_APPEND | O_CREAT), 0644);
	free(path);
	if (fd < 0)
		return ;
	i = -1;
	while (++i < LOGGER_COUNT)
		if (test.status == g_loghelpers[i].status)
			g_loghelpers[i].func(test, fd);
	close(fd);
}
