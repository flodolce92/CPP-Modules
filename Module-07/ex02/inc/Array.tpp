/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:41:07 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/07 20:24:09 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : n(0)
{
	DEBUG_LOG("Default constructor called", BLUE);
	this->arr = new T[n];
}

template <typename T>
Array<T>::Array(unsigned int n) : n(n)
{
	DEBUG_LOG("Constructor with n called", BLUE);
	this->arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array &src) : n(src.n)
{
	DEBUG_LOG("Copy constructor called", BLUE);
	this->arr = new T[n];
	for (size_t i = 0; i < n; i++)
		this->arr[i] = src.arr[i];
}

template <typename T>
Array<T>::~Array()
{
	DEBUG_LOG("Destructor called", BLUE);
	delete[] this->arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &src)
{
	DEBUG_LOG("Assignment operator called", BLUE);
	if (this == &src)
		return (*this);

	if (this->arr)
		delete[] this->arr;

	this->n = src.n;
	this->arr = new T[n];
	for (size_t i = 0; i < n; i++)
		this->arr[i] = src.arr[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t idx)
{
	if (idx >= this->n)
		throw std::out_of_range("Index out of range");
	return (this->arr[idx]);
}

template <typename T>
size_t Array<T>::size() const
{
	return (this->n);
}
