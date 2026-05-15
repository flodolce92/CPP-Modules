/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 01:17:13 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/13 01:17:19 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
std::string PmergeMe::containerToString(const T &container)
{
	std::stringstream ss;
	typename T::const_iterator it = container.begin();
	ss << "[";
	while (it != container.end())
	{
		if (it != container.begin())
			ss << " ";
		ss << *it;
		++it;
	}
	ss << "]";
	return ss.str();
}
