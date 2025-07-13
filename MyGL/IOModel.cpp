#include <cstring>
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
		this->free();
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
        this->createExtra();
		int v1 = this->size();
		if (v1 == 3 * (v1 / 3))
		{
			for (int i = 0; ; i += 3)
			{
				if (this->size() <= i)
					break;
				for (int r = 0; r <= 1; ++r)
				{
					v18 = this->texCoord((unsigned int)(i + 1))[r];
					v2 = v18 - this->texCoord((unsigned int)i)[r];
					tex1[r] = v2;
					v17 = this->texCoord((unsigned int)(i + 2))[r];
					v3 = v17 - this->texCoord((unsigned int)i)[r];
					tex2[r] = v3;
				}
				for (int r_0 = 0; r_0 <= 2; ++r_0)
				{
					v16 = this->point((unsigned int)(i + 1))[r_0];
					v4 = v16 - this->point((unsigned int)i)[r_0];
					pos1[r_0] = v4;
					v15 = this->point((unsigned int)(i + 2))[r_0];
					v5 = v15 - this->point((unsigned int)i)[r_0];
					pos2[r_0] = v5;
				}
				if (tex2[1] == 0.0)
				{
					if (tex2[0] == 0.0)
					{
						for (int r_3 = 0; r_3 <= 2; ++r_3)
						{
                            this->exPoint((unsigned int)i)[r_3] = 0.0;
						}
					}
					else
					{
						for ( int r_2 = 0; r_2 <= 2; ++r_2)
						{
							v7 = this->exPoint((unsigned int)i)[r_2];
							*v7 = pos2[r_2] / tex2[0];
						}
					}
				}
				else
				{
					k = tex1[1] / tex2[1];
					for (int r_1 = 0; r_1 <= 2; ++r_1)
					{
						v6 = this->exPoint((unsigned int)i)[r_1];
						*v6 = (float)(pos1[r_1] - (float)(pos2[r_1] * k)) / (float)(tex1[0] - (float)(tex2[1] * k));
					}
				}
                this->exPoint((unsigned int)i)[3] = 0.0;
				*(float*)&l = 0.0;
				for ( int r_4 = 0; r_4 <= 2; ++r_4)
				{
					v14 = this->exPoint((unsigned int)i)[r_4];
					v8 = this->exPoint((unsigned int)i)[r_4];
					*(float*)&l = (float)(*v8 * v14) + *(float*)&l;
				}
				v9 = _mm_cvtps_pd((__m128)l);
				v9.m128d_f64[0] = sqrt(v9.m128d_f64[0]);
				*(float*)&l = _mm_unpacklo_pd(v9, v9).m128d_f64[0];
				for (int r_5 = 0; r_5 <= 2; ++r_5)
				{
					v10 = this->exPoint((unsigned int)i)[r_5];
					*v10 = *v10 / *(float*)&l;
				}
				for (int r_6 = 0; r_6 <= 3; ++r_6)
				{
					v11 = this->exPoint((unsigned int)(i + 1))[r_6];
					*v11 = this->exPoint((unsigned int)i)[r_6];
					v12 = this->exPoint((unsigned int)(i + 2))[r_6];
					*v12 = this->exPoint((unsigned int)i)r[r_6];
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

	IIOModel::Point4* IOModel::exPoint(int i)
	{
		return new Point4(&this->extra[4 * i]);
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
		this->free();
		std::fstream v19;
        v19.open(fname, 8LL);
		if (v19.is_open() != 1)
		{
			v3 = 0;
		}
		else
		{
            v19 >>  this->msize;
			if (this->msize <= 51200)
			{
				this->vert = (CGL::GLfloat*)operator new[](12LL * this->msize);
				this->tex = (CGL::GLfloat*)operator new[](8LL * this->msize);
				this->norm = (CGL::GLfloat*)operator new[](12LL * this->msize);
				for (int i = 0; this->msize > i; ++i)
				{
					v4 = &this->norm[3 * i + 2];
					v5 = &this->norm[3 * i + 1];
					v6 = &this->norm[3 * i];
					v7 = &this->tex[2 * i + 1];
					v8 = &this->tex[2 * i];
					v18 = &this->vert[3 * i + 2];
					v17 = &this->vert[3 * i + 1];
					v19 >> &this->vert[3 * i] >> v17 >> v18>>  v8>> v7>> v6>>v5>> v4;
				}
                v19.close();
                this->computeTBN();
				v3 = 1;
			}
			else
			{
				this->msize = 0;
				v3 = 0;
			}
		}
		return v3;
	}

	bool IOModel::loadBin_v0(const std::string& fname)
	{
		this->free();
		std::fstream v7;
		v2 = std::operator|(std::_Ios_Openmode::_S_in, std::_Ios_Openmode::_S_bin);
        v7.open(fname, (unsigned int)v2);
		if (v7.is_open())
		{
			this->free();
            v7.read((char*)&this->msize, 4LL);
			if (this->msize <= 512000)
			{
				this->vert = (CGL::GLfloat*)operator new[](12LL * this->msize);
				this->tex = (CGL::GLfloat*)operator new[](8LL * this->msize);
				this->norm = (CGL::GLfloat*)operator new[](12LL * this->msize);
                v7.read( (char*)this->vert, 12LL * this->msize);
                v7.read(( (char*)this->tex, 8LL * this->msize);
                v7.read(( (char*)this->norm, 12LL * this->msize);
				i = 0;
                v7.read( (char*)&i, 4LL);
				if ((unsigned __int8)std::ios::eof(&v8) != 1)
				{
					memset(&info, 0, sizeof(info));
                    v7.read((char*)&info, i);
					if (info.stencilModelSize)
					{
						sh_data = new IOModel();
						sh_data_1->msize = info.stencilModelSize;
						*((_QWORD*)sh_data + 1) = operator new[](12LL * info.stencilModelSize);
                        v7.read( *((char**)sh_data + 1), 12LL * info.stencilModelSize);
						this->shadow_data = sh_data;
					}
					if (info.extraData)
					{
						this->extra = (CGL::GLfloat*)operator new[](16LL * this->msize);
                        v7.read((char*)this->extra, 16LL * this->msize);
					}
				}
                v7.close();
                this->computeTBN();
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
		return v4;
	}

	IOModel::Normal* IOModel::normal(int i)
	{
		return new Point(&this->norm[3 * i]);
	}

	const CGL::GLfloat* IOModel::normals()
	{
		return this->norm;
	}

	IIOModel::Point* IOModel::point(int i)
	{
		return new Point(&this->vert[3 * i]);
	}

	const CGL::GLfloat* IOModel::points()
	{
		return this->vert;
	}

	bool IOModel::save(const std::string& fname)
	{
		std::fstream v28;
        v28.open( fname, 16LL);
		if (v28.is_open() != 1)
		{
			v3 = 0;
		}
		else
		{
			 v29 << (unsigned int)this->msize << std::endl;
			for (int i = 0; this->msize > i; ++i)
			{
				v27 = this->norm[3 * i + 2];
				v26 = this->norm[3 * i + 1];
				v25 = this->norm[3 * i];
				v24 = this->tex[2 * i + 1];
				v23 = this->tex[2 * i];
				v22 = this->vert[3 * i + 2];
				v21 = this->vert[3 * i + 1];
				v29 << this->vert[3 * i]<< unk_4D36E0 << v21<<unk_4D36E0 <<v22 << unk_4D36E0 << v23
                 << unk_4D36E0 <<  v24 << unk_4D36E0 <<  v25 << unk_4D36E0 << v26 << unk_4D36E0 << v27 << std::endl;
			}
            v28.close();
			v3 = 1;
		}
		return v3;
	}

	bool IOModel::saveBin(const std::string& fname)
	{
		std::fstream v8;
		v2 = std::operator|(std::_Ios_Openmode::_S_out, std::_Ios_Openmode::_S_bin);
        v8.open(fname, (unsigned int)v2);
		if (v8.is_open() != 1)
		{
			v4 = 0;
		}
		else
		{
            v9.write( (const char*)&this->msize, 4LL);
            v9.write( (const char*)this->vert, 12LL * this->msize);
            v9.write( (const char*)this->tex, 8LL * this->msize);
            v9.write( (const char*)this->norm, 12LL * this->msize);
			if (this->shadow_data)
				info.stencilModelSize = (*(__int64(__fastcall**)(void*))(*(_QWORD*)this->shadow_data + 144LL))(this->shadow_data);
			else
				info.stencilModelSize = 0;
			info.extraData = this->extra != 0LL;
			i = 20;
            v9.write((const char*)&i, 4LL);
            v9.write((const char*)&info, 20LL);
			if (info.stencilModelSize)
			{
				v5 = 12LL * (*(int(__fastcall**)(void*))(*(_QWORD*)this->shadow_data + 144LL))(this->shadow_data);
				v6 = (const char*)(*(__int64(__fastcall**)(void*))(*(_QWORD*)this->shadow_data + 64LL))(this->shadow_data);
                v9.write(v6, v5);
			}
			if (this->extra)
                v9.write((const char*)this->extra, 16LL * this->msize);
            v8.close();
			v4 = 1;
		}
		return v4;
	}

	int IOModel::size()
	{
		return this->msize;
	}

	IIOModel::TexCoord* IOModel::texCoord(int i)
	{
		return new TexCoord(&this->tex[2 * i]);
	}

	const CGL::GLfloat* IOModel::textureCoords()
	{
		return this->tex;
	}
}