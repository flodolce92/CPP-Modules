#ifndef SPAN_HPP
# define SPAN_HPP

#include "debug.hpp"

class Span
{
	private:

	public:
		// Constructors and destructor
		Span();
		Span(const Span &src);
		~Span();

		// Operator overloads
		Span &operator=(const Span &src);

		// Methods
};

#endif
