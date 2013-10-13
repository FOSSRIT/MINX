/*
MINX_Monsters - A C++ Game Based off the
Copyright (C) 2013  MINX Team

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#include "Monster.h"
using namespace MINX_monsters;
Monster::Monster(Vector2* position, Graphics::Texture2D* texture, Graphics::Color* color)
{
	this->position = position;
	this->color = color;
	this->velocity = new Vector2(0,0);
	this->texture = texture;
}
void Monster::Update(GameTime* gameTime, Input::Keyboard* keyboard)
{
	if(keyboard->getKey(MINX_KEY_A).state)
	{
		position->X--;
		if(position->X < 0)
		{
			position->X = 0;
		}
	}
	if(keyboard->getKey(MINX_KEY_D).state)
	{
		position->X++;
		if(position->X >= Graphics::GameWindow::width - (int)texture->width)
		{
			position->X = Graphics::GameWindow::width - (int)texture->width;
		}
	}
	if(keyboard->getKey(MINX_KEY_W).state)
	{
		position->Y--;
		if(position->Y < 0)
		{
			position->Y = 0;
		}
	}
	if(keyboard->getKey(MINX_KEY_S).state)
	{
		position->Y++;
		if(position->Y >= Graphics::GameWindow::height - (int)texture->height)
		{
			position->Y = Graphics::GameWindow::height - (int)texture->height;
		}
	}
}
void Monster::Draw()
{
	texture->Draw(position->X, position->Y, 1.0f, 1.0f, 0.0f, color);
}