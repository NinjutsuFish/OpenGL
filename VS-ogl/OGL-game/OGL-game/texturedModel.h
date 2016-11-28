#pragma once
#include "RawModel.h"
#include "modelTexture.h"
#include "stdafx.h"
#include <string>
class texturedModel
{
public:
	texturedModel() { };
	texturedModel(RawModel mymodel, modelTexture mytexture) { model = mymodel; texture = mytexture; };
	~texturedModel() {};
	RawModel getModel() { return model; }
	modelTexture getTexture() { return texture; }

private:
	RawModel model;
	modelTexture texture;
};

