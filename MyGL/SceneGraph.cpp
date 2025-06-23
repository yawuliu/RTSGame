#include "SceneGraph.h"
namespace MyGL {
	SceneGraph::SceneGraph(IScene& s) :scene(s) {}

	void SceneGraph::addObjectEvent(IGraphicsObject& a2)
	{
		;
	}

	void SceneGraph::beginFrame(IRenderPass& a2)
	{
		(*((void(__fastcall**)(SceneGraph* const))this->_vptr_ISceneGraph + 4))(this);
	}

	void SceneGraph::beginFrame()
	{
		this->updateCull();
		(*((void(__fastcall**)(SceneGraph* const))this->_vptr_ISceneGraph + 8))(this);
	}

	void SceneGraph::delObjectEvent(IGraphicsObject* const a2)
	{
		;
	}

	void SceneGraph::endFrame()
	{
		;
	}

	void SceneGraph::getGl()
	{
		__int64 v1;
		__int64 v2;
		double modl[16];
		double proj[16];

		v1 = (*((__int64(__fastcall**)(IScene* const))this->scene->_vptr_IScene + 3))(this->scene);
		(*(void(__fastcall**)(__int64, double*))(*(_QWORD*)v1 + 352LL))(v1, proj);
		v2 = (*((__int64(__fastcall**)(IScene* const))this->scene->_vptr_IScene + 3))(this->scene);
		(*(void(__fastcall**)(__int64, double*))(*(_QWORD*)v2 + 344LL))(v2, modl);
		this->model_proj[0] = proj[12] * modl[3] + modl[0] * proj[0] + proj[4] * modl[1] + proj[8] * modl[2];
		this->model_proj[1] = proj[13] * modl[3] + modl[0] * proj[1] + proj[5] * modl[1] + proj[9] * modl[2];
		this->model_proj[2] = proj[14] * modl[3] + modl[0] * proj[2] + proj[6] * modl[1] + proj[10] * modl[2];
		this->model_proj[3] = proj[15] * modl[3] + modl[0] * proj[3] + proj[7] * modl[1] + proj[11] * modl[2];
		this->model_proj[4] = proj[12] * modl[7] + modl[4] * proj[0] + proj[4] * modl[5] + proj[8] * modl[6];
		this->model_proj[5] = proj[13] * modl[7] + modl[4] * proj[1] + proj[5] * modl[5] + proj[9] * modl[6];
		this->model_proj[6] = proj[14] * modl[7] + modl[4] * proj[2] + proj[6] * modl[5] + proj[10] * modl[6];
		this->model_proj[7] = proj[15] * modl[7] + modl[4] * proj[3] + proj[7] * modl[5] + proj[11] * modl[6];
		this->model_proj[8] = proj[12] * modl[11] + modl[8] * proj[0] + proj[4] * modl[9] + proj[8] * modl[10];
		this->model_proj[9] = proj[13] * modl[11] + modl[8] * proj[1] + proj[5] * modl[9] + proj[9] * modl[10];
		this->model_proj[10] = proj[14] * modl[11] + modl[8] * proj[2] + proj[6] * modl[9] + proj[10] * modl[10];
		this->model_proj[11] = proj[15] * modl[11] + modl[8] * proj[3] + proj[7] * modl[9] + proj[11] * modl[10];
		this->model_proj[12] = proj[12] * modl[15] + modl[12] * proj[0] + proj[4] * modl[13] + proj[8] * modl[14];
		this->model_proj[13] = proj[13] * modl[15] + modl[12] * proj[1] + proj[5] * modl[13] + proj[9] * modl[14];
		this->model_proj[14] = proj[14] * modl[15] + modl[12] * proj[2] + proj[6] * modl[13] + proj[10] * modl[14];
		this->model_proj[15] = proj[15] * modl[15] + modl[12] * proj[3] + proj[7] * modl[13] + proj[11] * modl[14];
	}

	bool SceneGraph::isObjectVisible(const IGraphicsObject& obj)
	{
		__m128d v2;
		__m128d v3;
		__m128d v4;
		__int64 v5;
		double v7;
		float z;
		float y;
		float x;
		int i;

		v2.m128d_f64[0] = (*((double(__fastcall**)(const IGraphicsObject* const))obj->_vptr_IGraphicsObject + 13))(obj);
		v3 = (__m128d)_mm_cvtpd_ps(_mm_unpacklo_pd(v2, v2));
		x = *(float*)v3.m128d_f64;
		v3.m128d_f64[0] = (*((double(__fastcall**)(const IGraphicsObject* const))obj->_vptr_IGraphicsObject + 14))(obj);
		v4 = (__m128d)_mm_cvtpd_ps(_mm_unpacklo_pd(v3, v3));
		y = *(float*)v4.m128d_f64;
		v4.m128d_f64[0] = (*((double(__fastcall**)(const IGraphicsObject* const))obj->_vptr_IGraphicsObject + 15))(obj);
		z = _mm_unpacklo_pd(v4, v4).m128d_f64[0];
		for (i = 0; i <= 5; ++i)
		{
			v7 = SceneGraph::po(this, x, y, z, this->cullM[i][0], this->cullM[i][1], this->cullM[i][2], this->cullM[i][3]);
			v5 = (*((__int64(__fastcall**)(const IGraphicsObject* const))obj->_vptr_IGraphicsObject + 20))(obj);
			if (-(*(double(__fastcall**)(__int64))(*(_QWORD*)v5 + 64LL))(v5) > v7)
				return 0;
		}
		return 1;
	}

	void SceneGraph::normalization(double* const X, double* const Y, double* const Z, double* const D)
	{
		double v5;

		v5 = sqrt(*Z * *Z + *X * *X + *Y * *Y);
		*X = *X * (1.0 / v5);
		*Y = *Y * (1.0 / v5);
		*Z = *Z * (1.0 / v5);
		*D = *D * (1.0 / v5);
	}

	double SceneGraph::po(double x, double y, double z, double X, double Y, double Z, double D)
	{
		return Z * z + X * x + Y * y + D;
	}

	void SceneGraph::updateCull()
	{
		int i;

		this->getGl();
		this->cullM[0][0] = this->model_proj[1] + this->model_proj[3];
		this->cullM[0][1] = this->model_proj[5] + this->model_proj[7];
		this->cullM[0][2] = this->model_proj[9] + this->model_proj[11];
		this->cullM[0][3] = this->model_proj[13] + this->model_proj[15];
		this->cullM[1][0] = this->model_proj[0] + this->model_proj[3];
		this->cullM[1][1] = this->model_proj[4] + this->model_proj[7];
		this->cullM[1][2] = this->model_proj[8] + this->model_proj[11];
		this->cullM[1][3] = this->model_proj[12] + this->model_proj[15];
		this->cullM[2][0] = this->model_proj[3] - this->model_proj[0];
		this->cullM[2][1] = this->model_proj[7] - this->model_proj[4];
		this->cullM[2][2] = this->model_proj[11] - this->model_proj[8];
		this->cullM[2][3] = this->model_proj[15] - this->model_proj[12];
		this->cullM[3][0] = this->model_proj[3] - this->model_proj[1];
		this->cullM[3][1] = this->model_proj[7] - this->model_proj[5];
		this->cullM[3][2] = this->model_proj[11] - this->model_proj[9];
		this->cullM[3][3] = this->model_proj[15] - this->model_proj[13];
		this->cullM[4][0] = this->model_proj[3] - this->model_proj[2];
		this->cullM[4][1] = this->model_proj[7] - this->model_proj[6];
		this->cullM[4][2] = this->model_proj[11] - this->model_proj[10];
		this->cullM[4][3] = this->model_proj[15] - this->model_proj[14];
		this->cullM[5][0] = this->model_proj[2] + this->model_proj[3];
		this->cullM[5][1] = this->model_proj[6] + this->model_proj[7];
		this->cullM[5][2] = this->model_proj[10] + this->model_proj[11];
		this->cullM[5][3] = this->model_proj[14] + this->model_proj[15];
		for (i = 0; i <= 5; ++i)
			this->normalization(this->cullM[i], &this->cullM[i][1], &this->cullM[i][2], &this->cullM[i][3]);
	}

	void SceneGraph::updateVisible()
	{
		__int64 v1;
		unsigned __int8(__fastcall * v2)(SceneGraph* const, __int64);
		__int64 v3;
		__int64 v4;
		std::vector<IGraphicsObject*>::size_type nsize_1;
		std::vector<IGraphicsObject*>::reference v6;
		__int64 v7;
		std::vector<IGraphicsObject*>::value_type __x;
		size_t objSize;
		size_t i;
		size_t nsize;

		nsize = 0LL;
		v1 = (*((__int64(__fastcall**)(IScene* const))this->scene->_vptr_IScene + 9))(this->scene);
		objSize = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v1 + 64LL))(v1);
		for (i = 0LL; i < objSize; ++i)
		{
			v2 = (unsigned __int8(__fastcall*)(SceneGraph* const, __int64)) * ((_QWORD*)this->_vptr_ISceneGraph + 7);
			v3 = (*((__int64(__fastcall**)(IScene* const))this->scene->_vptr_IScene + 9))(this->scene);
			v4 = (*(__int64(__fastcall**)(__int64, size_t))(*(_QWORD*)v3 + 72LL))(v3, i);
			if (v2(this, v4))
			{
				nsize_1 = std::vector<IGraphicsObject*>::size(&this->visObj);
				if (nsize_1 >= nsize)
				{
					__x = 0LL;
					std::vector<IGraphicsObject*>::push_back(&this->visObj, &__x);
				}
				v6 = std::vector<IGraphicsObject*>::operator[](&this->visObj, nsize);
				v7 = (*((__int64(__fastcall**)(IScene* const))this->scene->_vptr_IScene + 9))(this->scene);
				*v6 = (IGraphicsObject*)(*(__int64(__fastcall**)(__int64, size_t))(*(_QWORD*)v7 + 72LL))(v7, i);
				++nsize;
			}
		}
		this->visObj.resize(nsize, 0LL);
	}

	IGraphicsObject* SceneGraph::visible(int num)
	{
		return  this->visObj[num];
	}

	int SceneGraph::visiblesCount()
	{
		return this->visObj.size();
	}
}