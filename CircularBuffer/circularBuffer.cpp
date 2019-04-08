#include <iostream>
#include <Windows.h>

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer()
{
	m_start = 0;
	m_end = 0;
	m_size = 0;
}

CircularBuffer::~CircularBuffer()
{
}

void CircularBuffer::Push(float value)
{
	array[m_start] = value;
	m_start = (m_start + 1) % BUFFER_SIZE;
	m_size++;

	int overflow = m_size - BUFFER_SIZE;

	if (overflow > 0)
	{
		std::cout << std::endl << "Replaced oldest number" << std::endl;
		m_size -= overflow;
		m_end = (m_end + overflow) % BUFFER_SIZE;
	}
}

void CircularBuffer::Pop()
{
	if (m_size <= 0)
	{
		std::cout << "Nothing to remove!" << std::endl;
	}
	float value = getOldest();

	m_end = (m_end + 1) % BUFFER_SIZE;
	--m_size;
}

int CircularBuffer::getSize()
{
	return m_size;
}

float CircularBuffer::getValue(int location)
{
	int currentIndex = location;
	return array[currentIndex];
}

float CircularBuffer::getRelativeValue(int location)
{
	int currentIndex = 0;

	if (m_size < BUFFER_SIZE)
	{
		int m_gap = BUFFER_SIZE - m_size;
		currentIndex = (BUFFER_SIZE - location) - m_gap;
	}
	else
	{
		if (location < m_end)
		{
			currentIndex = abs((location - m_start));

		}
		else
		{
			currentIndex = (abs(location - BUFFER_SIZE)) + m_start;
		}
	}

	return array[currentIndex - 1];
}

float CircularBuffer::getLatest(int value)
{
	return array[m_start];
}

float CircularBuffer::getOldest()
{
	return array[m_start - 1];
}
