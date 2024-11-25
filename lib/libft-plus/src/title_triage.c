/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_triage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:51:39 by aska              #+#    #+#             */
/*   Updated: 2024/11/25 18:42:47 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	for_a_to_l(char c, t_alphanode **chara)
{
	if (c == 'a' || c == 'A')
		insert_end_alpha(chara, letter_creation(ASCII_A));
	if (c == 'b' || c == 'B')
		insert_end_alpha(chara, letter_creation(ASCII_B));
	if (c == 'c' || c == 'C')
		insert_end_alpha(chara, letter_creation(ASCII_C));
	if (c == 'd' || c == 'D')
		insert_end_alpha(chara, letter_creation(ASCII_D));
	if (c == 'e' || c == 'E')
		insert_end_alpha(chara, letter_creation(ASCII_E));
	if (c == 'f' || c == 'F')
		insert_end_alpha(chara, letter_creation(ASCII_F));
	if (c == 'g' || c == 'G')
		insert_end_alpha(chara, letter_creation(ASCII_G));
	if (c == 'h' || c == 'H')
		insert_end_alpha(chara, letter_creation(ASCII_H));
	if (c == 'i' || c == 'I')
		insert_end_alpha(chara, letter_creation(ASCII_I));
	if (c == 'j' || c == 'J')
		insert_end_alpha(chara, letter_creation(ASCII_J));
	if (c == 'k' || c == 'K')
		insert_end_alpha(chara, letter_creation(ASCII_K));
	if (c == 'l' || c == 'L')
		insert_end_alpha(chara, letter_creation(ASCII_L));
}

void	for_m_to_x(char c, t_alphanode **chara)
{
	if (c == 'm' || c == 'M')
		insert_end_alpha(chara, letter_creation(ASCII_M));
	if (c == 'n' || c == 'N')
		insert_end_alpha(chara, letter_creation(ASCII_N));
	if (c == 'o' || c == 'O')
		insert_end_alpha(chara, letter_creation(ASCII_O));
	if (c == 'p' || c == 'P')
		insert_end_alpha(chara, letter_creation(ASCII_P));
	if (c == 'q' || c == 'Q')
		insert_end_alpha(chara, letter_creation(ASCII_Q));
	if (c == 'r' || c == 'R')
		insert_end_alpha(chara, letter_creation(ASCII_R));
	if (c == 's' || c == 'S')
		insert_end_alpha(chara, letter_creation(ASCII_S));
	if (c == 't' || c == 'T')
		insert_end_alpha(chara, letter_creation(ASCII_T));
	if (c == 'u' || c == 'U')
		insert_end_alpha(chara, letter_creation(ASCII_U));
	if (c == 'v' || c == 'V')
		insert_end_alpha(chara, letter_creation(ASCII_V));
	if (c == 'w' || c == 'W')
		insert_end_alpha(chara, letter_creation(ASCII_W));
	if (c == 'x' || c == 'X')
		insert_end_alpha(chara, letter_creation(ASCII_X));
}

void	for_y_to_9(char c, t_alphanode **chara)
{
	if (c == 'y' || c == 'Y')
		insert_end_alpha(chara, letter_creation(ASCII_Y));
	if (c == 'z' || c == 'Z')
		insert_end_alpha(chara, letter_creation(ASCII_Z));
	if (c == '0')
		insert_end_alpha(chara, letter_creation(ASCII_ZERO));
	if (c == '1')
		insert_end_alpha(chara, letter_creation(ASCII_ONE));
	if (c == '2')
		insert_end_alpha(chara, letter_creation(ASCII_TWO));
	if (c == '3')
		insert_end_alpha(chara, letter_creation(ASCII_THREE));
	if (c == '4')
		insert_end_alpha(chara, letter_creation(ASCII_FOUR));
	if (c == '5')
		insert_end_alpha(chara, letter_creation(ASCII_FIVE));
	if (c == '6')
		insert_end_alpha(chara, letter_creation(ASCII_SIX));
	if (c == '7')
		insert_end_alpha(chara, letter_creation(ASCII_SEVEN));
	if (c == '8')
		insert_end_alpha(chara, letter_creation(ASCII_EIGHT));
	if (c == '9')
		insert_end_alpha(chara, letter_creation(ASCII_NINE));
}

void	for_symbol(char c, t_alphanode **chara)
{
	if (c == ' ')
		insert_end_alpha(chara, letter_creation(ASCII_SPACE));
	if (c == ',')
		insert_end_alpha(chara, letter_creation(ASCII_COMMA));
	if (c == '.')
		insert_end_alpha(chara, letter_creation(ASCII_DOT));
	if (c == '-')
		insert_end_alpha(chara, letter_creation(ASCII_HYPHEN));
	if (c == '_')
		insert_end_alpha(chara, letter_creation(ASCII_UNDERSCORE));
	if (c == '(')
		insert_end_alpha(chara, letter_creation(ASCII_BRACKET_ON));
	if (c == ')')
		insert_end_alpha(chara, letter_creation(ASCII_BRACKET_OFF));
	if (c == '*')
		insert_end_alpha(chara, letter_creation(ASCII_ASTERISK));
}
