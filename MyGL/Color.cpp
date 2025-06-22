#include "Color.h"

MyGL::Color::Color(ChanelType c) {
	set(c);
}

MyGL::Color::Color(ChanelType r, ChanelType g, ChanelType b, ChanelType a) {
	set(r, g, b, a);
}

MyGL::Color::Color() {
	set(1.0);
}

MyGL::Color::ChanelType MyGL::Color::a() {
	return data()[3];
}

MyGL::Color::ChanelType MyGL::Color::b() {
	return data()[2];
}

const MyGL::Color::ChanelType* MyGL::Color::data() {
	return this->cdata;
}

MyGL::Color::ChanelType MyGL::Color::g() {
	return data()[1];
}

void MyGL::Color::operator+(const Color& other) {
	Color v2;
	for (int i = 0; i <= 3; ++i)
		v2.cdata[i] = other.cdata[i] + this->cdata[i];
}

void MyGL::Color::operator+=(const Color& other) {
	for (int i = 0; i <= 3; ++i)
		this->cdata[i] = other.cdata[i] + this->cdata[i];
}

void MyGL::Color::operator-(const Color& other) {
	Color v2;
	for (int i = 0; i <= 3; ++i)
		v2.cdata[i] = this->cdata[i] - other.cdata[i];
}

void MyGL::Color::operator-=(const Color& other) {
	for (int i = 0; i <= 3; ++i)
		this->cdata[i] = this->cdata[i] - other.cdata[i];
}

void* MyGL::Color::operator=(const Color& other) {
	for (int i = 0; i <= 3; ++i)
		this->cdata[i] = other.cdata[i];
	return this;
}

MyGL::Color::ChanelType MyGL::Color::r() {
	return data()[0];
}

void MyGL::Color::set(ChanelType rgba) {
	int i;

	for (i = 0; i <= 3; ++i)
		this->cdata[i] = rgba;
}

void MyGL::Color::set(ChanelType r, ChanelType g, ChanelType b, ChanelType a) {
	this->cdata[0] = r;
	this->cdata[1] = g;
	this->cdata[2] = b;
	this->cdata[3] = a;
}
