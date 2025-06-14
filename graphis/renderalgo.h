#pragma once

#include "MyGL/Adapter.h"
#include "MyGL/ForwardRenderAlgo.h"
#include "MyGL/MainPass.h"

class Adapter;

class RenderAlgo : public MyGL::ForwardRenderAlgo {
public:
	RenderAlgo(MyGL::IScene* s, const ::Adapter* adaForwardRenderpter);

private:
	MyGL::MainPass* allockMainPass(const MyGL::Adapter* adapter);

	MyGL::IModel* quad;
};


