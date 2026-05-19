/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 05:51:26 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/20 00:50:25 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
std::string PmergeMe::containerToString(const T &container)
{
	std::stringstream ss;
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		ss << *it << " ";
	}
	return ss.str();
}
