/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 03:28:57 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/20 03:46:07 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H

# define KEYCODES_H
/*
gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit libft/src/*.c src/*.c -o output
*/
# ifdef OSX
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_Q 12
#  define KEY_R 15
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_E 14
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# else
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_E 101
#  define KEY_Q 113
#  define KEY_R 114
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

#endif
