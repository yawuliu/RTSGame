#include "ModelInfo.h"
namespace MyGL {
	ModelInfo::ModelInfo() {
		for (int i = 0; i <= 2; ++i) {
			this->minD[i] = 0.0;
			this->maxD[i] = 0.0;
		}
		this->r = 0.0;
	}

	ModelInfo::ModelInfo(IIOModel& m) {
		this->updateFrom(m);
	}

	ModelInfo::~ModelInfo() {

	}

	IModelInfo* ModelInfo::operator=(IModelInfo const& m) {
		__m128d v2;
		__m128d v3;
		__m128d v4;
		__m128d v5;
		__m128d v6;
		__m128d v7;
		float y;
		float z;
		float X;
		float Y;
		float Z;

		v2.m128d_f64[0] = (*(double(__fastcall**)(const void* const)) (*(_QWORD*)m + 56LL))(m);
		v3 = (__m128d) _mm_cvtpd_ps(_mm_unpacklo_pd(v2, v2));
		Z = *(float*)v3.m128d_f64;
		v3.m128d_f64[0] = (*(double(__fastcall**)(const void* const)) (*(_QWORD*)m + 48LL))(m);
		v4 = (__m128d) _mm_cvtpd_ps(_mm_unpacklo_pd(v3, v3));
		Y = *(float*)v4.m128d_f64;
		v4.m128d_f64[0] = (*(double(__fastcall**)(const void* const)) (*(_QWORD*)m + 40LL))(m);
		v5 = (__m128d) _mm_cvtpd_ps(_mm_unpacklo_pd(v4, v4));
		X = *(float*)v5.m128d_f64;
		v5.m128d_f64[0] = (*(double(__fastcall**)(const void* const)) (*(_QWORD*)m + 32LL))(m);
		v6 = (__m128d) _mm_cvtpd_ps(_mm_unpacklo_pd(v5, v5));
		z = *(float*)v6.m128d_f64;
		v6.m128d_f64[0] = (*(double(__fastcall**)(const void* const)) (*(_QWORD*)m + 24LL))(m);
		v7 = (__m128d) _mm_cvtpd_ps(_mm_unpacklo_pd(v6, v6));
		y = *(float*)v7.m128d_f64;
		v7.m128d_f64[0] = (*(double(__fastcall**)(const void* const)) (*(_QWORD*)m + 16LL))(m);
		this->setBox(_mm_unpacklo_pd(v7, v7).m128d_f64[0], y, z, X, Y, Z);
		return this;
	}

	double ModelInfo::minX() {
		return this->minD[0];
	}

	double ModelInfo::minY() {
		return this->minD[1];
	}

	double ModelInfo::minZ() {
		return this->minD[2];
	}

	double ModelInfo::maxX() {
		return this->maxD[0];
	}

	double ModelInfo::maxY() {
		return this->maxD[1];
	}

	double ModelInfo::maxZ() {
		return this->maxD[2];
	}

	double ModelInfo::radius() {
		return this->r;
	}

	void ModelInfo::updateFrom(IIOModel const& m) {
		__int64 v2;
		const double* v3;
		double v4;
		int v5;
		double p;
		double dVec[3];
		int i_2;
		int r;
		int i_1;
		int i_0;
		int i;

		for (i = 0; i <= 2; ++i) {
			this->minD[i] = 0.0;
			this->maxD[i] = 0.0;
		}
		this->r = 0.0;
		if ((*((unsigned int(__fastcall**)(IIOModel* const)) m->_vptr_IIOModel + 18))(m)) {
			for (i_0 = 0; i_0 <= 2; ++i_0) {
				this->minD[i_0] = *(float*)(4LL * i_0
					+ (*((__int64(__fastcall**)(
						IIOModel* const)) m->_vptr_IIOModel + 8))(m));
				this->maxD[i_0] = *(float*)(4LL * i_0
					+ (*((__int64(__fastcall**)(
						IIOModel* const)) m->_vptr_IIOModel + 8))(m));
			}
			for (i_1 = 0;; i_1 += 3) {
				v5 = (*((__int64(__fastcall**)(IIOModel* const)) m->_vptr_IIOModel + 18))(m);
				if (3 * v5 <= i_1)
					break;
				for (r = 0; r <= 2; ++r) {
					v2 = (*((__int64(__fastcall**)(IIOModel* const)) m->_vptr_IIOModel + 8))(m);
					p = *(float*)(4LL * (i_1 + r) + v2);
					v3 = std::min<double>(&this->minD[r], &p);
					this->minD[r] = *v3;
					v4 = *std::max<double>(&this->maxD[r], &p);
					this->maxD[r] = v4;
				}
			}
			for (i_2 = 0; i_2 <= 2; ++i_2)
				dVec[i_2] = this->maxD[i_2] - this->minD[i_2];
			this->r = sqrt(dVec[2] * dVec[2] + dVec[0] * dVec[0] + dVec[1] * dVec[1]) * 0.5;
		}
	}

	void ModelInfo::setBox(float x, float y, float z, float X, float Y, float Z) {
		double dVec[3];
		int i;

		this->minD[0] = x;
		this->minD[1] = y;
		this->minD[2] = z;
		this->maxD[0] = X;
		this->maxD[1] = Y;
		this->maxD[2] = Z;
		for (i = 0; i <= 2; ++i)
			dVec[i] = this->maxD[i] - this->minD[i];
		this->r = sqrt(dVec[2] * dVec[2] + dVec[0] * dVec[0] + dVec[1] * dVec[1]) * 0.5;
	}
}
