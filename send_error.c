/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:32:31 by luserbu           #+#    #+#             */
/*   Updated: 2022/06/15 18:08:26 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void    parsing_message_error(t_data *data, char *str)
{
    int len;
    int x;

    x = 0;
    len = (int)ft_strlen(str);
    while (len >= 0)
    {
        data->error[x] = malloc(sizeof(char *) * (int)ft_strlen(str) + 1);
        //ft_printf("%s\n", data->error[x]);
        x++;
        len--;
    }
}

void    error_message(t_data *data, char *str)
{
    int x;
    int y;
    int len;
    int tmp;

    parsing_message_error(data, str);
    tmp = 0;
    len = (int)ft_strlen(str);
    x = 0;
    while (x < 5)
    {
        y = 0;
        while(y < len + 6)
        {
            if (x == 2 && y == 3)
            {
                // data->error[x][y] = '/';
                // data->error[x][y + 1] = '.';
                // data->error[x][y + 2] = '.';
                while (tmp < len)
                {
                    data->error[x][y] = str[len - tmp];
                    //ft_printf("%c", data->error[x][y]);
                    tmp++;
                    y++;
                }
            }
            else if (x == 0 && (y > 0 && y < len + 5))
                data->error[x][y] = '*';
            else if (x == 4 && (y > 0 && y < len + 5))
                data->error[x][y] = '*';
            else if (x >= 0 && x <= 4 && y == 0)
                data->error[x][y] = '/';
            else if (x >= 0 && x <= 4 && y == len + 5)
                data->error[x][y] = '/';
            else
                  data->error[x][y] = '.';
            // ft_printf("%c", data->error[x][y]);
            y++;
           // ft_printf("%c", data->error[x][y]);
        }
        ft_printf("%s\n", data->error[x]);
        //ft_printf("\n");
        x++;
    }
}