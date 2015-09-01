// Copyright Liam hill 2014
#pragma once
#include "stdafx.h"

#include "globals.h"
#include <SDL/SDL_ttf.h>
class maze
{
public:
	bool used;
    bool red;
	bool yelow;
	maze(void);
	~maze(void);
	void print(const int x, const int y, const int size, const int linethicness);
};

