#pragma once
#ifndef _CIRCULARBUFFER_H_INCLUDED
#define _CIRCULARBUFFER_H_INCLUDED

#define BUFFER_SIZE 5

class CircularBuffer
{
private:
	int m_start;
	int m_size;
	int m_end;

public:
	
	float array[BUFFER_SIZE];

	CircularBuffer();
	~CircularBuffer();

	void Push(float value);
	void Pop();
	int getSize();
	float getValue(int location);
	float getRelativeValue(int location);
	float getLatest(int value);
	float getOldest();

};

#endif // !_CIRCULARBUFFER_H_INCLUDED
