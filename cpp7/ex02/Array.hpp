/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:23:47 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/25 21:07:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class	Array
{
	private:
		T* 			_array;
		unsigned int _size;
	public:
		Array()
			: _array(NULL), _size(0)
		{
		}
		Array(unsigned int N)
			: _array(new T[N]()), _size(N)
		{
		}
		~Array()
		{
			if (this->_array)
				delete[] this->_array;
		}
		int size() const
		{
			return (this->_size);
		}

		Array(const Array &cp)
			: _size(cp._size)
		{
			if (cp._array)
			{
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
				{
					this->_array[i] = cp._array[i];
				}
			}
			else
			{
				this->_array = NULL;
			}
		}
		Array& operator= (const Array &cp)
		{
			if (this != &cp)
			{
				delete[] this->_array;
				this->_size = cp._size;
				if (cp._array)
				{
					this->_array = new T[this->_size];
					for (unsigned int i = 0; i < this->_size; i++)
					{
						this->_array[i] = cp._array[i];
					}
				}
				else
				{
					this->_array = NULL;
				}
			}
			return (*this);
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("index out of bounds");
			return (this->_array[index]);
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::out_of_range("index out of bounds");
			return (this->_array[index]);
		}
};

#endif
