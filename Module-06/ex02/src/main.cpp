/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:12:03 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/25 17:26:35 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	Base *p = NULL;
	int r = rand() % 3;

	if (r == 0)
		p = new A();
	else if (r == 1)
		p = new B();
	else
		p = new C();
	return (p);
}

void identify(Base *p)
{
	if (!p)
	{
		std::cout << "Null pointer" << std::endl;
		return;
	}

	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return;
	}
	catch (const std::exception &)
	{
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return;
	}
	catch (const std::exception &)
	{
	}

	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

int main()
{
	srand(time(NULL));
	Base *arr[5];

	for (int i = 0; i < 5; ++i)
	{
		arr[i] = generate();
	}

	std::cout << "Pointers identification:" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		identify(arr[i]);
	}

	std::cout << "\nReferences identification:" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		identify(*arr[i]);
	}

	for (int i = 0; i < 5; ++i)
	{
		delete arr[i];
	}

	std::cout << "\nTesting with a base class pointer:" << std::endl;
	Base *base = new Base();

	identify(base);
	identify(*base);
	delete base;

	return (0);
}
