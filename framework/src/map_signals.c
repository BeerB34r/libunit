/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   map_signals.c                                           :+:    :+:       */
/*                                                          +:+               */
/*   By: mde-beer <mde-beer@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/17 15:33:28 by mde-beer            #+#    #+#           */
/*   Updated: 2026/01/17 15:33:44 by mde-beer            ########   odam.nl   */
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

#include <framework.h>
#include <signal.h>

#define SUPPORTED_SIGNALS 7

const static struct s_map_sig_stat
{
	int			sig;
	t_status	status;
}	g_map_sig_stat[SUPPORTED_SIGNALS] = {
	{SIGSEGV, SEGV},
	{SIGBUS, BUS},
	{SIGABRT, ABRT},
	{SIGFPE, FPE},
	{SIGPIPE, PIPE},
	{SIGILL, ILL},
	{SIGALRM, TIME}
};

t_status	map_signal_status(int signal)
{
	unsigned int	i;

	i = -1;
	while (++i < SUPPORTED_SIGNALS)
		if (g_map_sig_stat[i].sig == signal)
			return (g_map_sig_stat[i].status);
	return (ERR);
}

#define SUPPORTED_RETVAL_COUNT 10

const static struct s_map
{
	unsigned char	retval;
	t_status		status;
}	g_map_ret_stat[SUPPORTED_RETVAL_COUNT] = {
	{0, OK},
	{1, KO},
	{2, SEGV},
	{3, BUS},
	{4, ABRT},
	{5, FPE},
	{6, PIPE},
	{7, ILL},
	{8, TIME},
	{-1, KO}
};

int	map_status_retval(t_status stat)
{
	unsigned int	i;

	i = -1;
	while (++i < SUPPORTED_RETVAL_COUNT)
		if (g_map_ret_stat[i].status == stat)
			return (g_map_ret_stat[i].retval);
	return (SUPPORTED_RETVAL_COUNT);
}

t_status	map_retval_status(int retval)
{
	unsigned int	i;

	i = -1;
	while (++i < SUPPORTED_RETVAL_COUNT)
		if (g_map_ret_stat[i].retval == retval)
			return (g_map_ret_stat[i].status);
	return (ERR);
}
