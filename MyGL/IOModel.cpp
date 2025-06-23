#include "IOModel.h"
namespace MyGL {
	IOModel::IOModel()
	{
		this->vert = 0LL;
		this->tex = 0LL;
		this->norm = 0LL;
		this->extra = 0LL;
		this->shadow_data = 0LL;
		this->msize = 0;
	}

	IOModel::~IOModel()
	{
		this->free();
	}

	void IOModel::allock(size_t vertexCount)
	{
		(*((void(__fastcall**)(IOModel* const))this->_vptr_IIOModel + 7))(this);
		this->msize = vertexCount;
		this->vert = (CGL::GLfloat*)operator new[](12LL * this->msize);
		this->tex = (CGL::GLfloat*)operator new[](8LL * this->msize);
		this->norm = (CGL::GLfloat*)operator new[](12LL * this->msize);
		memset(this->vert, 0, 12LL * this->msize);
		memset(this->tex, 0, 8LL * this->msize);
		memset(this->norm, 0, 12LL * this->msize);
	}

	void IOModel::computeTBN()
	{
		int v1;
		float v2;
		float v3;
		float v4;
		float v5;
		CGL::GLfloat* v6;
		CGL::GLfloat* v7;
		CGL::GLfloat* v8;
		__m128d v9;
		CGL::GLfloat* v10;
		CGL::GLfloat* v11;
		CGL::GLfloat* v12;
		int i_1;
		float v14;
		float v15;
		float v16;
		float v17;
		float v18;
		float pos2[4];
		float pos1[4];
		float tex2[4];
		float tex1[4];
		IIOModel::TexCoord v23;
		IIOModel::TexCoord v24;
		IIOModel::TexCoord v25;
		IIOModel::TexCoord v26;
		IIOModel::Point v27;
		IIOModel::Point v28;
		IIOModel::Point v29;
		IIOModel::Point v30;
		IIOModel::Point4 v31;
		IIOModel::Point4 v32;
		IIOModel::Point4 v33;
		IIOModel::Point4 v34;
		IIOModel::Point4 v35;
		IIOModel::Point4 v36;
		IIOModel::Point4 v37;
		IIOModel::Point4 v38;
		IIOModel::Point4 v39;
		IIOModel::Point4 v40;
		IIOModel::Point4 v41;
		float k;
		int r_6;
		int r_5;
		int r_4;
		unsigned int l;
		int r_3;
		int r_2;
		int r_1;
		int r_0;
		int r;
		int i;

		(*((void(__fastcall**)(IOModel* const))this->_vptr_IIOModel + 16))(this);
		v1 = (*((__int64(__fastcall**)(IOModel* const))this->_vptr_IIOModel + 18))(this);
		if (v1 == 3 * (v1 / 3))
		{
			for (i = 0; ; i += 3)
			{
				i_1 = (*((__int64(__fastcall**)(IOModel* const))this->_vptr_IIOModel + 18))(this);
				if (i_1 <= i)
					break;
				for (r = 0; r <= 1; ++r)
				{
					(*((void(__fastcall**)(IIOModel::TexCoord*, IOModel* const, _QWORD))this->_vptr_IIOModel + 13))(
						&v23,
						this,
						(unsigned int)(i + 1));
					v18 = *IIOModel::TexCoord::operator[](&v23, r);
					(*((void(__fastcall**)(IIOModel::TexCoord*, IOModel* const, _QWORD))this->_vptr_IIOModel + 13))(
						&v24,
						this,
						(unsigned int)i);
					v2 = v18 - *IIOModel::TexCoord::operator[](&v24, r);
					tex1[r] = v2;
					(*((void(__fastcall**)(IIOModel::TexCoord*, IOModel* const, _QWORD))this->_vptr_IIOModel + 13))(
						&v25,
						this,
						(unsigned int)(i + 2));
					v17 = *IIOModel::TexCoord::operator[](&v25, r);
					(*((void(__fastcall**)(IIOModel::TexCoord*, IOModel* const, _QWORD))this->_vptr_IIOModel + 13))(
						&v26,
						this,
						(unsigned int)i);
					v3 = v17 - *IIOModel::TexCoord::operator[](&v26, r);
					tex2[r] = v3;
				}
				for (r_0 = 0; r_0 <= 2; ++r_0)
				{
					(*((void(__fastcall**)(IIOModel::Point*, IOModel* const, _QWORD))this->_vptr_IIOModel + 12))(
						&v27,
						this,
						(unsigned int)(i + 1));
					v16 = *IIOModel::Point::operator[](&v27, r_0);
					(*((void(__fastcall**)(IIOModel::Point*, IOModel* const, _QWORD))this->_vptr_IIOModel + 12))(
						&v28,
						this,
						(unsigned int)i);
					v4 = v16 - *IIOModel::Point::operator[](&v28, r_0);
					pos1[r_0] = v4;
					(*((void(__fastcall**)(IIOModel::Point*, IOModel* const, _QWORD))this->_vptr_IIOModel + 12))(
						&v29,
						this,
						(unsigned int)(i + 2));
					v15 = *IIOModel::Point::operator[](&v29, r_0);
					(*((void(__fastcall**)(IIOModel::Point*, IOModel* const, _QWORD))this->_vptr_IIOModel + 12))(
						&v30,
						this,
						(unsigned int)i);
					v5 = v15 - *IIOModel::Point::operator[](&v30, r_0);
					pos2[r_0] = v5;
				}
				if (tex2[1] == 0.0)
				{
					if (tex2[0] == 0.0)
					{
						for (r_3 = 0; r_3 <= 2; ++r_3)
						{
							(*((void(__fastcall**)(IIOModel::Point4*, IOModel* const, _QWORD))this->_vptr_IIOModel + 15))(
								&v33,
								this,
								(unsigned int)i);
							*IIOModel::Point4::operator[](&v33, r_3) = 0.0;
						}
					}
					else
					{
						for (r_2 = 0; r_2 <= 2; ++r_2)
						{
							(*((void(__fastcall**)(IIOModel::Point4*, IOModel* const, _QWORD))this->_vptr_IIOModel + 15))(
								&v32,
								this,
								(unsigned int)i);
							v7 = IIOModel::Point4::operator[](&v32, r_2);
							*v7 = pos2[r_2] / tex2[0];
						}
					}
				}
				else
				{
					k = tex1[1] / tex2[1];
					for (r_1 = 0; r_1 <= 2; ++r_1)
					{
						(*((void(__fastcall**)(IIOModel::Point4*, IOModel* const, _QWORD))this->_vptr_IIOModel + 15))(
							&v31,
							this,
							(unsigned int)i);
						v6 = IIOModel::Point4::operator[](&v31, r_1);
						*v6 = (float)(pos1[r_1] - (float)(pos2[r_1] * k)) / (float)(tex1[0] - (float)(tex2[1] * k));
					}
				}
				(*((void(__fastcall**)(IIOModel::Point4*, IOModel* const, _QWORD))this->_vptr_IIOModel + 15))(
					&v34,
					this,
					(unsigned int)i);
				*IIOModel::Point4::operator[](&v34, 3) = 0.0;
				*(float*)&l = 0.0;
				for (r_4 = 0; r_4 <= 2; ++r_4)
				{
					(*((void(__fastcall**)(IIOModel::Point4*, IOModel* const, _QWORD))this->_vptr_IIOModel + 15))(
						&v35,
						this,
						(unsigned int)i);
					v14 = *IIOModel::Point4::operator[](&v35, r_4);
					(*((void(__fastcall**)(IIOModel::Point4*, IOModel* const, _QWORD))this->_vptr_IIOModel + 15))(
						&v36,
						this,
						(unsigned int)i);
					v8 = IIOModel::Point4::operator[](&v36, r_4);
					*(float*)&l = (float)(*v8 * v14) + *(float*)&l;
				}
				v9 = _mm_cvtps_pd((__m128)l);
				v9.m128d_f64[0] = sqrt(v9.m128d_f64[0]);
				*(float*)&l = _mm_unpacklo_pd(v9, v9).m128d_f64[0];
				for (r_5 = 0; r_5 <= 2; ++r_5)
				{
					(*((void(__fastcall**)(IIOModel::Point4*, IOModel* const, _QWORD))this->_vptr_IIOModel + 15))(
						&v37,
						this,
						(unsigned int)i);
					v10 = IIOModel::Point4::operator[](&v37, r_5);
					*v10 = *v10 / *(float*)&l;
				}
				for (r_6 = 0; r_6 <= 3; ++r_6)
				{
					(*((void(__fastcall**)(IIOModel::Point4*, IOModel* const, _QWORD))this->_vptr_IIOModel + 15))(
						&v38,
						this,
						(unsigned int)(i + 1));
					v11 = IIOModel::Point4::operator[](&v38, r_6);
					(*((void(__fastcall**)(IIOModel::Point4*, IOModel* const, _QWORD))this->_vptr_IIOModel + 15))(
						&v39,
						this,
						(unsigned int)i);
					*v11 = *IIOModel::Point4::operator[](&v39, r_6);
					(*((void(__fastcall**)(IIOModel::Point4*, IOModel* const, _QWORD))this->_vptr_IIOModel + 15))(
						&v40,
						this,
						(unsigned int)(i + 2));
					v12 = IIOModel::Point4::operator[](&v40, r_6);
					(*((void(__fastcall**)(IIOModel::Point4*, IOModel* const, _QWORD))this->_vptr_IIOModel + 15))(
						&v41,
						this,
						(unsigned int)i);
					*v12 = *IIOModel::Point4::operator[](&v41, r_6);
				}
			}
		}
	}

	void IOModel::createExtra()
	{
		if (!this->extra)
			this->extra = (CGL::GLfloat*)operator new[](16LL * this->msize);
	}

	void IOModel::deleteExtra()
	{
		if (this->extra)
			operator delete[](this->extra);
		this->extra = 0LL;
	}

	IIOModel::Point4* IOModel::exPoint(IIOModel::Point4* __return_ptr retstr, int i)
	{
		IIOModel::Point4::Point4(retstr, &this->extra[4 * i]);
		return retstr;
	}

	const CGL::GLfloat* IOModel::extraData()
	{
		return this->extra;
	}

	void IOModel::free()
	{
		this->msize = 0;
		if (this->vert)
			operator delete[](this->vert);
		if (this->tex)
			operator delete[](this->tex);
		if (this->norm)
			operator delete[](this->norm);
		if (this->extra)
			operator delete[](this->extra);
		if (this->shadow_data)
			(*(void(__fastcall**)(void*))(*(_QWORD*)this->shadow_data + 8LL))(this->shadow_data);
		this->vert = 0LL;
		this->tex = 0LL;
		this->norm = 0LL;
		this->extra = 0LL;
		this->shadow_data = 0LL;
	}

	bool IOModel::load(const std::string& fname)
	{
		__int64 v2;
		bool v3;
		CGL::GLfloat* v4;
		CGL::GLfloat* v5;
		CGL::GLfloat* v6;
		CGL::GLfloat* v7;
		CGL::GLfloat* v8;
		__int64 v9;
		__int64 v10;
		__int64 v11;
		__int64 v12;
		__int64 v13;
		__int64 v14;
		__int64 v15;
		CGL::GLfloat* v17;
		CGL::GLfloat* v18;
		_BYTE v19[540];
		int i;

		(*((void(__fastcall**)(IOModel* const))this->_vptr_IIOModel + 7))(this);
		std::fstream::basic_fstream(v19);
		v2 = std::string::data((std::string*)fname);
		std::fstream::open(v19, v2, 8LL);
		if ((unsigned __int8)std::fstream::is_open(v19) != 1)
		{
			v3 = 0;
		}
		else
		{
			std::istream::operator>>(v19, &this->msize);
			if (this->msize <= 51200)
			{
				this->vert = (CGL::GLfloat*)operator new[](12LL * this->msize);
				this->tex = (CGL::GLfloat*)operator new[](8LL * this->msize);
				this->norm = (CGL::GLfloat*)operator new[](12LL * this->msize);
				for (i = 0; this->msize > i; ++i)
				{
					v4 = &this->norm[3 * i + 2];
					v5 = &this->norm[3 * i + 1];
					v6 = &this->norm[3 * i];
					v7 = &this->tex[2 * i + 1];
					v8 = &this->tex[2 * i];
					v18 = &this->vert[3 * i + 2];
					v17 = &this->vert[3 * i + 1];
					v9 = std::istream::operator>>(v19, &this->vert[3 * i]);
					v10 = std::istream::operator>>(v9, v17);
					v11 = std::istream::operator>>(v10, v18);
					v12 = std::istream::operator>>(v11, v8);
					v13 = std::istream::operator>>(v12, v7);
					v14 = std::istream::operator>>(v13, v6);
					v15 = std::istream::operator>>(v14, v5);
					std::istream::operator>>(v15, v4);
				}
				std::fstream::close(v19);
				IOModel::computeTBN(this);
				v3 = 1;
			}
			else
			{
				this->msize = 0;
				v3 = 0;
			}
		}
		std::fstream::~fstream(v19);
		return v3;
	}

	bool IOModel::loadBin_v0(const std::string& fname)
	{
		std::_Ios_Openmode v2;
		__int64 v3;
		bool v4;
		IOModel* sh_data_1;
		_BYTE v7[264];
		__int64 v8;
		IOModel::IOInfo info;
		unsigned int i;
		void* sh_data;

		(*((void(__fastcall**)(IOModel* const))this->_vptr_IIOModel + 7))(this);
		std::fstream::basic_fstream(v7);
		v2 = std::operator|(std::_Ios_Openmode::_S_in, std::_Ios_Openmode::_S_bin);
		v3 = std::string::data((std::string*)fname);
		std::fstream::open(v7, v3, (unsigned int)v2);
		if ((unsigned __int8)std::fstream::is_open(v7))
		{
			(*((void(__fastcall**)(IOModel* const))this->_vptr_IIOModel + 7))(this);
			std::istream::read((std::istream*)v7, (char*)&this->msize, 4LL);
			if (this->msize <= 512000)
			{
				this->vert = (CGL::GLfloat*)operator new[](12LL * this->msize);
				this->tex = (CGL::GLfloat*)operator new[](8LL * this->msize);
				this->norm = (CGL::GLfloat*)operator new[](12LL * this->msize);
				std::istream::read((std::istream*)v7, (char*)this->vert, 12LL * this->msize);
				std::istream::read((std::istream*)v7, (char*)this->tex, 8LL * this->msize);
				std::istream::read((std::istream*)v7, (char*)this->norm, 12LL * this->msize);
				i = 0;
				std::istream::read((std::istream*)v7, (char*)&i, 4LL);
				if ((unsigned __int8)std::ios::eof(&v8) != 1)
				{
					memset(&info, 0, sizeof(info));
					std::istream::read((std::istream*)v7, (char*)&info, i);
					if (info.stencilModelSize)
					{
						sh_data_1 = (IOModel*)operator new(0x38uLL);
						IOModel::IOModel(sh_data_1);
						sh_data = sh_data_1;
						sh_data_1->msize = info.stencilModelSize;
						*((_QWORD*)sh_data + 1) = operator new[](12LL * info.stencilModelSize);
						std::istream::read((std::istream*)v7, *((char**)sh_data + 1), 12LL * info.stencilModelSize);
						this->shadow_data = sh_data;
					}
					if (info.extraData)
					{
						this->extra = (CGL::GLfloat*)operator new[](16LL * this->msize);
						std::istream::read((std::istream*)v7, (char*)this->extra, 16LL * this->msize);
					}
				}
				std::fstream::close(v7);
				IOModel::computeTBN(this);
				v4 = 1;
			}
			else
			{
				this->msize = 0;
				v4 = 0;
			}
		}
		else
		{
			v4 = 0;
		}
		std::fstream::~fstream(v7);
		return v4;
	}

	IOModel::Normal* IOModel::normal(IOModel::Normal* retstr, int i)
	{
		IIOModel::Point::Point(retstr, &this->norm[3 * i]);
		return retstr;
	}

	const CGL::GLfloat* IOModel::normals()
	{
		return this->norm;
	}

	IIOModel::Point* IOModel::point(IIOModel::Point* retstr, int i)
	{
		IIOModel::Point::Point(retstr, &this->vert[3 * i]);
		return retstr;
	}

	const CGL::GLfloat* IOModel::points()
	{
		return this->vert;
	}

	bool IOModel::save(const std::string& fname)
	{
		__int64 v2;
		bool v3;
		__int64 v4;
		__int64 v5;
		__int64 v6;
		__int64 v7;
		__int64 v8;
		__int64 v9;
		__int64 v10;
		__int64 v11;
		__int64 v12;
		__int64 v13;
		__int64 v14;
		__int64 v15;
		__int64 v16;
		__int64 v17;
		__int64 v18;
		__int64 v19;
		float v21;
		float v22;
		float v23;
		float v24;
		float v25;
		float v26;
		float v27;
		_BYTE v28[16];
		_BYTE v29[524];
		int i;

		std::fstream::basic_fstream(v28);
		v2 = std::string::data((std::string*)fname);
		std::fstream::open(v28, v2, 16LL);
		if ((unsigned __int8)std::fstream::is_open(v28) != 1)
		{
			v3 = 0;
		}
		else
		{
			v4 = std::ostream::operator<<(v29, (unsigned int)this->msize);
			std::ostream::operator<<(v4, &std::endl<char, std::char_traits<char>>);
			for (i = 0; this->msize > i; ++i)
			{
				v27 = this->norm[3 * i + 2];
				v26 = this->norm[3 * i + 1];
				v25 = this->norm[3 * i];
				v24 = this->tex[2 * i + 1];
				v23 = this->tex[2 * i];
				v22 = this->vert[3 * i + 2];
				v21 = this->vert[3 * i + 1];
				v5 = std::ostream::operator<<(v29, this->vert[3 * i]);
				v6 = std::operator<<<std::char_traits<char>>(v5, &unk_4D36E0);
				v7 = std::ostream::operator<<(v6, v21);
				v8 = std::operator<<<std::char_traits<char>>(v7, &unk_4D36E0);
				v9 = std::ostream::operator<<(v8, v22);
				v10 = std::operator<<<std::char_traits<char>>(v9, &unk_4D36E0);
				v11 = std::ostream::operator<<(v10, v23);
				v12 = std::operator<<<std::char_traits<char>>(v11, &unk_4D36E0);
				v13 = std::ostream::operator<<(v12, v24);
				v14 = std::operator<<<std::char_traits<char>>(v13, &unk_4D36E0);
				v15 = std::ostream::operator<<(v14, v25);
				v16 = std::operator<<<std::char_traits<char>>(v15, &unk_4D36E0);
				v17 = std::ostream::operator<<(v16, v26);
				v18 = std::operator<<<std::char_traits<char>>(v17, &unk_4D36E0);
				v19 = std::ostream::operator<<(v18, v27);
				std::ostream::operator<<(v19, &std::endl<char, std::char_traits<char>>);
			}
			std::fstream::close(v28);
			v3 = 1;
		}
		std::fstream::~fstream(v28);
		return v3;
	}

	bool IOModel::saveBin(const std::string& fname)
	{
		std::_Ios_Openmode v2;
		__int64 v3;
		bool v4;
		__int64 v5;
		const char* v6;
		_BYTE v8[16];
		_BYTE v9[524];
		unsigned int i;
		IOModel::IOInfo info;

		std::fstream::basic_fstream(v8);
		v2 = std::operator|(std::_Ios_Openmode::_S_out, std::_Ios_Openmode::_S_bin);
		v3 = std::string::data((std::string*)fname);
		std::fstream::open(v8, v3, (unsigned int)v2);
		if ((unsigned __int8)std::fstream::is_open(v8) != 1)
		{
			v4 = 0;
		}
		else
		{
			std::ostream::write(v9, (const char*)&this->msize, 4LL);
			std::ostream::write(v9, (const char*)this->vert, 12LL * this->msize);
			std::ostream::write(v9, (const char*)this->tex, 8LL * this->msize);
			std::ostream::write(v9, (const char*)this->norm, 12LL * this->msize);
			if (this->shadow_data)
				info.stencilModelSize = (*(__int64(__fastcall**)(void*))(*(_QWORD*)this->shadow_data + 144LL))(this->shadow_data);
			else
				info.stencilModelSize = 0;
			info.extraData = this->extra != 0LL;
			i = 20;
			std::ostream::write(v9, (const char*)&i, 4LL);
			std::ostream::write(v9, (const char*)&info, 20LL);
			if (info.stencilModelSize)
			{
				v5 = 12LL * (*(int(__fastcall**)(void*))(*(_QWORD*)this->shadow_data + 144LL))(this->shadow_data);
				v6 = (const char*)(*(__int64(__fastcall**)(void*))(*(_QWORD*)this->shadow_data + 64LL))(this->shadow_data);
				std::ostream::write(v9, v6, v5);
			}
			if (this->extra)
				std::ostream::write(v9, (const char*)this->extra, 16LL * this->msize);
			std::fstream::close(v8);
			v4 = 1;
		}
		std::fstream::~fstream(v8);
		return v4;
	}

	int IOModel::size()
	{
		return this->msize;
	}

	IIOModel::TexCoord* IOModel::texCoord(IIOModel::TexCoord* retstr, int i)
	{
		IIOModel::TexCoord::TexCoord(retstr, &this->tex[2 * i]);
		return retstr;
	}

	const CGL::GLfloat* IOModel::textureCoords()
	{
		return this->tex;
	}
}