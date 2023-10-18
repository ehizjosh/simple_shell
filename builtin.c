#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exit_code;

	if (info->argv[1])
	{
		exit_code = _atoi(info->argv[1]);
		if (exit_code == -1)
		{
			info->status = 2;
			print_error(info, "Invalid exit code: ");
			_puts(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *s, *new_dir, buffer[1024];
	int chdir_result;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		new_dir = _getenv(info, "HOME=");
		if (!new_dir)
			chdir_result = chdir((new_dir = _getenv(info, "PWD=")) ? new_dir : "/");
		else
			chdir_result = chdir(new_dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_result = chdir((new_dir = _getenv(info, "OLDPWD=")) ? new_dir : "/");
	}
	else
		chdir_result = chdir(info->argv[1]);
	if (chdir_result == -1)
	{
		print_error(info, "can't cd to");
		_puts(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help command works. Function not yet implemented.\n");

	if (0)
		_puts(*arg_array);
		return (0);
}
