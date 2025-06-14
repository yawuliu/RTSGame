#include "qtshader.h"
#include "MyGL/IUniform4f.h"

#include <MyGL/Uniform1f.h>
#include <MyGL/Uniform4f.h>
#include <MyGL/UniformMatrix4x4.h>
#include <MyGL/UniformSampler.h>
#include <MyGL/UniformArray.h>
#include <MyGL/CGL.h>
#include <MyGL/IRender.h>
#include <MyGL/IErrorControl.h>

#include <string>
#include <QDebug>
#include <QOpenGLShader>



QtShader::QtShader(MyGL::IRender* r) : AbstractShader(r) {

}

void QtShader::loadVertexSource(const char* src) {
	//loadSH(QGLShader::Vertex,   file);
//		qDebug() << src;
	if (!prog.addShaderFromSourceCode(QOpenGLShader::Vertex, src)) {
		qDebug() << src;
		std::string str = "Shader compile error: \n" + prog.log().toStdString();
		render()->gl()->errorCtrl()->compileError(this, str.data());
	}

}

void QtShader::loadFragmentSource(const char* src) {
	//loadSH(QGLShader::Fragment, file);
	if (!prog.addShaderFromSourceCode(QOpenGLShader::Fragment, src)) {
		std::string str = "Shader compile error: \n" + prog.log().toStdString();
		render()->gl()->errorCtrl()->compileError(this, str.data());
	}
}

void QtShader::printInfoLog() {
	qDebug() << prog.log();
}

void QtShader::compile(bool autoLink) {

	if (autoLink)
		link();
}

void QtShader::link() {
	prog.link();
}

bool QtShader::isLinked() {
	return prog.isLinked();
}

void QtShader::use() {
	prog.bind();
	sendUniformsToGPU();
}

void QtShader::unUse() {
	prog.release();
}

const char* QtShader::getVSLog() {
	static const char* r = "QtShader::getVSLog not suporised";
	return r;
}

const char* QtShader::getFSLog() {
	static const char* r = "QtShader::getFSLog not suporised";
	return r;
}

MyGL::IUniformSampler* QtShader::uniformSampler(const char* name) {
	GLint h = prog.uniformLocation(name);

	return MyGL::uniform<MyGL::UniformSampler>((int)h);
}

MyGL::IUniform1f* QtShader::uniform1f(const char* name) {
	GLint h = prog.uniformLocation(name);

	return MyGL::uniform<MyGL::Uniform1f>((int)h);
}

MyGL::IUniform4f* QtShader::uniform4f(const char* name) {
	GLint h = prog.uniformLocation(name);

	return MyGL::uniform<MyGL::Uniform4f>((int)h);
}

MyGL::IUniformMatrix4x4* QtShader::uniformMatrix4x4(const char* name) {
	GLint h = prog.uniformLocation(name);

	return MyGL::uniform<MyGL::UniformMatrix4x4>((int)h);
}

MyGL::UniformArray<MyGL::IUniformMatrix4x4>* QtShader::uniformMat4x4Array(const char* name, int s) {
	GLint h = prog.uniformLocation(name);

	return MyGL::uniformArray<MyGL::UniformArray<MyGL::IUniformMatrix4x4> >((int)h, s);
}
