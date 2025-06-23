#pragma once
#include <cstdint>
#include <fstream>
#include <ostream>
#include "IIOModel.h"
#include "CGL.h"

namespace MyGL {
	class IOModel :public IIOModel {
	public:
		IOModel();
		virtual ~IOModel();
		void allock(size_t vertexCount);
		void computeTBN();
		void createExtra();
		void deleteExtra();
		IIOModel::Point4* exPoint(IIOModel::Point4* retstr, int i);
		const CGL::GLfloat* extraData();
		void free();
		bool load(const std::string& fname);
		bool loadBin_v0(const std::string& fname);
		IOModel::Normal* normal(IOModel::Normal* retstr, int i);
		const CGL::GLfloat* normals();
		IIOModel::Point* point(IIOModel::Point* retstr, int i);
		const CGL::GLfloat* points();
		bool save(const std::string& fname);
		bool saveBin(const std::string& fname);
		int size();
		IIOModel::TexCoord* texCoord(IIOModel::TexCoord* retstr, int i);
		const CGL::GLfloat* textureCoords();
	protected:
		CGL::GLfloat* vert;
		CGL::GLfloat* tex;
		CGL::GLfloat* norm;
		CGL::GLfloat* extra;
		int msize;
		//0000002C     // padding byte
		//    0000002D     // padding byte
		//    0000002E     // padding byte
		//    0000002F     // padding byte
		void* shadow_data;
	};
}


