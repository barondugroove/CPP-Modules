/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:01:48 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/30 16:24:08 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
T const &max(T const &x, T const &y) {
	return (x >= y ? x : y);
}

template<typename T>
T const &min(T const &x, T const &y) {
	return (x <= y ? x : y);
}

template<typename T>
void swap(T &x, T &y) {
	T buf = x;
	x = y;
	y = buf;
}
