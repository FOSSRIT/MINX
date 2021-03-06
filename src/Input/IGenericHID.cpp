/*
# MINX

Copyright (c) 2013-2014 Liam Middlebrook, Benjamin Pylko

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

> 1\. The origin of this software must not be misrepresented; you must not
> claim that you wrote the original software. If you use this software
> in a product, an acknowledgment in the product documentation would be
> appreciated but is not required.
>
> 2\. Altered source versions must be plainly marked as such, and must not be
> misrepresented as being the original software.
>
> 3\. This notice may not be removed or altered from any source
> distribution.
>
 */
#include "IGenericHID.hpp"

using namespace MINX::Input;
using namespace MINX;

IGenericHID::IGenericHID(Game* game, unsigned int buttonVectorSize, unsigned int axisVectorSize) : GameComponent(game)
{
	Button b;
	b.UpdateState(0);
	b.UpdateState(0);
	buttons = new std::vector<Button>(buttonVectorSize, b);
	Axis a;
	a.UpdateValue(0);
	a.UpdateValue(0);
	axes = new std::vector<Axis>(axisVectorSize, a);
}

Button IGenericHID::GetButton(unsigned int id)
{
	return (*buttons)[id];
}

Axis IGenericHID::GetAxis(unsigned int id)
{
	return (*axes)[id];
}
